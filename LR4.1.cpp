#include<iostream>
#include<string>
using namespace std;
class Transport
{
public:

	Transport(int maxspeed, double weight, string mark) {
		this->maxspeed = maxspeed;
		this->weight = weight;
		this->mark = mark;
	}
	void display() {
		cout << maxspeed << "\t" << weight << "\t" << mark << endl;
	}
protected:
	int maxspeed;
	double weight;
	string mark;
};
class Avto :public Transport {
public:
	Avto(int maxspeed, double weight, string mark, int numberofdoors, string fuel) :Transport(
		maxspeed,
		weight,
		mark
	) {
		this->numberofdoors = numberofdoors;
		this->fuel = fuel;
	}
	void display1() {
		cout << maxspeed << "\t" << weight << "\t" << mark << "\t" << numberofdoors << "\t" << fuel << endl;
	}
protected:
	int numberofdoors;
	string fuel;
};
class Bycicle :public Transport {
public:
	Bycicle(int maxspeed, double weight, string mark, int numberofperedach, string materrama) :Transport(
		maxspeed,
		weight,
		mark
	) {
		this->numberofperedach=numberofperedach;
		this->materrama=materrama;
	}
	void display2() {
		cout << maxspeed << "\t" << weight << "\t" << mark << "         " << numberofperedach << "\t" << materrama << endl;
	}
protected:
	int numberofperedach;
	string materrama;
};
int main() {
	Transport a(100,20.3,"BMW");
	Avto b(200,15.5,"Mersedes",4,"Gas");
	Bycicle c(50,0.0015,"Ukraine",3,"Plastic");
	a.display();
	b.display1();
	c.display2();

	return 0;
}