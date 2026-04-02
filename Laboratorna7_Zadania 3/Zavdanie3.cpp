#include <iostream>
#include <string>
#include <vector>
#include <fstream>   
#include <Windows.h>
using namespace std;

struct Student {
    string prizv;
    string name;
    int kurs;
    string grupa;
    int yearBirth;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість студентів: ";
    cin >> n;
    cin.ignore();
    vector<Student> students(n);

 
    for (int i = 0; i < n; i++) {
        cout << "\nСтудент #" << i + 1 << endl;
        cout << "Прізвище: ";
        getline(cin, students[i].prizv);
        cout << "Ім'я: ";
        getline(cin, students[i].name);
        cout << "Курс: ";
        cin >> students[i].kurs;
        cin.ignore();
        cout << "Група: ";
        getline(cin, students[i].grupa);
        cout << "Рік народження: ";
        cin >> students[i].yearBirth;
        cin.ignore();
    }

   
    int youngestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].yearBirth > students[youngestIndex].yearBirth) {
            youngestIndex = i;
        }
    }

    
    cout << "\nНаймолодший студент:" << endl;
    cout << "Прізвище: " << students[youngestIndex].prizv << endl;
    cout << "Ім'я: " << students[youngestIndex].name << endl;
    cout << "Курс: " << students[youngestIndex].kurs << endl;
    cout << "Група: " << students[youngestIndex].grupa << endl;
    cout << "Рік народження: " << students[youngestIndex].yearBirth << endl;

    ofstream Fout("Result.txt");
    if (Fout.is_open()) {
        Fout << "Список студентів:\n";
        for (int i = 0; i < n; i++) {
            Fout << "Студент #" << i + 1 << "\n";
            Fout << "Прізвище: " << students[i].prizv << "\n";
            Fout << "Ім'я: " << students[i].name << "\n";
            Fout << "Курс: " << students[i].kurs << "\n";
            Fout << "Група: " << students[i].grupa << "\n";
            Fout << "Рік народження: " << students[i].yearBirth << "\n\n";
        }

        Fout << "Наймолодший студент:\n";
        Fout << "Прізвище: " << students[youngestIndex].prizv << "\n";
        Fout << "Ім'я: " << students[youngestIndex].name << "\n";
        Fout << "Курс: " << students[youngestIndex].kurs << "\n";
        Fout << "Група: " << students[youngestIndex].grupa << "\n";
        Fout << "Рік народження: " << students[youngestIndex].yearBirth << "\n";
        Fout.close();
        cout << "\nДані записані у файл results.txt" << endl;
    }
    else {
        cout << "Не вдалося відкрити файл для запису!" << endl;
    }

    cout << "\nНатисніть Enter, щоб завершити...";
    cin.ignore();
    cin.get();
    return 0;
}