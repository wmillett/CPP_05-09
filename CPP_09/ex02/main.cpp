#include "PmergeMe.hpp"










int main(int argc, char **argv){
    // merge abc(argv[0]);
    // std::vector<int> A;
    // A.push_back(2);
    // A.push_back(5);
    // A.push_back(1);
    // A.push_back(6);
    // A.push_back(7);
    // A.push_back(3);
    // A.push_back(8);
    // A.push_back(4);
    // A.push_back(9);


    // abc.sort(A, 0, A.size() - 1);
    //  for (int i = 0; A[i]; i++) {
    //     std::cout << i << " ";
    // }
    // return 0;

    ///////////



    if(argc < 2){
        std::cout << "Usage: ./PmergeMe <args>" << std::endl;
        return 1;
    }
    std::vector<int>input;
    std::list<int>inputlist;
    double tmp;
    for(size_t i = 1; argv[i]; i++){
        tmp = std::stod(argv[i]);
        if(tmp > std::numeric_limits<int>::max()){
            std::cout << "Error: number too large" << std::endl;
            return 1;
        }
        if(tmp < 0){
            std::cout << "Error: number is negative" << std::endl;
            return 1;
        }
        input.push_back(static_cast<int>(tmp));
        inputlist.push_back(static_cast<int>(tmp));
    }
     try{
        merge a(argv[1]);
        a.calculate(input, inputlist);
    }
    catch(std::exception & e){
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}