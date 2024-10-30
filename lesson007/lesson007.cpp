#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <locale>

void firstTask() {
    std::string str1 = "кошка   ";
    std::string str2 = "кошка";

    // Compare the strings
    if (str1 == str2) {
        std::cout << "\"" << str1 << "\" == \"" << str2 << "\" (строки равны)" << std::endl;
    }
    else if (str1 < str2) {
        std::cout << "\"" << str1 << "\" < \"" << str2 << "\" (первая строка меньше второй)" << std::endl;
    }
    else {
        std::cout << "\"" << str1 << "\" > \"" << str2 << "\" (первая строка больше второй)" << std::endl;
    }
}

std::string mergeStrings(int N1, int N2, const std::string& S1, const std::string& S2) {
    // Проверка на корректность ввода
    if (N1 > S1.length() || N2 > S2.length() || N1 < 0 || N2 < 0) {
        throw std::invalid_argument("N1 и N2 должны быть положительными и не превышать длину соответствующих строк.");
    }

    std::string newString = S1.substr(0, N1) + S2.substr(S2.length() - N2, N2);

    return newString;
}
void secondTask() {
    int N1, N2;
    std::string S1, S2;

    std::cout << "Введите целое положительное число N1 (длина символов из S1): ";
    std::cin >> N1;
    std::cout << "Введите целое положительное число N2 (длина символов из S2): ";
    std::cin >> N2;
    std::cin.ignore(); // Игнорируем символ новой строки после ввода числа
    std::cout << "Введите строку S1: ";
    std::getline(std::cin, S1);
    std::cout << "Введите строку S2: ";
    std::getline(std::cin, S2);

    try {
        std::string newString = mergeStrings(N1, N2, S1, S2);
        std::cout << "Новая строка: " << newString << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return;
    }
}

void thirdTask() {
    std::string message;
    char letter;

    // Ввод сообщения
    std::cout << "Введите текстовое сообщение (в конце ставится точка): ";
    std::getline(std::cin, message);

    // Ввод буквы
    std::cout << "Введите букву для поиска: ";
    std::cin >> letter;

    // Удаление точки в конце сообщения, если она есть
    if (message.back() == '.') {
        message.pop_back();
    }

    // Разделение сообщения на слова
    std::istringstream stream(message);
    std::string word;
    std::vector<std::string> result;

    while (stream >> word) {
        // Проверка на наличие буквы в слове
        if (word.find(letter) != std::string::npos) {
            result.push_back(word);
        }
    }

    // Вывод результатов
    std::cout << "Слова, содержащие букву '" << letter << "':" << std::endl;
    for (const auto& w : result) {
        std::cout << w << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    //firstTask();
    secondTask();
    //thirdTask();

    return 0;
}