#include <iostream>
#include <stack>
#include <vector>

// Structure to represent an intermediate code instruction
struct Instruction {
    std::string op;
    std::string arg1;
    std::string arg2;
    std::string result;
};

class ExpressionCompiler {
private:
    std::vector<Instruction> instructions;
    int tempCount = 0;
    
    // Generate a new temporary variable name
    std::string newTemp() {
        return "t" + std::to_string(tempCount++);
    }

public:
    // Generate intermediate code for an expression
    std::vector<Instruction> generateCode(const std::string& expr) {
        instructions.clear();
        tempCount = 0;
        
        std::stack<char> operators;
        std::stack<std::string> operands;
        
        for (size_t i = 0; i < expr.length(); i++) {
            // Skip spaces
            if (expr[i] == ' ')
                continue;
                
            // Handle parentheses
            if (expr[i] == '(') {
                operators.push(expr[i]);
            }
            else if (expr[i] == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    generateInstruction(operators, operands);
                }
                // Pop the '('
                if (!operators.empty())
                    operators.pop();
            }
            // Handle operands (numbers or variables)
            else if (isalnum(expr[i])) {
                std::string operand;
                // Extract the complete number or variable
                while (i < expr.length() && (isalnum(expr[i]) || expr[i] == '_')) {
                    operand += expr[i++];
                }
                i--; // Adjust for the loop increment
                operands.push(operand);
            }
            // Handle operators
            else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || 
                     expr[i] == '/' || expr[i] == '%') {
                while (!operators.empty() && precedence(operators.top()) >= precedence(expr[i])) {
                    generateInstruction(operators, operands);
                }
                operators.push(expr[i]);
            }
        }
        
        // Process remaining operators
        while (!operators.empty()) {
            generateInstruction(operators, operands);
        }
        
        return instructions;
    }
    
    // Helper to determine operator precedence
    int precedence(char op) {
        if (op == '(')
            return 0;
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/' || op == '%')
            return 2;
        return 0;
    }
    
    // Generate an instruction and update operands stack
    void generateInstruction(std::stack<char>& operators, std::stack<std::string>& operands) {
        if (operators.empty() || operands.size() < 2)
            return;
            
        char op = operators.top();
        operators.pop();
        
        std::string arg2 = operands.top();
        operands.pop();
        std::string arg1 = operands.top();
        operands.pop();
        
        std::string result = newTemp();
        std::string opStr;
        
        switch (op) {
            case '+': opStr = "ADD"; break;
            case '-': opStr = "SUB"; break;
            case '*': opStr = "MUL"; break;
            case '/': opStr = "DIV"; break;
            case '%': opStr = "MOD"; break;
            default: return;
        }
        
        instructions.push_back({opStr, arg1, arg2, result});
        operands.push(result);
    }
    
    // Print the generated instructions
    void printCode() const {
        for (const auto& instr : instructions) {
            std::cout << instr.result << " = " << instr.arg1 << " " 
                      << instr.op << " " << instr.arg2 << std::endl;
        }
    }
};

int main() {
    ExpressionCompiler compiler;
    std::string expression;
    
    std::cout << "Enter an arithmetic expression: ";
    std::getline(std::cin, expression);
    
    compiler.generateCode(expression);
    std::cout << "Generated intermediate code:" << std::endl;
    compiler.printCode();
    
    return 0;
}