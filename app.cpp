#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int year;

    Book(int _id, string _title, string _author, int _year) {
        id = _id;
        title = _title;
        author = _author;
        year = _year;
    }

    void display() {
        cout << "ID: " << id << "\n"
             << "Title: " << title << "\n"
             << "Author: " << author << "\n"
             << "Year: " << year << "\n"
             << "--------------------------" << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id, year;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Year: ";
        cin >> year;

        books.push_back(Book(id, title, author, year));
        cout << "✅ Book added successfully.\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books found in the library.\n";
            return;
        }
        cout << "\n--- Library Books ---\n";
        for (auto &book : books) {
            book.display();
        }
    }

    void searchBook() {
        int searchID;
        cout << "Enter Book ID to search: ";
        cin >> searchID;

        for (auto &book : books) {
            if (book.id == searchID) {
                cout << "✅ Book Found:\n";
                book.display();
                return;
            }
        }
        cout << "❌ Book with ID " << searchID << " not found.\n";
    }

    void deleteBook() {
        int deleteID;
        cout << "Enter Book ID to delete: ";
        cin >> deleteID;

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == deleteID) {
                books.erase(it);
                cout << "✅ Book deleted successfully.\n";
                return;
            }
        }
        cout << "❌ Book with ID " << deleteID << " not found.\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Delete Book by ID\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.displayBooks(); break;
            case 3: lib.searchBook(); break;
            case 4: lib.deleteBook(); break;
            case 5: cout << "Exiting the program.\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
