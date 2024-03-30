#pragma once

#include <iostream>
#include <cctype>

#define IMP std::string("impossible")
#define NDISP std::string("Non displayable")



enum e_Pseudo{
    pinff,
    minff,
    nanf,
    nan,
    none
};



class Scalar{
    public:
        Scalar(std::string a);
        Scalar(Scalar& other);
        Scalar& operator=(const Scalar& other);
        ~Scalar();
        void convertScalar(std::string a);

    private:
        Scalar();
        std::string scalarChar;
        std::string scalarInt;
        std::string scalarDouble;
        std::string scalarFloat;
        e_Pseudo isPseudo;

        void printScalar(void);
};
