#include <iostream>
using namespace std;
void add(int* num1, int* num2, int* result) {
    *result = *num1 + *num2;
}
void subtract(int* num1, int* num2, int* result) {
    *result = *num1 - *num2;
}
void multiply(int* num1, int* num2, int* result) {
    *result = *num1 * *num2;
}
void divide(int* num1, int* num2, float* result) {
    *result = static_cast<float>(*num1) / *num2;
}
int main() {
    int num1, num2;
    int choice;
    int intResult;
    float floatResult;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    cout << "\nSelect operation:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    switch (choice) {
        case 1:
            add(&num1, &num2, &intResult);
            cout << "Result of addition: " << intResult << endl;
            break;
        case 2:
            subtract(&num1, &num2, &intResult);
            cout << "Result of subtraction: " << intResult << endl;
            break;
        case 3:
            multiply(&num1, &num2, &intResult);
            cout << "Result of multiplication: " << intResult << endl;
            break;
        case 4:
            if (num2 != 0) {
                divide(&num1, &num2, &floatResult);
                cout << "Result of division: " << floatResult << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
            break;
        default:
            cout << "Invalid choice. Please select a valid operation (1-4)." << endl;
            break;
    }

    return 0;
}
