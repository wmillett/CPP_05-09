// #include "PmergeMe.hpp"

// #define K 5

// //For list
// void insertionSortList(std::list<int>& A, int p, int q) {
//    std::list<int>::iterator it = A.begin();
//     advance(it, p);
//     for (int i = p; i < q; i++) {
//         int tempVal = *next(it, 1);
//         std::list<int>::iterator j = it;
//         while (j != A.begin() && *prev(j, 1) > tempVal) {
//             *j = *prev(j, 1);
//             --j;
//         }
//         *j = tempVal;
//         ++it;
//     }
// }

// void combineList(std::list<int>& A, int p, int q, int r) {
//     std::list<int> LA(A.begin(), next(A.begin(), q + 1));
//     std::list<int> RA(next(A.begin(), q + 1), next(A.begin(), r + 1));
//     std::list<int>::iterator LIT = LA.begin();
//     std::list<int>::iterator RIT = RA.begin();
//     std::list<int>::iterator it = next(A.begin(), p);
//     for (int i = p; i <= r; i++) {
//         if (RIT == RA.end()) {
//             *it = *LIT;
//             ++LIT;
//         } else if (LIT == LA.end()) {
//             *it = *RIT;
//             ++RIT;
//         } else if (*RIT > *LIT) {
//             *it = *LIT;
//             ++LIT;
//         } else {
//             *it = *RIT;
//             ++RIT;
//         }
//         ++it;
//     }
// }

// void merge::sortList(std::list<int>& A, int p, int r) {
//     if (r - p > K) {
//         int q = (p + r) / 2;
//         sortList(A, p, q);
//         sortList(A, q + 1, r);
//         combineList(A, p, q, r);
//     } else {
//         insertionSortList(A, p, r);
//     }
// }



// //For vector
// void insertionSort(std::vector<int>& A, int p, int q) {
//     for (int i = p; i < q; i++) {
//         int tempVal = A[i + 1];
//         int j = i + 1;
//         while (j > p && A[j - 1] > tempVal) {
//             A[j] = A[j - 1];
//             j--;
//         }
//         A[j] = tempVal;
//     }
// }

// void combine(std::vector<int>& A, int p, int q, int r) {
//     int n1 = q - p + 1;
//     int n2 = r - q;
//     std::vector<int> LA(A.begin() + p, A.begin() + q + 1);
//     std::vector<int> RA(A.begin() + q + 1, A.begin() + r + 1);
//     int RIDX = 0;
//     int LIDX = 0;
//     for (int i = p; i <= r; i++) {
//         if (RIDX == n2) {
//             A[i] = LA[LIDX];
//             LIDX++;
//         } else if (LIDX == n1) {
//             A[i] = RA[RIDX];
//             RIDX++;
//         } else if (RA[RIDX] > LA[LIDX]) {
//             A[i] = LA[LIDX];
//             LIDX++;
//         } else {
//             A[i] = RA[RIDX];
//             RIDX++;
//         }
//     }
// }

// void merge::sort(std::vector<int>& A, int p, int r) {
//     if (r - p > K) {
//         int q = (p + r) / 2;
//         sort(A, p, q);
//         sort(A, q + 1, r);
//         combine(A, p, q, r);
//     } else {
//         insertionSort(A, p, r);
//     }
// }


// merge::merge(){
// }

// merge::merge(const std::string input){
//     (void)input;
// }

// merge::merge(const merge& other){
//     *this = other;
// }

// merge& merge::operator=(const merge& other){
//     if (this != &other) {
//         _vector = other._vector;
//         _list = other._list;
//     }
//     return *this;
// }
// merge::~merge(){
// }


// void merge::calculate(std::vector<int>input, std::list<int>inputList){

//     std::cout << "Before: ";
//     for(size_t i = 0; input[i]; i++){
//         std::cout << input[i] << " ";
//     }
//     std::cout << std::endl;
//     const size_t size = input.size();
   
//    //for vector
//     clock_t start_vector = clock();
//     sort(input, 0, input.size() - 1);
//     clock_t stop_vector = clock();
//     double duration_vector = (stop_vector - start_vector) * 1000000.0 / CLOCKS_PER_SEC;

