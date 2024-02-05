#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include<Windows.h>
using namespace std;
class Joke {
public:
    Joke(string text) : text(text), votes(0), totalRating(0) {}

    void tellJoke() const {
        cout << "����: " << text << endl;
       cout << "������: " << fixed << setprecision(2) << getAverageRating() << " (������: " << votes << ")" << endl;
    }

    void rateJoke(int rating) {
        if (rating >= 1 && rating <= 5) {
            votes++;
            totalRating += rating;
        }
        else {
           cout << "������ ������� ���� �� 1 �� 5!" << endl;
        }
    }

    double getAverageRating() const {
        return (votes > 0) ? static_cast<double>(totalRating) / votes : 0.0;
    }

private:
    string text;
    int votes;
    int totalRating;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list<Joke> jokeList;

    // ��������� ����� �� ������
    jokeList.push_back(Joke("���� ���������� ��� ������ ������? ���� �� ���� ����� ������ �� ����!"));
    jokeList.push_back(Joke("�� ������ ��������� ���� �����������? ���������� �� ����� ����������!"));

    cout << "������� ������� �� �������� ��� ���������� �����!" << endl;
    int  countAppraisers;
    cout << "������ ������� ��������,���������� ����" << endl;
    cin >> countAppraisers;
    // ���������� �����
    for (auto& joke : jokeList) {
        joke.tellJoke();

       
        int userRating;
        for (int i = 0; i < countAppraisers; i++)
        {
            cout << "���� ������ (1-5): ";
            cin >> userRating;

            joke.rateJoke(userRating);
        }
        
    }

    cout << "\n����� � ������� ���������:" <<endl;
    for (const auto& joke : jokeList) {
        if (joke.getAverageRating() >= 4.0) {
            joke.tellJoke();
        }
    }

    return 0;
}