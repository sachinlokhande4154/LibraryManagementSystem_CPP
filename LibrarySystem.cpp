#include "LibrarySystem.h"

LibrarySystem::LibrarySystem() {
    setConsoleColor(11);
    cout << "\nLibrary Management System Initialized Successfully!\n\n";
    setConsoleColor(7);
}

void LibrarySystem::addBook() {
    Book book;
    setConsoleColor(10);
    cout << "Enter Book ID: ";
    cin >> book.bookID;
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, book.title);
    cout << "Enter Author: ";
    getline(cin, book.author);
    book.isAvailable = true;
    books[book.bookID] = book;
    setConsoleColor(2);
    cout << "✅ Book Added Successfully!\n";
    setConsoleColor(7);
}

void LibrarySystem::registerMember() {
    Member member;
    setConsoleColor(14);
    cout << "Enter Member ID: ";
    cin >> member.memberID;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, member.name);
    members[member.memberID] = member;
    setConsoleColor(2);
    cout << "✅ Member Registered Successfully!\n";
    setConsoleColor(7);
}

void LibrarySystem::borrowBook() {
    int bookID, memberID;
    Borrow borrow;

    setConsoleColor(11);
    cout << "Enter Member ID: ";
    cin >> memberID;

    if (members.find(memberID) == members.end()) {
        setConsoleColor(4);
        cout << "❌ Member not found.\n";
        setConsoleColor(7);
        return;
    }

    cout << "Enter Book ID to Borrow: ";
    cin >> bookID;

    if (books.find(bookID) == books.end()) {
        setConsoleColor(4);
        cout << "❌ Book not found.\n";
        setConsoleColor(7);
        return;
    }

    if (!books[bookID].isAvailable) {
        setConsoleColor(6);
        cout << "⚠️ Book is currently borrowed.\n";
        setConsoleColor(7);
        return;
    }

    cin.ignore();
    cout << "Enter Borrow Date: ";
    getline(cin, borrow.borrowDate);
    cout << "Enter Expected Return Date: ";
    getline(cin, borrow.returnDate);

    borrow.bookID = bookID;
    borrow.memberID = memberID;
    borrowedBooks.push_back(borrow);
    books[bookID].isAvailable = false;

    setConsoleColor(2);
    cout << "✅ Book borrowed successfully!\n";
    setConsoleColor(7);
}

void LibrarySystem::returnBook() {
    int bookID;
    setConsoleColor(14);
    cout << "Enter Book ID to return: ";
    cin >> bookID;

    if (books.find(bookID) == books.end()) {
        setConsoleColor(4);
        cout << "❌ Book not found.\n";
        setConsoleColor(7);
        return;
    }

    books[bookID].isAvailable = true;

    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (it->bookID == bookID) {
            borrowedBooks.erase(it);
            break;
        }
    }

    setConsoleColor(2);
    cout << "✅ Book returned successfully!\n";
    setConsoleColor(7);
}

void LibrarySystem::viewBooks() {
    setConsoleColor(11);
    cout << "\n📚 Available Books:\n";
    for (const auto& pair : books) {
        const Book& book = pair.second;
        setConsoleColor(book.isAvailable ? 10 : 4);
        cout << "ID: " << book.bookID
            << " | Title: " << book.title
            << " | Author: " << book.author
            << " | " << (book.isAvailable ? "Available" : "Borrowed") << "\n";
    }
    setConsoleColor(7);
}

void LibrarySystem::viewBorrowed() {
    setConsoleColor(14);
    cout << "\n📕 Borrowed Books:\n";
    for (const auto& record : borrowedBooks) {
        const Book& book = books[record.bookID];
        const Member& member = members[record.memberID];
        cout << "Book: " << book.title
            << " | Borrowed by: " << member.name
            << " | From: " << record.borrowDate
            << " to: " << record.returnDate << "\n";
    }
    setConsoleColor(7);
}

void LibrarySystem::showMenu() {
    int choice;
    do {
        setConsoleColor(3);
        cout << "\n==========  Library Menu ==========\n";
        setConsoleColor(9);
        cout << "1. Add Book\n";
        cout << "2. Register Member\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. View All Books\n";
        cout << "6. View Borrowed Books\n";
        cout << "0. Exit\n";
        setConsoleColor(3);
        cout << "=====================================\n";
        setConsoleColor(6);
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addBook(); break;
        case 2: registerMember(); break;
        case 3: borrowBook(); break;
        case 4: returnBook(); break;
        case 5: viewBooks(); break;
        case 6: viewBorrowed(); break;
        case 0: setConsoleColor(2); cout << "👋 Exiting..."; break;
        default: setConsoleColor(4); cout << "Invalid choice. Try again.\n"; break;
        }

    } while (choice != 0);
    setConsoleColor(7);
}
