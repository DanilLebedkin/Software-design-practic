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
        cout << "Enter-����� ������, ESC-�����"<<endl;
        c = _getch();
        switch (c)
        {
           
        case 27:return;

        default:
            cout << "������ ����� ������ ��� ������" << endl;
            cin >> i;
            cout << vec1[i-1] << ", ������� ��� = " << vec2[i-1] << endl;
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
    studentGrades["����"] = 4.5;
    studentGrades["�����"] = 3.8;
    studentGrades["��������"] = 4.2;
    studentGrades["������"] = 4.0;
    cout << "���������� ��� ��������:" << endl;
    for (const auto& student : studentGrades) {
        cout << student.first << ": " << student.second <<endl;
    }

    string searchStudent;
   
    do
    {
        cout << "\n������ ��'� �������� ��� ������ ���������� ����: ";
        cin >> searchStudent;
        student.push_back(searchStudent);
        auto it = studentGrades.find(searchStudent);
        if (it != studentGrades.end()) {
            GPA.push_back(it->second);
            cout << "������� ��� �������� " << searchStudent << ": " << it->second << std::endl;
        }
        else {
            cout << "������� � ������ " << searchStudent << " �� ���������." << std::endl;
        }
        cout << "Enter-����������,ESC-�����" << endl;
        c = _getch();
    } while (c!=27);
    cout << endl;
    journal(student, GPA);
    return 0;
}