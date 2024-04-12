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
    
    }
    return *this;
}
revPol::~revPol(){
}

void revPol::calculate(void){

    if(_line.empty())
        throw std::runtime_error("Empty line for input");

    size_t tmp = 0;
    long check;

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
            tmp = _stack.top();
            _stack.pop();
            if(!tmp && _line[i] == '/')
                throw std::runtime_error("Cannot divide by 0");
            check = makeOp(tmp, _stack.top(), _line[i]);
            if(check > std::numeric_limits<int>::max())
                throw std::runtime_error("Result from operation is too large");
            if(check < std::numeric_limits<int>::min())
                throw std::runtime_error("Result from operation is too small");
            _stack.pop();
            _stack.push(static_cast<int>(check));
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
