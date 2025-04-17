#include "LibrarySystem.h"

int main() {
    LibrarySystem system;
    int choice;

    while (true) {
        setConsoleColor(11);
        cout << "\n==========  LIBRARY MENU  ==========\n";
        setConsoleColor(14);
        cout << "1. Add Book\n";
        cout << "2. Register Member\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. View All Books\n";
        cout << "6. View Borrowed Records\n";
        cout << "0. Exit\n";
        setConsoleColor(11);
        cout << "=======================================\n";
        setConsoleColor(10);
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.addBook();
            break;
        case 2:
            system.registerMember();
            break;
        case 3:
            system.borrowBook();
            break;
        case 4:
            system.returnBook();
            break;
        case 5:
            system.viewBooks();
            break;
        case 6:
            system.viewBorrowed();
            break;
        case 0:
            setConsoleColor(12);
            cout << "Exiting Library System. Goodbye!\n";
            setConsoleColor(7);
            return 0;
        default:
            setConsoleColor(4);
            cout << "Invalid choice. Please try again.\n";
        }

        setConsoleColor(7);
    }

    return 0;
}