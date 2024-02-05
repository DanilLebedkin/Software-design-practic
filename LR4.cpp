#include<iostream>
#include<string>
using namespace std;

class Film
{
public:
	Film(const string& title) : title(title){}
	void play() {
		cout << "����� ������: " << title << endl;
	}
private:
	string title;
};


class Horror :protected Film
{	
public:
	Horror(const string& title, const string& mainEnemy) :Film(title), mainEnemy(mainEnemy) {}
	void displayMainEnemy() {
		cout << "������� ������ �������- " << mainEnemy << endl;
	}
private:
	string mainEnemy;
};


class Slasher :protected Horror 
{
public:
	Slasher(const string& title, const string&mainEnemy, int countOfVictims):Horror(title,mainEnemy),countOfVictims(countOfVictims){}
	
	void ShowCountVictims() {
		cout << "���-�� �����: " << countOfVictims << endl;
	}
	void InfoAboutHorror() {
		play();
		displayMainEnemy();
		ShowCountVictims();

	}
private:
	int countOfVictims;
};


class Comedy : protected Film 
{
public:
	Comedy(const string& title, int laughterCount) : Film(title), laughterCount(laughterCount) {}
	void displayLaughterCount() {
		cout << "���-�� ����� � ������:" << laughterCount << endl;
	}
	
private:
	int laughterCount;
};


class DarkComedy : protected Comedy
{
public:
	DarkComedy(const string& title, int laughterCount, const string& darkHumor)
		: Comedy(title, laughterCount), darkHumor(darkHumor) {}
	void displayDarkHumor() {
		cout << "������ ���� � ������: " << darkHumor << endl;
	}
private:
	string darkHumor;
};


class ParodyDarkComedy :protected DarkComedy
{
public:
	ParodyDarkComedy(const string& title, int laughterCount, const string& darkHumor, const string& parodyElement)
		:DarkComedy(title, laughterCount, darkHumor), parodyElement(parodyElement) {}
	void displayParody()
	{
		cout << "�������� ������� � ������: " << parodyElement << endl;
	};
	void InfoAboutComedy(){
		play();
		displayLaughterCount();
		displayDarkHumor();
		displayParody();
	};

private:
	string parodyElement;
};

int main() {
	setlocale(LC_ALL, "ru");
	Slasher slasherfilm("Friday 13 2","������� ������",20);
	slasherfilm.InfoAboutHorror();
	ParodyDarkComedy parodyfilm("Scary movie", 100, "������ ���� ��� ���� � ����� ������ �������", "������� �� ����� ���� � ������ �������");
	parodyfilm.InfoAboutComedy();
	return 0;
}