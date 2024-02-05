#include <iostream>
#include <map>
#include <string>
#include<vector>
#include<conio.h>
#include<Windows.h>
using namespace std;
void journal(vector<string>vec1,vector<double>vec2) {
    char c=0;
    int i=0;
    while (c != 27)
    {
        cout << "Enter-Пошук запиту, ESC-Вихід"<<endl;
        c = _getch();
        switch (c)
        {
           
        case 27:return;

        default:
            cout << "Введіть номер запиту для пошуку" << endl;
            cin >> i;
            cout << vec1[i-1] << ", середній бал = " << vec2[i-1] << endl;
            break;
        }
    } 
    
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    map<string, double> studentGrades;
    vector<string>student;
    vector<double>GPA;
    char c;
    studentGrades["Анна"] = 4.5;
    studentGrades["Борис"] = 3.8;
    studentGrades["Катерина"] = 4.2;
    studentGrades["Дмитро"] = 4.0;
    cout << "Інформація про студентів:" << endl;
    for (const auto& student : studentGrades) {
        cout << student.first << ": " << student.second <<endl;
    }

    string searchStudent;
   
    do
    {
        cout << "\nВведіть ім'я студента для пошуку середнього балу: ";
        cin >> searchStudent;
        student.push_back(searchStudent);
        auto it = studentGrades.find(searchStudent);
        if (it != studentGrades.end()) {
            GPA.push_back(it->second);
            cout << "Середній бал студента " << searchStudent << ": " << it->second << std::endl;
        }
        else {
            cout << "Студент з іменем " << searchStudent << " не знайдений." << std::endl;
        }
        cout << "Enter-продовжити,ESC-Вийти" << endl;
        c = _getch();
    } while (c!=27);
    cout << endl;
    journal(student, GPA);
    return 0;
}