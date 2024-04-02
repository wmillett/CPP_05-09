#pragma once

#include <iostream>
#include <cctype>
#include <sstream>
#include <cstring>
#define IMP std::string("impossible")
#define NDISP std::string("Non displayable")



enum e_Pseudo{
    pinff,
    minff,
    nanf,
    nan,
    none
};

enum e_DataType{
    integer,
    character,
    dinteger,
    finteger,
    none
};


class Scalar{
    public:
        Scalar(std::string a);
        Scalar(Scalar& other);
        Scalar& operator=(const Scalar& other);
        ~Scalar();

    private:
        Scalar();
        std::string scalarChar;
        std::string scalarInt;
        std::string scalarDouble;
        std::string scalarFloat;
        
        std::string input;
        e_Pseudo isPseudo;
        e_DataType dataType;

        bool checkPseudo(std::string a);
        void convertToChar(int a);
        void isChar(std::string a);
        bool checkInt(std::string a);
        bool checkDataType(std::string a);
        void printScalar(void);
};
