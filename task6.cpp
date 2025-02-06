#include <iostream>
class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

    void resize(int newCapacity) {
        int* newArr = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }
public:
    DynamicArray() {
        size = 0;
        capacity = 5;
        arr = new int[capacity];
    }
    ~DynamicArray() {
        delete[] arr;
    }
    void addElement(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        arr[size++] = value;
    }
    void shrinkToFit() {
        resize(size);
    }
    void printArray() const {
        for (int i = 0; i < size; i++) {
           std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    int getSize() const {
        return size;
    }
};
int main() {
    DynamicArray arr;
    std::cout << "Feeding the array..." << std::endl;
    for (int i = 0; i < 10; i++) {
        arr.addElement(i * 2);
    }
    std::cout << "Current array (after feeding): ";
    arr.printArray();
    std::cout << "Shrinking the array to fit: ";
    arr.shrinkToFit();
    arr.printArray();
    std::cout << "Final size of array: " << arr.getSize() << std::endl;
    return 0;
}
