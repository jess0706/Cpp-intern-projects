#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Book {
public:
    string title, author, isbn;
    
    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}
    
    void display() {
        cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << isbn << "\n\n";
    }
};

class Library {
    vector<Book> books;
    
public:
    void addBook() {
        string t, a, i;
        cout << "Enter title: "; 
        cin.ignore(); 
        getline(cin, t);
        cout << "Enter author: "; 
        getline(cin, a);
        cout << "Enter ISBN: "; 
        getline(cin, i);
        books.push_back(Book(t, a, i));
        cout << "Book added!\n\n";
    }
    
    void viewBooks() {
        if(books.empty()) {
            cout << "No books!\n\n";
        } else {
            for(auto &b : books) {
                b.display();
            }
        }
    }
    
    void searchBook() {
        string term;
        cout << "Search (title/author): "; 
        cin.ignore(); 
        getline(cin, term);
        transform(term.begin(), term.end(), term.begin(), ::tolower);
        
        bool found = false;
        for(auto &b : books) {
            string title = b.title;
            string author = b.author;
            transform(title.begin(), title.end(), title.begin(), ::tolower);
            transform(author.begin(), author.end(), author.begin(), ::tolower);
            
            if(title.find(term) != string::npos || author.find(term) != string::npos) {
                b.display();
                found = true;
            }
        }
        if(!found) cout << "No books found!\n\n";
    }
};

int main() {
    Library lib;
    int choice;
    
    while(true) {
        cout << "1. Add Book\n2. View Books\n3. Search\n4. Exit\nChoice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: lib.addBook(); break;
            case 2: lib.viewBooks(); break;
            case 3: lib.searchBook(); break;
            case 4: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
