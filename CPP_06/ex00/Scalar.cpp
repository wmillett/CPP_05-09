#include "Scalar.hpp"


// static bool containsSpace(std::string a){
//     const size_t size = a.size();
//     for(size_t i = 0; i < size; i++){
//         if(isspace(a[i]))
//             return 1;
//     }
//     return 0;
// }
static bool containsDot(std::string a){
    const size_t size = a.size();
    for(size_t i = 0; i < size; i++){
        if(a[i] == '.')
            return 1;
    }
    return 0;
};

void Scalar::printScalar(void){
    if(scalarChar == IMP || scalarChar == NDISP)
        std::cout << "Char: " << scalarChar << std::endl;
    else
        std::cout << "Char: '" << scalarChar << "'" << std::endl;
    std::cout << "Int: " << scalarInt << std::endl;
    if(scalarFloat == IMP){
        std::cout << "Float: " << scalarFloat << std::endl;
        std::cout << "Double: " << scalarDouble << std::endl;
    }
    else if(containsDot(scalarFloat) || dontAddDecimal){
        std::cout << "Float: " << scalarFloat << "f" << std::endl;
        std::cout << "Double: " << scalarDouble << std::endl;
    }
    else{
        std::cout << "Float: " << scalarFloat << ".0f" << std::endl;
        std::cout << "Double: " << scalarDouble << ".0" << std::endl;
    }
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

// std::string Scalar::convertIntToFloat(int a){
//     std::string tmp = intToString(a);
//     tmp.push_back('f');
//     return tmp;
// };

bool Scalar::checkPseudo(std::string a){
    if(!strcmp(a.c_str(), "nan") || !strcmp(a.c_str(), "nanf")){
        scalarFloat = "nanf";
        scalarDouble = "nan";
        dontAddDecimal = 1;
        printScalar();
        return 1;
    }
    if(!strcmp(a.c_str(), "-inff") || !strcmp(a.c_str(), "-inf")){
        scalarFloat = "-inff";
        scalarDouble = "-inf";
        dontAddDecimal = 1;
        printScalar();
        return 1;
    }
    if(!strcmp(a.c_str(), "+inff") || !strcmp(a.c_str(), "+inf")){
        scalarFloat = "+inff";
        scalarDouble = "+inf";
        dontAddDecimal = 1;
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
            scalarFloat = intToString(static_cast<int>(a[0]));
            scalarDouble = doubleToString(static_cast<double>(a[0]));
        }
        else{
            scalarChar = NDISP;
            scalarInt = intToString(a[0] - 48);
            scalarFloat = intToString(static_cast<int>(a[0] - 48));
            scalarDouble = doubleToString(static_cast<double>(a[0] - 48));
        }
    }
    else{
        scalarChar = NDISP;
        scalarInt = intToString(static_cast<int>(a[0]));
        scalarFloat = intToString(static_cast<int>(a[0]));
        scalarDouble = doubleToString(static_cast<double>(a[0]));
    }
    printScalar();
};

bool Scalar::checkInt(std::string a){
    for(size_t i = 0; a[i]; i++){
        if(a[i] == '-'){
            if(i != 0)
                return 0;
        }
        else if(!isdigit(a[i]))
            return 0;
    }
    int res = std::stoi(a);
    scalarInt = intToString(res);
    convertToChar(res);
    scalarFloat = floatToString(static_cast<float>(res));
    scalarDouble = doubleToString(static_cast<double>(res));
    printScalar();
    return 1;
};

bool Scalar::checkOther(std::string a){
    bool tmp = 0;
    const size_t size = a.size();
    for(size_t i = 0; i < size; i++){
        if(a[i] == '-'){
            if(i != 0)
                return 0;
        }
        if(a[i] == '.'){
            if(tmp || i == 0 || i + 1 == size){
                return 0;
            }
            tmp = 1;
        }
        else if(!isdigit(a[i])){
            if(i + 1 == size && a[i] == 'f'){
                dataType = finteger;
                return 1;
            }
            return 0;
        }
    }
    dataType = dinteger;
    return 1;
};

bool Scalar::checkDataType(){
    const size_t size = input.size();
    long check = std::strtol(input.c_str(), NULL, 10);
    if (check < INT_MIN || check > INT_MAX)
        return(printScalar(), 0);
    if(size == 1){
        isChar(input);
        return 0;
    }
    else if(checkPseudo(input)){
        return 0;
    }
    else if(checkInt(input)){
        return 0;
    }
    else if(checkOther(input)){
        if(dataType == finteger){
            float res = std::stof(input);
            scalarFloat = floatToString(res);
            scalarDouble = doubleToString(static_cast<double>(res));
            convertToChar(static_cast<int>(res));
            scalarInt = intToString(static_cast<int>(res));
            printScalar();
            return 0;
        }
        else{
            double res = std::stod(input);
            std::cout << res << std::endl;
            scalarDouble = doubleToString(res);
            scalarFloat = floatToString(static_cast<float>(res));
            convertToChar(static_cast<int>(res));
            scalarInt = intToString(static_cast<int>(res));
            printScalar();
            return 0;
        }
    }
    else{
        printScalar();
        return 1;
    }
};

Scalar::Scalar(): scalarChar(IMP), scalarInt(IMP), scalarDouble(IMP), scalarFloat(IMP), input("none"), dataType(none), dontAddDecimal(0){
};

Scalar::Scalar(std::string a): scalarChar(IMP), scalarInt(IMP), scalarDouble(IMP), scalarFloat(IMP), input(a), dataType(none), dontAddDecimal(0){
    checkDataType();
};

Scalar::Scalar(Scalar& other): input(other.input){};

Scalar& Scalar::operator=(const Scalar& other){
    if(this != &other){
        input = other.input;
    }
    return *this;
};

Scalar::~Scalar(){
};
