#include <iostream>
#include <string>
using namespace std;
struct Book {
    string title;
    string author;
    int publicationYear;
    string genre;
};
void displayBook(const Book& book) {
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Publication Year: " << book.publicationYear << endl;
    cout << "Genre: " << book.genre << endl;
    cout << "-------------------------" << endl;
}
void displayAllBooks(Book library[], int bookCount) {
    for (int i = 0; i < bookCount; ++i) {
        displayBook(library[i]);
    }
}
void searchBook(Book library[], int bookCount, const string& query) {
    bool found = false;
    for (int i = 0; i < bookCount; ++i) {
        if (library[i].title.find(query) != string::npos || library[i].author.find(query) != string::npos) {
            displayBook(library[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No books found with that title or author." << endl;
    }
}

void addBook(Book library[], int& bookCount, int maxBooks) {
    if (bookCount >= maxBooks) {
        cout << "Library is full. Cannot add more books." << endl;
        return;
    }

    Book newBook;
    cout << "Enter book title: ";
    getline(cin, newBook.title);
    cout << "Enter author: ";
    getline(cin, newBook.author);
    cout << "Enter publication year: ";
    cin >> newBook.publicationYear;
    cin.ignore();
    cout << "Enter genre: ";
    getline(cin, newBook.genre);

    library[bookCount] = newBook;
    bookCount++;
    cout << "Book added successfully!" << endl;
}

void updateBook(Book library[], int bookCount, const string& title) {
    for (int i = 0; i < bookCount; ++i) {
        if (library[i].title == title) {
            cout << "Updating details for: " << title << endl;
            cout << "Enter new author (current: " << library[i].author << "): ";
            getline(cin, library[i].author);
            cout << "Enter new publication year (current: " << library[i].publicationYear << "): ";
            cin >> library[i].publicationYear;
            cin.ignore();
            cout << "Enter new genre (current: " << library[i].genre << "): ";
            getline(cin, library[i].genre);
            cout << "Book updated successfully!" << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

int main() {
    const int maxBooks = 10;
    Book library[maxBooks];
    int bookCount = 0;
    int choice;

    while (true) {
        cout << "\nLibrary Inventory System" << endl;
        cout << "1. Add a new book" << endl;
        cout << "2. Search for a book" << endl;
        cout << "3. Update a book's information" << endl;
        cout << "4. Display all books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            addBook(library, bookCount, maxBooks);
        }
        else if (choice == 2) {
            string searchQuery;
            cout << "Enter title or author to search: ";
            getline(cin, searchQuery);
            searchBook(library, bookCount, searchQuery);
        }
        else if (choice == 3) {
            string title;
            cout << "Enter the title of the book to update: ";
            getline(cin, title);
            updateBook(library, bookCount, title);
        }
        else if (choice == 4) {
            displayAllBooks(library, bookCount);
        }
        else if (choice == 5) {
            cout << "Exiting the program." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
