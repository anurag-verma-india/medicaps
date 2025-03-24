#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <algorithm>

// A simple LALR(1) parser implementation
class LALRParser {
private:
    // Grammar symbols
    enum Symbol {
        // Terminals
        INTEGER, PLUS, TIMES, LPAREN, RPAREN, END,
        // Non-terminals
        EXPR, TERM, FACTOR
    };

    // Action types
    enum ActionType { SHIFT, REDUCE, ACCEPT, ERROR };

    // LR item types
    struct Action {
        ActionType type;
        int value; // State for SHIFT, production for REDUCE
        
        Action() : type(ERROR), value(0) {}
        Action(ActionType t, int v) : type(t), value(v) {}
    };

    // Grammar production
    struct Production {
        Symbol left;
        std::vector<Symbol> right;
        
        Production(Symbol l, std::vector<Symbol> r) : left(l), right(r) {}
    };

    // Token structure
    struct Token {
        Symbol type;
        std::string lexeme;
        
        Token(Symbol t, const std::string& l) : type(t), lexeme(l) {}
    };

    // Parser tables
    std::vector<std::map<Symbol, Action>> actionTable;
    std::vector<std::map<Symbol, int>> gotoTable;
    std::vector<Production> productions;

    // Initialize the grammar productions
    void initGrammar() {
        // E -> E + T
        productions.push_back(Production(EXPR, {EXPR, PLUS, TERM}));
        // E -> T
        productions.push_back(Production(EXPR, {TERM}));
        // T -> T * F
        productions.push_back(Production(TERM, {TERM, TIMES, FACTOR}));
        // T -> F
        productions.push_back(Production(TERM, {FACTOR}));
        // F -> (E)
        productions.push_back(Production(FACTOR, {LPAREN, EXPR, RPAREN}));
        // F -> int
        productions.push_back(Production(FACTOR, {INTEGER}));
    }

    // Initialize the parsing tables (LALR(1) tables would normally be generated)
    void initTables() {
        // This is a simplified version of what would normally be generated tables
        // We'll create tables for the expression grammar E -> E+T | T, T -> T*F | F, F -> (E) | int
        
        // Create states
        actionTable.resize(12);
        gotoTable.resize(12);

        // State 0
        actionTable[0][INTEGER] = Action(SHIFT, 5);
        actionTable[0][LPAREN] = Action(SHIFT, 4);
        gotoTable[0][EXPR] = 1;
        gotoTable[0][TERM] = 2;
        gotoTable[0][FACTOR] = 3;

        // State 1
        actionTable[1][PLUS] = Action(SHIFT, 6);
        actionTable[1][END] = Action(ACCEPT, 0);

        // State 2
        actionTable[2][TIMES] = Action(SHIFT, 7);
        actionTable[2][PLUS] = Action(REDUCE, 1);
        actionTable[2][RPAREN] = Action(REDUCE, 1);
        actionTable[2][END] = Action(REDUCE, 1);

        // State 3
        actionTable[3][TIMES] = Action(REDUCE, 3);
        actionTable[3][PLUS] = Action(REDUCE, 3);
        actionTable[3][RPAREN] = Action(REDUCE, 3);
        actionTable[3][END] = Action(REDUCE, 3);

        // State 4
        actionTable[4][INTEGER] = Action(SHIFT, 5);
        actionTable[4][LPAREN] = Action(SHIFT, 4);
        gotoTable[4][EXPR] = 8;
        gotoTable[4][TERM] = 2;
        gotoTable[4][FACTOR] = 3;

        // State 5
        actionTable[5][TIMES] = Action(REDUCE, 5);
        actionTable[5][PLUS] = Action(REDUCE, 5);
        actionTable[5][RPAREN] = Action(REDUCE, 5);
        actionTable[5][END] = Action(REDUCE, 5);

        // State 6
        actionTable[6][INTEGER] = Action(SHIFT, 5);
        actionTable[6][LPAREN] = Action(SHIFT, 4);
        gotoTable[6][TERM] = 9;
        gotoTable[6][FACTOR] = 3;

        // State 7
        actionTable[7][INTEGER] = Action(SHIFT, 5);
        actionTable[7][LPAREN] = Action(SHIFT, 4);
        gotoTable[7][FACTOR] = 10;

        // State 8
        actionTable[8][PLUS] = Action(SHIFT, 6);
        actionTable[8][RPAREN] = Action(SHIFT, 11);

        // State 9
        actionTable[9][TIMES] = Action(SHIFT, 7);
        actionTable[9][PLUS] = Action(REDUCE, 0);
        actionTable[9][RPAREN] = Action(REDUCE, 0);
        actionTable[9][END] = Action(REDUCE, 0);

        // State 10
        actionTable[10][TIMES] = Action(REDUCE, 2);
        actionTable[10][PLUS] = Action(REDUCE, 2);
        actionTable[10][RPAREN] = Action(REDUCE, 2);
        actionTable[10][END] = Action(REDUCE, 2);

        // State 11
        actionTable[11][TIMES] = Action(REDUCE, 4);
        actionTable[11][PLUS] = Action(REDUCE, 4);
        actionTable[11][RPAREN] = Action(REDUCE, 4);
        actionTable[11][END] = Action(REDUCE, 4);
    }

