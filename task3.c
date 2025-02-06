#include <iostream>
int* allocateArray(int size) {
    int* arr = new int[size];
    return arr;
}
int main() {
    int size = 5;
    int* array = allocateArray(size);
    for (int i = 0; i < size; i++) {
        array[i] = i * 2;
        std::cout << array[i] << " ";
    }
    delete[] array;
    return 0;
}
