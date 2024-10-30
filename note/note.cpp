/*
В а р и а н т 1 2
Описать структуру с именем NOTE, содержащую следующие поля:
• фамилия, имя;
• номер телефона;
• дата рождения (массив из трех чисел).
Написать программу, выполняющую следующие действия:
• ввод с клавиатуры данных в массив, состоящий из восьми элементов типа NOTE
(записи должны быть упорядочены по дате рождения);
• вывод на экран информации о человеке, номер телефона которого введен с клавиатуры
(если такого нет, вывести соответствующее сообщение).
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <locale>
#include <iomanip> 

using namespace std;

struct Note {
    string lastName;
    string name;
    string phoneNum;
    int birthDate[3];
};

// Чтение записей из файла
vector<Note> loadNotes(const string& filename) {
    vector<Note> notes;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        Note note;
        stringstream ss(line);
        ss >> note.lastName >> note.name >> note.phoneNum
            >> note.birthDate[0] >> note.birthDate[1] >> note.birthDate[2];
        notes.push_back(note);
    }
    file.close();
    return notes;
}

// Запись записей в файл
void saveNotes(const string& filename, const vector<Note>& notes) {
    ofstream file(filename, ios::app); // Открываем в режиме добавления
    for (const auto& note : notes) {
        file << note.lastName << " " << note.name << " " << note.phoneNum << " "
            << note.birthDate[0] << " " << note.birthDate[1] << " " << note.birthDate[2] << endl;
    }
    file.close();
}

// Добавление записи
void addNote(vector<Note>& notes, const string& filename) {
    if (notes.size() >= 8) {
        cout << "Массив записей полон (8 записей)." << endl;
        return;
    }

    Note note;
    cout << "Введите фамилию: ";
    cin >> note.lastName;
    cout << "Введите имя: ";
    cin >> note.name;
    cout << "Введите номер телефона: ";
    cin >> note.phoneNum;
    cout << "Введите дату рождения (DD MM YYYY): ";
    cin >> note.birthDate[0] >> note.birthDate[1] >> note.birthDate[2];

    notes.push_back(note);

    // Запись новой записи в файл
    saveNotes(filename, { note });
    cout << "Запись добавлена!" << endl;
}

// Поиск записи по фамилии
void findByLastName(const vector<Note>& notes, const string& lastName) {
    bool found = false;
    for (const auto& note : notes) {
        if (note.lastName == lastName) {
            cout << setw(15) << left << "Фамилия"
                << setw(10) << left << "Имя"
                << setw(15) << left << "Телефон"
                << "Дата рождения" << endl;
            cout << setw(15) << left << note.lastName
                << setw(10) << left << note.name
                << setw(15) << left << note.phoneNum
                << note.birthDate[0] << "." << note.birthDate[1] << "." << note.birthDate[2] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Запись с фамилией " << lastName << " не найдена." << endl;
    }
}

// Удаление записи
void deleteNote(vector<Note>& notes, const string& lastName) {
    auto it = remove_if(notes.begin(), notes.end(), [&](const Note& note) {
        return note.lastName == lastName;
        });

    if (it != notes.end()) {
        notes.erase(it, notes.end());
        // Перезаписываем файл без удаленной записи
        ofstream file("note.txt");
        for (const auto& note : notes) {
            file << note.lastName << " " << note.name << " " << note.phoneNum << " "
                << note.birthDate[0] << " " << note.birthDate[1] << " " << note.birthDate[2] << endl;
        }
        file.close();
        cout << "Запись удалена." << endl;
    }
    else {
        cout << "Запись с фамилией " << lastName << " не найдена." << endl;
    }
}

// Сортировка по дате рождения
void sortByBirthDate(vector<Note>& notes) {
    sort(notes.begin(), notes.end(), [](const Note& a, const Note& b) {
        if (a.birthDate[2] != b.birthDate[2]) return a.birthDate[2] < b.birthDate[2];
        if (a.birthDate[1] != b.birthDate[1]) return a.birthDate[1] < b.birthDate[1];
        return a.birthDate[0] < b.birthDate[0];
        });
    cout << "Записи отсортированы по дате рождения." << endl;
}

void displayNotes(const vector<Note>& notes) {
    cout << setw(15) << left << "Фамилия"
        << setw(10) << left << "Имя"
        << setw(15) << left << "Телефон"
        << "Дата рождения" << endl;

    for (const auto& note : notes) {
        cout << setw(15) << left << note.lastName
            << setw(10) << left << note.name
            << setw(15) << left << note.phoneNum
            << note.birthDate[0] << "." << note.birthDate[1] << "." << note.birthDate[2] << endl;
    }
}

// Основное меню программы
void start(const string& filename) {
    vector<Note> notes = loadNotes(filename);
    int choice;
    bool isRunning = true;
    while (isRunning) {
        cout << "=========МЕНЮ========="
            << "\n1. Добавить запись"
            << "\n2. Поиск записи по фамилии"
            << "\n3. Удалить запись"
            << "\n4. Сортировка по дате рождения"
            << "\n5. Вывести все записи"
            << "\n6. Выход"
            << "\nВаш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addNote(notes, filename);
            break;
        case 2: {
            string lastName;
            cout << "Введите фамилию для поиска: ";
            cin >> lastName;
            findByLastName(notes, lastName);
            break;
        }
        case 3: {
            string lastName;
            cout << "Введите фамилию для удаления: ";
            cin >> lastName;
            deleteNote(notes, lastName);
            break;
        }
        case 4:
            sortByBirthDate(notes);
            displayNotes(notes);  // Показываем отсортированные записи
            break;
        case 5:
            displayNotes(notes);
            break;
        case 6:
            cout << "Выход..." << endl;
            isRunning = false;
            break;
        default:
            cout << "Неверный выбор, попробуйте снова." << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const string filename = "note.txt";
    start(filename);
    return 0;
}
