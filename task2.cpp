#include <iostream>
#include <string>
using namespace std;
const int MAX_PRODUCTS = 100;
struct Product {
    int product_id;
    string name;
    float price;
    int quantity;
    string description;
};
Product products[MAX_PRODUCTS];
int productCount = 0;
void addProduct(int product_id, string name, float price, int quantity, string description) {
    if (productCount < MAX_PRODUCTS) {
        products[productCount].product_id = product_id;
        products[productCount].name = name;
        products[productCount].price = price;
        products[productCount].quantity = quantity;
        products[productCount].description = description;
        productCount++;
        cout << "Product '" << name << "' added successfully!" << endl;
    } else {
        cout << "Inventory is full! Cannot add more products." << endl;
    }
}
void displayProduct(int product_id) {
    bool found = false;
    for (int i = 0; i < productCount; i++) {
        if (products[i].product_id == product_id) {
            cout << "ID: " << products[i].product_id
                 << ", Name: " << products[i].name
                << ", Price: $" << products[i].price
                 << ", Quantity: " << products[i].quantity
                << ", Description: " << products[i].description << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product not found." << endl;
    }
}
void updateProduct(int product_id, string name, float price, int quantity, string description) {
    bool found = false;
    for (int i = 0; i < productCount; i++) {
    if (products[i].product_id == product_id) {
    if (!name.empty()) products[i].name = name;
    if (price >= 0) products[i].price = price;
    if (quantity >= 0) products[i].quantity = quantity;
    if (!description.empty()) products[i].description = description;
     cout << "Product '" << product_id << "' updated successfully!" << endl;
       found = true;
         break;
        }
    }
    if (!found) {
      cout << "Product not found." << endl;
    }
}
void removeProduct(int product_id) {
    bool found = false;
    for (int i = 0; i < productCount; i++) {
        if (products[i].product_id == product_id) {
            for (int j = i; j < productCount - 1; j++) {
           products[j] = products[j + 1];
           }
            productCount--;
            cout << "Product '" << product_id << "' removed successfully." << endl;
           found = true;
           break;
        }
    }
    if (!found) {
        cout << "Product not found." << endl;
    }
}

int main() {
    addProduct(101, "Laptop", 799.99, 10, "High performance laptop");
    addProduct(102, "Smartphone", 599.99, 15, "Latest model smartphone");

    displayProduct(101);

    updateProduct(101, "", 749.99, 8, "");

    removeProduct(102);

    displayProduct(102);

    return 0;
}
