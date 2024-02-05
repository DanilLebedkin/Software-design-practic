#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include<conio.h>
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<string> favoriteFruits;
    char c=0;
    cout << "������� ������� �� ��� '���������� ������'!" << std::endl;
    cout << "������ ��� ������� ������ (������ '�����', ��� ��������� ��������):" << std::endl;

    string fruit;
    while (true) {
        cout << "�����: ";
        cin >> fruit;

        // �������� �� ����� � ���
        if (fruit == "�����") {
            break;
        }

        favoriteFruits.push_back(fruit);
    }

    // ���������� ������ �� ��������
    cout << "������ ����� ����������: 1-�-�, 2-�-�" << endl;
   // while (c != '1' || c != '2')
        c = _getch();
    if(c=='1') sort(favoriteFruits.begin(), favoriteFruits.end());
    else sort(favoriteFruits.begin(), favoriteFruits.end(), greater<string>());

    cout << "\n���� ������� ������ � ���������� �������:" << std::endl;
    for (const auto& favoriteFruit : favoriteFruits) {
        cout << favoriteFruit << std::endl;
    }

    cout << "��� ���������. ������ �� ������!" << std::endl;

    return 0;
}