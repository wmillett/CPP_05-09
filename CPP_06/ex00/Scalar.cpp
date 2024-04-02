#include "Scalar.hpp"


static bool containsSpace(std::string a){
    const size_t size = a.size();
    for(size_t i = 0; i < size; i++){
        if(isspace(a[i]))
            return 1;
    }
    return 0;
}

void Scalar::printScalar(void){
    if(!strcmp(scalarChar.c_str(), IMP.c_str()) || !strcmp(scalarChar.c_str(), NDISP.c_str()))
        std::cout << "Char: " << scalarChar << std::endl;
    else
        std::cout << "Char: '" << scalarChar << "'" << std::endl;
    std::cout << "Int: " << scalarInt << std::endl;
    std::cout << "Float: " << scalarFloat << std::endl;
    std::cout << "Double: " << scalarDouble << std::endl;
};

static std::string intToString(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

static std::string floatToString(float number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

static std::string doubleToString(double number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

static std::string charToString(char number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

void Scalar::convertToChar(int a){
    if(a < 0 || a > 127){
        scalarChar = IMP;
        return ;
    }
    if(!isprint(a)){
        scalarChar = NDISP;
        return ;
    }
    scalarChar = charToString(static_cast<char>(a));
};

bool Scalar::checkPseudo(std::string a){
    if(!strcmp(a.c_str(), "nan") || !strcmp(a.c_str(), "nanf")){
        scalarFloat = "nanf";
        scalarDouble = "nan";
        printScalar();
        return 1;
    }
    if(!strcmp(a.c_str(), "-inff") || !strcmp(a.c_str(), "-inf")){
        scalarFloat = "-inff";
        scalarDouble = "-inf";
        printScalar();
        return 1;
    }
    if(!strcmp(a.c_str(), "+inff") || !strcmp(a.c_str(), "+inf")){
        scalarFloat = "+inff";
        scalarDouble = "+inf";
        printScalar();
        return 1;
    }
    return 0;
};


void Scalar::isChar(std::string a){
    if(isprint(a[0])){
        if(!isdigit(a[0])){
            scalarChar = a;
            scalarInt = intToString(static_cast<int>(a[0]));
        }
        else{
            scalarChar = charToString(static_cast<char>(a[0]));
            scalarInt = intToString(a[0]);
        }
    }
    else{
        scalarChar = NDISP;
        scalarInt = intToString(static_cast<int>(a[0]));
    }
    scalarFloat = floatToString(static_cast<float>(a[0]));
    scalarFloat = doubleToString(static_cast<double>(a[0]));
    printScalar();
};

bool Scalar::checkInt(std::string a){
    for(size_t i = 0; a[i]; i++){
        if(!isdigit(a[i]))
            return 0;
    }
    int res = std::stoi(a);
    convertToChar(res);
    scalarFloat = floatToString(static_cast<float>(res));
    scalarDouble = doubleToString(static_cast<double>(res));
    printScalar();
    return 1;
};


bool Scalar::checkDataType(std::string a){
    const size_t size = a.size();
    size_t count = 0;
    long check = std::strtol(a.c_str(), NULL, 10);
    if (check < INT_MIN || check > INT_MAX)
        return(printScalar(), 0);
    if(size == 1){
        isChar(a);
        return 0;
    }
    else if(checkPseudo(a)){
        return 0;
    }
    else if(checkInt(a)){
        return 0;
    }
    

};


Scalar::Scalar(): scalarChar(IMP), scalarInt(IMP), scalarDouble(IMP), scalarFloat(IMP), input("none"){
};

Scalar::Scalar(std::string a): scalarChar(IMP), scalarInt(IMP), scalarDouble(IMP), scalarFloat(IMP), input(a){
};

Scalar::Scalar(Scalar& other): input(other.input){};

 Scalar& operator=(const Scalar& other){
    if(this != &other){
        input = other.input;
    }
    return *this;
 };

Scalar::~Scalar(){
};