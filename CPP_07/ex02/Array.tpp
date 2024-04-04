template<typename T>
Array<T>::Array() : elements(nullptr), arraySize(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), arraySize(n) {
    for (size_t i = 0; i < arraySize; ++i) {
        elements[i] = T();
    }
}

template<typename T>
Array<T>::Array(const Array& other) : elements(new T[other.arraySize]), arraySize(other.arraySize) {
    for (size_t i = 0; i < arraySize; ++i) {
        elements[i] = other.elements[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] elements;
        elements = new T[other.arraySize];
        arraySize = other.arraySize;
        for (size_t i = 0; i < arraySize; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    delete[] elements;
}

template<typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= arraySize) {
        throw std::out_of_range("Index out of bounds");
    }
    return elements[index];
}

template<typename T>
size_t Array<T>::size() const {
    return arraySize;
}
