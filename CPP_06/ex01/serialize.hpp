#pragma once

#include <iostream>

typedef struct{
    int useless;

}Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