    // Helper function to get symbol name for debugging
    std::string getSymbolName(Symbol s) {
        switch(s) {
            case INTEGER: return "INTEGER";
            case PLUS: return "+";
            case TIMES: return "*";
            case LPAREN: return "(";
            case RPAREN: return ")";
            case END: return "$";
            case EXPR: return "EXPR";
            case TERM: return "TERM";
            case FACTOR: return "FACTOR";
            default: return "UNKNOWN";
        }
    }

public:
    LALRParser() {
        initGrammar();
        initTables();
    }

    // Simple lexer for testing
    std::vector<Token> tokenize(const std::string& input) {
        std::vector<Token> tokens;
        for (size_t i = 0; i < input.length(); ++i) {
            char c = input[i];
            if (isdigit(c)) {
                std::string num;
                while (i < input.length() && isdigit(input[i])) {
                    num += input[i++];
                }
                --i;  // Adjust for the loop increment
                tokens.push_back(Token(INTEGER, num));
            } else if (c == '+') {
                tokens.push_back(Token(PLUS, "+"));
            } else if (c == '*') {
                tokens.push_back(Token(TIMES, "*"));
            } else if (c == '(') {
                tokens.push_back(Token(LPAREN, "("));
            } else if (c == ')') {
                tokens.push_back(Token(RPAREN, ")"));
            } else if (!isspace(c)) {
                std::cerr << "Unexpected character: " << c << std::endl;
                return {};
            }
        }
        tokens.push_back(Token(END, "$"));
        return tokens;
    }

    // Parse input
    bool parse(const std::string& input) {
        std::vector<Token> tokens = tokenize(input);
        if (tokens.empty()) return false;

        std::stack<int> stateStack;
        std::stack<Symbol> symbolStack;
        
        stateStack.push(0);  // Start state
        
        size_t currentToken = 0;
        
        while (true) {
            int currentState = stateStack.top();
            Symbol currentSymbol = tokens[currentToken].type;
            
            // Debugging output
            std::cout << "Current state: " << currentState 
                      << ", Current symbol: " << getSymbolName(currentSymbol) 
                      << ", Lexeme: " << tokens[currentToken].lexeme << std::endl;
            
            // Look up action
            if (actionTable[currentState].find(currentSymbol) == actionTable[currentState].end()) {
                std::cerr << "Syntax error: No valid action for state " << currentState
                          << " and symbol " << getSymbolName(currentSymbol) << std::endl;
                return false;
            }
            
            Action action = actionTable[currentState][currentSymbol];
            
            if (action.type == SHIFT) {
                stateStack.push(action.value);
                symbolStack.push(currentSymbol);
                currentToken++;
                std::cout << "Action: SHIFT to state " << action.value << std::endl;
            } else if (action.type == REDUCE) {
                Production& prod = productions[action.value];
                
                // Pop states and symbols according to production
                for (size_t i = 0; i < prod.right.size(); ++i) {
                    stateStack.pop();
                    symbolStack.pop();
                }
                
                // Get new state from GOTO table
                int newState = gotoTable[stateStack.top()][prod.left];
                stateStack.push(newState);
                symbolStack.push(prod.left);
                
                std::cout << "Action: REDUCE by " << getSymbolName(prod.left) << " -> ";
                for (Symbol s : prod.right) {
                    std::cout << getSymbolName(s) << " ";
                }
                std::cout << std::endl;
            } else if (action.type == ACCEPT) {
                std::cout << "Action: ACCEPT" << std::endl;
                return true;
            } else {
                std::cerr << "Error at position " << currentToken << std::endl;
                return false;
            }
        }
        
        return false;
    }
};

int main() {
    LALRParser parser;
    std::string input;
    
    std::cout << "Enter an expression (e.g., 2+3*4): ";
    std::getline(std::cin, input);
    
    if (parser.parse(input)) {
        std::cout << "Successfully parsed!" << std::endl;
    } else {
        std::cout << "Parse failed!" << std::endl;
    }
    
    return 0;
}