//     //for list
//     clock_t start_list = clock();
//     sortList(inputList, 0, distance(inputList.begin(), prev(inputList.end())));
//     clock_t stop_list = clock();
//     double duration_list = (stop_list - start_list) * 1000000.0 / CLOCKS_PER_SEC;

//     std::cout << "After: ";
//     for(size_t i = 0; input[i]; i++){
//         std::cout << input[i] << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "Time to process a range of " << size << "  elements with std::vector: " << std::fixed << std::setprecision(5) << duration_vector << " us" << std::endl;
//     std::cout << "Time to process a range of " << size << "  elements with std::list: " << std::fixed << std::setprecision(5) << duration_list << " us" << std::endl;
// }

#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

#define K 5

// For list
void insertionSortList(std::list<int>& A, int p, int q) {
    std::list<int>::iterator it = A.begin();
    advance(it, p);
    for (int i = p; i < q; i++) {
        int tempVal = *next(it, 1);
        std::list<int>::iterator j = it;
        while (j != A.begin() && *prev(j, 1) > tempVal) {
            *j = *prev(j, 1);
            --j;
        }
        *j = tempVal;
        ++it;
    }
}

void combineList(std::list<int>& A, int p, int q, int r) {
    std::list<int> LA(A.begin(), next(A.begin(), q + 1));
    std::list<int> RA(next(A.begin(), q + 1), next(A.begin(), r + 1));
    std::list<int>::iterator LIT = LA.begin();
    std::list<int>::iterator RIT = RA.begin();
    std::list<int>::iterator it = next(A.begin(), p);
    for (int i = p; i <= r; i++) {
        if (RIT == RA.end()) {
            *it = *LIT;
            ++LIT;
        } else if (LIT == LA.end()) {
            *it = *RIT;
            ++RIT;
        } else if (*RIT > *LIT) {
            *it = *LIT;
            ++LIT;
        } else {
            *it = *RIT;
            ++RIT;
        }
        ++it;
    }
}

void merge::sortList(std::list<int>& A, int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        sortList(A, p, q);
        sortList(A, q + 1, r);
        combineList(A, p, q, r);
    } else {
        insertionSortList(A, p, r);
    }
}

// For vector
void insertionSort(std::vector<int>& A, int p, int q) {
    for (int i = p; i < q; i++) {
        int tempVal = A[i + 1];
        int j = i + 1;
        while (j > p && A[j - 1] > tempVal) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tempVal;
    }
}

void combine(std::vector<int>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> LA(A.begin() + p, A.begin() + q + 1);
    std::vector<int> RA(A.begin() + q + 1, A.begin() + r + 1);
    int RIDX = 0;
    int LIDX = 0;
    for (int i = p; i <= r; i++) {
        if (RIDX == n2) {
            A[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            A[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            A[i] = LA[LIDX];
            LIDX++;
        } else {
            A[i] = RA[RIDX];
            RIDX++;
        }
    }
}

void merge::sort(std::vector<int>& A, int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        sort(A, p, q);
        sort(A, q + 1, r);
        combine(A, p, q, r);
    } else {
        insertionSort(A, p, r);
    }
}

merge::merge() {}

merge::merge(const std::string input) {
    (void)input;
}

merge::merge(const merge& other) {
    *this = other;
}

merge& merge::operator=(const merge& other) {
    if (this != &other) {
        _vector = other._vector;
        _list = other._list;
    }
    return *this;
}

merge::~merge() {}

void merge::calculate(std::vector<int> input, std::list<int> inputList) {
    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
    const size_t size = input.size();

    // For vector
    clock_t start_vector = clock();
    sort(input, 0, input.size() - 1);
    clock_t stop_vector = clock();
    double duration_vector = (stop_vector - start_vector) * 1000000.0 / CLOCKS_PER_SEC;

    // For list
    clock_t start_list = clock();
    sortList(inputList, 0, distance(inputList.begin(), prev(inputList.end())));
    clock_t stop_list = clock();
    double duration_list = (stop_list - start_list) * 1000000.0 / CLOCKS_PER_SEC;

    std::cout << "After: ";
    for (size_t i = 0; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::vector: " << std::fixed << std::setprecision(5) << duration_vector << " us" << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::list: " << std::fixed << std::setprecision(5) << duration_list << " us" << std::endl;
}
