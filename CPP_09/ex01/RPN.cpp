#include "RPN.hpp"

bool isOp(char a){
    return(a == '*' || a == '/' || a == '+' || a== '-');
}

long makeOp(int first, int second, char op){
    long temp = 0;
    //std::cout  << "first: " << first << std::endl;
    //std::cout << "second: " << second << std::endl;
    switch(op){
        case '-':
            temp = first - second;
            break;
        case '+':
            temp = first + second;
            break;
        case '*':
            temp = first * second;
            break;
        case '/':
            temp = first / second;
            break;
        default:
            break;
    }
    //std::cout << "temp: " << temp << std::endl; 
    return temp;
}

std::string  intToString(int num){

    std::stringstream ss;
    ss << num;
    std::string str = ss.str();
    return str;
}


revPol::revPol(){
    _line = "Invalid";
}

revPol::revPol(const std::string input): _line(input){
    
}

revPol::revPol(const revPol& other){
    *this = other;
}

revPol& revPol::operator=(const revPol& other){
    if (this != &other) {
        _stack = other._stack;
        _line = other._line;
    }
    return *this;
}
revPol::~revPol(){
}

void revPol::calculate(void){

    if(_line.empty())
        throw std::runtime_error("Empty line for input");

    long check;
    std::stack<int>tmpstack;
    for(size_t i = 0; _line[i]; i++){
        while(isspace(_line[i]))
            i++;
        if(isnumber(_line[i])){
            _stack.push(_line[i] - '0');
        }
        else if(isOp(_line[i])){
            if(_stack.size() < 2){
                throw std::runtime_error("Stack size is too small at moment of operation");
            }
            while(_stack.size() != 1){
                tmpstack.push(_stack.top());
                _stack.pop();
            }
            if(!tmpstack.top() && _line[i] == '/')
                 throw std::runtime_error("Cannot divide by 0");
            check = makeOp(_stack.top(), tmpstack.top(), _line[i]);
            if(check > std::numeric_limits<int>::max())
                throw std::runtime_error("Result from operation is too large");
            if(check < std::numeric_limits<int>::min())
                throw std::runtime_error("Result from operation is too small");
            _stack.pop();
            tmpstack.pop();
            _stack.push(static_cast<int>(check));
            while(tmpstack.size()){
                _stack.push(tmpstack.top());
                tmpstack.pop();
            }
        }
        else if(_line[i]){
            throw std::runtime_error("Invalid character");
        }
        else
            break;
    }
    if(_stack.size() > 1)
        throw std::runtime_error("Missing operators");
    std::string res = intToString(_stack.top());
    std::cout << res << std::endl;
}
