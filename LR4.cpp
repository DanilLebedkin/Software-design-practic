#include<iostream>
#include<string>
using namespace std;

class Film
{
public:
	Film(const string& title) : title(title){}
	void play() {
		cout << "Показ фильма: " << title << endl;
	}
private:
	string title;
};


class Horror :protected Film
{	
public:
	Horror(const string& title, const string& mainEnemy) :Film(title), mainEnemy(mainEnemy) {}
	void displayMainEnemy() {
		cout << "Главный злодей хоррора- " << mainEnemy << endl;
	}
private:
	string mainEnemy;
};


class Slasher :protected Horror 
{
public:
	Slasher(const string& title, const string&mainEnemy, int countOfVictims):Horror(title,mainEnemy),countOfVictims(countOfVictims){}
	
	void ShowCountVictims() {
		cout << "Кол-во жертв: " << countOfVictims << endl;
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
		cout << "Кол-во смеха в фильме:" << laughterCount << endl;
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
		cout << "Черный юмор в фильме: " << darkHumor << endl;
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
		cout << "Элементы пародии в фильме: " << parodyElement << endl;
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
	Slasher slasherfilm("Friday 13 2","Джейсон Вурхиз",20);
	slasherfilm.InfoAboutHorror();
	ParodyDarkComedy parodyfilm("Scary movie", 100, "Черный юмор над ЛГБТ и клише хоррор фильмов", "Пародии на фильм Крик и Шестое чувство");
	parodyfilm.InfoAboutComedy();
	return 0;
}