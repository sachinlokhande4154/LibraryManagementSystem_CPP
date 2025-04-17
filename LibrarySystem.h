#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <windows.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Function to color console text
inline void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Book structure
struct Book {
    int bookID;
    string title;
    string author;
    bool isAvailable;
};

// Member structure
struct Member {
    int memberID;
    string name;
};

// Borrowing record
struct Borrow {
    int bookID;
    int memberID;
    string borrowDate;
    string returnDate;
};

class LibrarySystem {
private:
    unordered_map<int, Book> books;
    unordered_map<int, Member> members;
    vector<Borrow> borrowedBooks;

public:
    LibrarySystem();
    void addBook();
    void registerMember();
    void borrowBook();
    void returnBook();
    void viewBooks();
    void viewBorrowed();
    void showMenu();
};

#endif // LIBRARYSYSTEM_H
