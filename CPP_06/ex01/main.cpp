#include "serialize.hpp"

Data* deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}

uintptr_t serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

int main(){
    Data data;
    Data *origin = &data;

    data.useless = 42;
    uintptr_t serPtr = serialize(origin);
    std::cout << "serie result: " << serPtr << std::endl;
    Data *desPtr = deserialize(serPtr);
    if (desPtr == origin){
        std::cout << "original ptr: " << origin << std::endl;
        std::cout << "deserialize ptr: " << desPtr << std::endl;
        std::cout << "value in data: " << data.useless << std::endl;
    }
    return 0;
}
