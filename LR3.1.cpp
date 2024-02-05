#include<iostream>
using namespace std;
class Book
{
private:
	string author;
	string genre;
	double price;
public:
	Book() {
		this->author = "O.Genry";
		this->genre = "Detectiv";
		this->price = 150;
	}
	void setAuthor(string author) {
		this->author = "O.Genry";
	}
	void setGenre(string genre) {
		this->genre = "Detectiv";
	}
	void setPrice(int price) {
		this->price = 150;
	}
	string getAuthor() {
		return this->author;
	}
	string getGenre() {
		return this->genre;
	}
	int getPrice() {
		return this->price;
	}
	double Znushka(double price, int valZnushka) {
		int newprice =price-price/100*valZnushka;
		return newprice;
	}
};
int main() {
	Book book;
	string b,a;
	int valueZnushka;
	double p, fp;
	cout << "Input author "; cin >> b;
	book.setAuthor(b);
	cout << "Input genre "; cin >> a;
	book.setGenre(a);
	cout << "Input price "; cin >> p;
	book.setPrice(p);
	cout << "Input znushka "; cin >> valueZnushka;
	fp = book.Znushka(p, valueZnushka);
	cout << "Final price= " <<fp<< endl;

}