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
    std::cout << "Char: " << scalarChar << std::endl;
    std::cout << "Int: " << scalarInt << std::endl;
    std::cout << "Float: " << scalarFloat << std::endl;
    std::cout << "Double: " << scalarDouble << std::endl;
};




static bool checkDataType(std::string a){
    const size_t size = a.size();
    size_t count = 0;
//     if()
//    if()


};










void Scalar::convertScalar(std::string a){





};




Scalar::Scalar(): scalarChar(IMP), scalarInt(IMP), scalarDouble(IMP), scalarFloat(IMP), isPseudo(none){

};

Scalar::Scalar(std::string a): scalarChar(IMP), scalarInt(IMP), scalarDouble(IMP), scalarFloat(IMP), isPseudo(none){
    
};

Scalar::~Scalar(){
};