#include<iostream>
#include<string>
using namespace std;

class User
{
public:
	User(const string& name) : name(name) {}
	void showName() {
		cout << "Name: " << name << endl;
	}
private:
	string name;
};


class LimitedUser :protected User
{
public:
	LimitedUser(const string& name, int levelAcces) :User(name), levelAcces(levelAcces) {}
	void displayLevelAcces() {
		cout << "Level of acces " << levelAcces << endl;
	}
private:
	int levelAcces;
};


class Guest :protected LimitedUser
{
public:
	Guest(const string&name , int levelAcces, int numberOfConp) :LimitedUser(name, levelAcces), numberOfComp(numberOfConp) {}

	void ShowNOC() {
		cout << "Number of computer: " << numberOfComp << endl;
	}
	void InfoAboutUser() {
		showName();
		displayLevelAcces();
		ShowNOC();

	}
private:
	int numberOfComp;
};


class UserWithRights : protected User
{
public:
	UserWithRights(const string& name, const string& post) : User(name), post(post) {}
	void displayPost() {
		cout << "Job title:" << post << endl;
	}

private:
	string post;
};


class Admin : protected UserWithRights
{
public:
	Admin(const string& name,const string& post,int salary)
		: UserWithRights(name, post), salary(salary) {}
	void displaySalary() {
		cout << "Salary: " << salary << endl;
	}
private:
	int salary;
};


class SuperAdmin :protected Admin
{
public:
	SuperAdmin(const string& name, const string& post, int salary, const string& subordinate) :Admin(name, post, salary), subordinate(subordinate){}
	void ShowSubordinate()
	{
		cout << "Subordinate: " << subordinate << endl;
	};
	void InfoAboutEmployee() {
		showName();
		displayPost();
		displaySalary();
		ShowSubordinate();
	};

private:
	string subordinate;
};

int main() {
	Guest guest("David", 0,12);
	guest.InfoAboutUser();
	SuperAdmin sadmin("Jacob", "Sales Director", 40000,"Jason");
	sadmin.InfoAboutEmployee();
	return 0;
}