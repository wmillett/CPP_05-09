#include "Scalar.hpp"


int main(int argc, char** argv){
    if(argc != 2){
        std::cerr << "Error: Wrong number of args" << std::endl;
        return 1;
    }
    std::string a(argv[1]);
    if(a.empty()){
        std::cerr << "Error: Empty string" << std::endl;
        return 1;
    }
    Scalar con(a);
    return 0;
}
