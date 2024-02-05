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
    cout << "Ласкаво просимо до гри 'Сортування фруктів'!" << std::endl;
    cout << "Введіть свої улюблені фрукти (введіть 'кінець', щоб завершити введення):" << std::endl;

    string fruit;
    while (true) {
        cout << "Фрукт: ";
        cin >> fruit;

        // Перевірка на вихід з гри
        if (fruit == "кінець") {
            break;
        }

        favoriteFruits.push_back(fruit);
    }

    // Сортування фруктів за алфавітом
    cout << "Оберіть метод сортування: 1-А-Я, 2-Я-А" << endl;
   // while (c != '1' || c != '2')
        c = _getch();
    if(c=='1') sort(favoriteFruits.begin(), favoriteFruits.end());
    else sort(favoriteFruits.begin(), favoriteFruits.end(), greater<string>());

    cout << "\nВаші улюблені фрукти в алфавітному порядку:" << std::endl;
    for (const auto& favoriteFruit : favoriteFruits) {
        cout << favoriteFruit << std::endl;
    }

    cout << "Гра завершена. Дякуємо за участь!" << std::endl;

    return 0;
}