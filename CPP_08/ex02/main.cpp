#include "Mutantstack.hpp"

int main()
{
    MutantStack<int> mstack;
    std::list<int> testList;

    mstack.push(5);
    mstack.push(17);
    
    testList.push_front(5);
    testList.push_front(17);

    std::cout << "mstack top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "mstack top: " << mstack.top() << std::endl;
    std::cout << "testList front: " << testList.front() << std::endl;
    testList.pop_front();
    std::cout << "testList front: " << testList.front() << std::endl;


    std::cout << "size of mstack: " << mstack.size() << std::endl;
    std::cout << "size of testList: " << testList.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    testList.push_back(3);
    testList.push_back(5);
    testList.push_back(737);
    testList.push_back(0);

    std::cout << "Test iterators" << std::endl;
    std::cout << "--- mstack ---" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "--- testList ---" << std::endl;
    std::list<int>::iterator iter = testList.begin(); 
    std::list<int>::iterator itera = testList.end();
    ++iter;
    --iter;
    while (iter != itera)
    {
        std::cout << *iter << std::endl;
        ++iter;
    }
    std::stack<int> s(mstack);
    return 0;
}
