#include "RPN.hpp"






int main(int argc, char **argv){
    if(argc != 2){
        std::cout << "Usage: ./RPN <Polish mathematical string>" << std::endl;
        return 1;
    }
    try{
        revPol a(argv[1]);
        a.calculate();
    }
    catch(std::exception & e){
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return 1;
    }
    



    return 0;
}