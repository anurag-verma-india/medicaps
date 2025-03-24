#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

// Modified Item struct with explicit comparison
struct Item {
    string production;
    size_t dotPos;  // Changed to size_t to match string::length()
    
    // Explicit equality operator
    bool operator==(const Item& other) const {
        return production == other.production && dotPos == other.dotPos;
    }
    
    // Less than operator for set ordering
    bool operator<(const Item& other) const {
        return production < other.production || 
               (production == other.production && dotPos < other.dotPos);
    }
};

class LALRParser {
private:
    map<string, vector<string>> grammar;
    set<string> terminals;
    set<string> nonTerminals;
    
    // Compute first sets for look-ahead
    map<string, set<string>> computeFirstSets() {
        map<string, set<string>> firstSets;
        
        // Initialize terminals
        for (const string& terminal : terminals) {
            firstSets[terminal] = {terminal};
        }
        
        bool changed;
        do {
            changed = false;
            for (const auto& [nonterminal, productions] : grammar) {
                for (const string& prod : productions) {
                    set<string> prodFirst;
                    bool allNullable = true;
                    
                    for (char symbol : prod) {
                        string symStr(1, symbol);
                        
                        // Merge first set
                        for (const string& first : firstSets[symStr]) {
                            if (first != "ε") {
                                if (prodFirst.insert(first).second) {
                                    changed = true;
                                }
                            }
                        }
                        
                        // Break if not nullable
                        if (firstSets[symStr].find("ε") == firstSets[symStr].end()) {
                            allNullable = false;
                            break;
                        }
                    }
                    
                    // Add epsilon if all symbols are nullable
                    if (allNullable) {
                        if (prodFirst.insert("ε").second) {
                            changed = true;
                        }
                    }
                    
                    // Merge with existing first set
                    for (const string& first : prodFirst) {
                        if (firstSets[nonterminal].insert(first).second) {
                            changed = true;
                        }
                    }
                }
            }
        } while (changed);
        
        return firstSets;
    }
    
    // Generate canonical collection of LR(0) items
    vector<set<Item>> canonicalCollection() {
        vector<set<Item>> states;
        
        // Initial state: augmented grammar start
        set<Item> initialState = {{"S'->S", 0}};
        states.push_back(closure(initialState));
        
        bool changed;
        do {
            changed = false;
            size_t currentSize = states.size();
            
            for (size_t i = 0; i < currentSize; ++i) {
                // Compute transitions for each symbol
                for (const string& symbol : getAllSymbols()) {
                    set<Item> gotoState = gotoFunc(states[i], symbol);
                    
                    if (!gotoState.empty()) {
                        // Check if state already exists with a custom comparison
                        auto it = find_if(states.begin(), states.end(), 
                            [&gotoState](const set<Item>& existingState) {
                                if (existingState.size() != gotoState.size()) 
                                    return false;
                                return equal(gotoState.begin(), gotoState.end(), 
                                             existingState.begin());
                            });
                        
                        if (it == states.end()) {
                            states.push_back(gotoState);
                            changed = true;
                        }
                    }
                }
            }
        } while (changed);
        
        return states;
    }
    
    // Compute closure of LR(0) items
    set<Item> closure(set<Item> items) {
        bool changed;
        do {
            changed = false;
            set<Item> newItems = items;
            
            for (const Item& item : items) {
                // Use size_t for length comparison
                if (item.dotPos < item.production.length()) {
                    char nextSymbol = item.production[item.dotPos];
                    string nonterminal(1, nextSymbol);
                    
                    if (nonTerminals.count(nonterminal)) {
                        for (const string& prod : grammar[nonterminal]) {
                            Item newItem = {nonterminal + "->" + prod, 0};
                            if (newItems.insert(newItem).second) {
                                changed = true;
                            }
                        }
                    }
                }
            }
            
            items = newItems;
        } while (changed);
        
        return items;
    }
    
    // Goto function for state transitions
    set<Item> gotoFunc(const set<Item>& items, const string& symbol) {
        set<Item> gotoItems;
        
        for (const Item& item : items) {
            // Use size_t for length comparison
            if (item.dotPos < item.production.length() && 
                item.production[item.dotPos] == symbol[0]) {
                Item newItem = item;
                newItem.dotPos++;
                gotoItems.insert(newItem);
            }
        }
        
        return closure(gotoItems);
    }
    
    // Get all unique symbols in grammar
    set<string> getAllSymbols() {
        set<string> symbols;
        symbols.insert(terminals.begin(), terminals.end());
        symbols.insert(nonTerminals.begin(), nonTerminals.end());
        return symbols;
    }

public:
    LALRParser(const map<string, vector<string>>& g) : grammar(g) {
        // Separate terminals and non-terminals
        for (const auto& [nonterminal, _] : grammar) {
            nonTerminals.insert(nonterminal);
        }
        
        // Add augmented start symbol
        grammar["S'"] = {"S"};
        
        // Find terminals
        for (const auto& [_, productions] : grammar) {
            for (const string& prod : productions) {
                for (char symbol : prod) {
                    string symStr(1, symbol);
                    if (!nonTerminals.count(symStr)) {
                        terminals.insert(symStr);
                    }
                }
            }
        }
    }
    
    // Generate parsing table
    void generateParsingTable() {
        // Compute canonical collection of LR(0) items
        vector<set<Item>> states = canonicalCollection();
        
        // Compute first sets for look-ahead
        map<string, set<string>> firstSets = computeFirstSets();
        
        cout << "Parsing Table:\n";
        cout << "State\tAction\tGoto\n";
        
        // Print states and their transitions
        for (size_t i = 0; i < states.size(); ++i) {
            cout << "State " << i << ":\n";
            
            // Print items in this state
            for (const Item& item : states[i]) {
                cout << "\t" << item.production << " (dot at " << item.dotPos << ")\n";
            }
            
            // Compute transitions for each symbol
            for (const string& symbol : getAllSymbols()) {
                set<Item> nextState = gotoFunc(states[i], symbol);
                
                if (!nextState.empty()) {
                    // Find the state index for this transition
                    auto it = find_if(states.begin(), states.end(), 
                        [&nextState](const set<Item>& existingState) {
                            if (existingState.size() != nextState.size()) 
                                return false;
                            return equal(nextState.begin(), nextState.end(), 
                                         existingState.begin());
                        });
                    
                    if (it != states.end()) {
                        size_t nextStateIndex = distance(states.begin(), it);
                        
                        // Distinguish between terminals and non-terminals
                        if (terminals.count(symbol)) {
                            cout << "\tAction[" << i << "," << symbol << "] = shift " << nextStateIndex << "\n";
                        } else {
                            cout << "\tGoto[" << i << "," << symbol << "] = " << nextStateIndex << "\n";
                        }
                    }
                }
            }
            
            cout << "\n";
        }
    }
};

int main() {
    // Example grammar
    map<string, vector<string>> grammar = {
        {"S", {"AA"}},
        {"A", {"aA", "b"}}
    };
    
    LALRParser parser(grammar);
    parser.generateParsingTable();
    
    return 0;
}