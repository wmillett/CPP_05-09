#include "BitcoinExchange.hpp"


int main(int argc, char **argv){
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename(argv[1]);
    if(filename.empty()){
        std::cerr << "input filename is empty" << std::endl;
        return 1;
    }
    try{
        Bitcoin btc(filename);
        btc.convert();

    }
    catch(const std::exception& e){

        return 1;
    }
    






    return 0;
}