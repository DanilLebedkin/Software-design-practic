#include <iostream>
#include <vector>
#include <algorithm>
#include<conio.h>
#include <string>
#include<Windows.h>
using namespace std;
class Book {
public:
    Book(string title, string author, int year) : title(title), author(author), year(year) {}

    void displayInfo() const {
        cout << "Книга: " << title << ", Автор: " << author << ", Рік: " << year << endl;
    }

    // Оператор порівняння за назвою книги
    bool operator<(const Book& other) const {
        return title < other.title;
    }
   string getTitle() {
       return this->title;
    }
   string getAuthor() {
       return this->author;
   }
   int getYear() {
       return this->year;
   }
   void setTitle(string title) {
       this->title = title;
   }
   void setAuthor(string author) {
       this->author = author;
   }
   void setYear(int year) {
       this->year = year;
   }
private:
    string title;
    string author;
    int year;
};
void EditBook(vector<Book>&vec) {
    int i=0,year;
    string tittle, author;
    cout << "Input number of book in library" << endl;
    cin >> i;
    if (i<0&&i>vec.size())
    {
        cout << "Uncorrect input" << endl;
    }
    else {
        vec[i - 1].displayInfo();
        cout << "Input new tittle" << endl;
        cin >> tittle;
        vec[i - 1].setTitle(tittle);
        cout << "Input new author" << endl;
        cin >> author;
        vec[i - 1].setAuthor(author);
        cout << "Input new year" << endl;
        cin >> year;
        vec[i - 1].setYear(year);
    }
   
}
void addBook(vector<Book>&vec) {
    int year=0;
    
    string tittle, author;
    cout << "Input new tittle" << endl;
    cin >> tittle;
    cout << "Input new author" << endl;
    cin >> author;
    cout << "Input new year" << endl;
    cin >> year;
    vec.push_back(Book(tittle, author, year));
}
void deleteBook(vector<Book>&vec) {
    int k = 0;
    cout << "Input number of book for deleting" << endl;
    cin >> k;
    if (k > vec.size()||k<0)
    {
        cout << "Uncorrect input" << endl;
    }
    else
    {
        vec.erase(vec.begin() + (k - 1));
    }
   
}
void Menu() {
    cout << "1. Add book" << endl;
    cout << "2. Print library" << endl;
    cout << "3. Edit book" << endl;
    cout << "4. Delete book" << endl;
    cout << "5. Sort books" << endl;
    cout << "ESC. Exit" << endl;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Book> library;
    int year = 0;

    string tittle, author;
    char c;
        do{
            Menu();
            do
            {
                c = _getch();
            } while (c < '0' && c>'5' && c != 27);

            switch (c) {
            case'1':
                system("cls");
                addBook(library);
                system("pause");
                break;
            case'2':
                system("cls");
                for (const auto& book : library) {
                    book.displayInfo();
                }
                system("pause");
                break;
            case'3':
                system("cls");
                EditBook(library);
                system("pause");
                break;
            case'4':
                system("cls");
                deleteBook(library);
                system("pause");
                break;
            case'5':
                system("cls");
                sort(library.begin(), library.end());
                system("pause");
                break;
            default:
                break;
                system("cls");
            }
        } while (c != 27);
    return 0;
}
