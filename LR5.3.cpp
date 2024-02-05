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
        cout << "Жарт: " << text << endl;
       cout << "Оцінка: " << fixed << setprecision(2) << getAverageRating() << " (Голосів: " << votes << ")" << endl;
    }

    void rateJoke(int rating) {
        if (rating >= 1 && rating <= 5) {
            votes++;
            totalRating += rating;
        }
        else {
           cout << "Оцінка повинна бути від 1 до 5!" << endl;
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

    // Додавання жартів до списку
    jokeList.push_back(Joke("Чому програмісти так погано сплять? Тому що вони давно звикли до багів!"));
    jokeList.push_back(Joke("Що робить програміст після розставання? Переходить на інший репозиторій!"));

    cout << "Ласкаво просимо до програми для оцінювання жартів!" << endl;
    int  countAppraisers;
    cout << "Введіть кількість учасників,враховуючи себе" << endl;
    cin >> countAppraisers;
    // Оцінювання жартів
    for (auto& joke : jokeList) {
        joke.tellJoke();

       
        int userRating;
        for (int i = 0; i < countAppraisers; i++)
        {
            cout << "Ваша оцінка (1-5): ";
            cin >> userRating;

            joke.rateJoke(userRating);
        }
        
    }

    cout << "\nЖарти з високим рейтингом:" <<endl;
    for (const auto& joke : jokeList) {
        if (joke.getAverageRating() >= 4.0) {
            joke.tellJoke();
        }
    }

    return 0;
}