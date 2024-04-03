#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}
A::~A(){}
B::~B(){}
C::~C(){}

#include <cstdlib>
#include <ctime>

int getRandomNumber(){
    int randomNumber = std::rand() % 3;
    return randomNumber + 1;
}

Base * generate(void){
    int randomNumber = getRandomNumber();
    switch(randomNumber){
        case 1:
            std::cout << "Generated a class A" << std::endl;
            return new A();
        case 2:
            std::cout << "Generated a class B" << std::endl;
            return new B();
        case 3:
            std::cout << "Generated a class C" << std::endl;
            return new C();
        default:
            break;
    }
    std::cout << "Generated a class A" << std::endl;
    return new A();
}

void identify(Base* p){
    Base* a = dynamic_cast<A*>(p);
    if(a){
        std::cout << "Base is of type A" << std::endl; return;
    }
    a = dynamic_cast<B*>(p);
    if(a){
         std::cout << "Base is of type B" << std::endl; return;
    }
    a = dynamic_cast<C*>(p);
    if(a){
        std::cout << "Base is of type C" << std::endl; return;
    }
}

void identify(Base& p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "Base is of type A" << std::endl; return;
    } catch (std::exception){}
     try{
        (void)dynamic_cast<B&>(p);
        std::cout << "Base is of type B" << std::endl; return;
    } catch (std::exception){}
     try{
        (void)dynamic_cast<C&>(p);
        std::cout << "Base is of type C" << std::endl; return;
    } catch (std::exception){}
}

int main(){
    std::srand(std::time(0));
    for (size_t i = 0; i < 10; i++){
        Base *base = generate();
        identify(base);
        identify(*base);
        delete base;
        std::cout << "------------" << std::endl;
    }
}
