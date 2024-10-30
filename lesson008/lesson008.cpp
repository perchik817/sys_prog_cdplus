#include <iostream>
#include <string>
#include <locale>
#include <vector>
using namespace std;

//стр 181 - глава 8 - рекур. функ. перегрузка 
// 
// II. Разработать рекурсивную функцию, возвращающую значение
//12) для вычисления суммы цифр в строке; с помощью данной функции определить, в каком из двух предложений сумма цифр больше

double recursiveFraction(double x, int n) {
    if (n == 1) {
        return x;  
    }
    return x / (n + recursiveFraction(x, n - 1));
}

int sumOfDigits(const string& str) {
    int sum = 0;
    for (char ch : str) {
        if (isdigit(ch)) {
            sum += ch - '0';  // Преобразование символа в его числовое значение
        }
    }
    return sum;
}

//III. Разработать рекурсивную функцию, не возвращающую значений
//12. Дано натуральное четное число п. Разработать рекурсивную функцию для вывода на экран следующей картинки :
void printPattern(int n) {

    // Вывод верхней части шаблона

    for (int i = 0; i < n; i++) {

        std::cout << " ";
    }

    std::cout << "*" << "------" << "*" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << " ";
    }
    std::cout << "-*" << "*--*" << "*-" << std::endl;


    // Вывод нижней части шаблона

    for (int i = 0; i < n; i++) {

        std::cout << " ";

    }

    std::cout << "--*" << "**" << "*--" << std::endl;


    // Вывод средней части шаблона

    for (int i = 0; i < n; i++) {

        std::cout << " ";

    }

    std::cout << "-*" << "*--*" << "*-" << std::endl;


    // Вывод нижней части шаблона

    for (int i = 0; i < n; i++) {

        std::cout << " ";

    }

    std::cout << "*" << "------" << "*" << std::endl;

    std::cout << std::endl;

}

//IV. Используя механизм перегрузки функций, разработайте две версии функции F, заголовки которых выглядят следующим образом :
//1) float F(float х);
//2) void F(float x, float& y)
//Продемонстрируйте работу данных функций на примерах.
//Функции у = / (х)использовать из параграфа «Упражнения»(VI) к гл. 3
//0, еслих < 0;
//у = < х2 + 1., если х>0 и х ^ 1;
//1, если х = 1.
// Первая версия функции F, возвращающая float

float F(float x) {
    if (x < 0) {
        return 0.0; // 0, если x < 0
    }
    else if (x == 1) {
        return 1.0; // 1, если x = 1
    }
    else {
        return (x * x) + 1; // y = x^2 + 1, если x > 0 и x != 1
    }
}

// Вторая версия функции F, принимающая ссылку
void F(float x, float& y) {
    if (x < 0) {
        y = 0.0; // 0, если x < 0
    }
    else if (x == 1) {
        y = 1.0; // 1, если x = 1
    }
    else {
        y = (x * x) + 1; // y = x^2 + 1, если x > 0 и x != 1
    }

}

//V. Использование функций-шаблонов: для работы с двумерными массивами арифметических типов данных разработать шаблоны ввода и вывода массива,
//а также шаблон для решения основной задачи. 12. Подсчитать сумму элементов, расположенных на побочной диагонали.
// Шаблон для ввода двумерного массива
template <typename T>
void inputArray(std::vector<std::vector<T>>& array, int rows, int cols) {
    std::cout << "Введите элементы массива (" << rows << " x " << cols << "):" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> array[i][j];
        }
    }
}

// Шаблон для вывода двумерного массива
template <typename T>
void outputArray(const std::vector<std::vector<T>>& array) {
    std::cout << "Элементы массива:" << std::endl;
    for (const auto& row : array) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

// Шаблон для подсчета суммы элементов на побочной диагонали
template <typename T>
T sumSecondaryDiagonal(const std::vector<std::vector<T>>& array) {
    T sum = 0;
    int rows = array.size();
    int cols = array[0].size();

    for (int i = 0; i < rows; ++i) {
        sum += array[i][cols - 1 - i]; // Элементы побочной диагонали
    }

    return sum;
}

void secondPart() {
    double x;
    int n;

    cout << "Введите x для дроби: ";
    cin >> x;
    cout << "Введите n для дроби: ";
    cin >> n;

    double result = x / (1 + recursiveFraction(x, n));
    cout << "Результат дроби: " << result << endl;

    cin.ignore(); // Очистка буфера ввода после cin
    string sentence1, sentence2;

    cout << "Введите первое предложение: ";
    getline(cin, sentence1);
    cout << "Введите второе предложение: ";
    getline(cin, sentence2);

    int sum1 = sumOfDigits(sentence1);
    int sum2 = sumOfDigits(sentence2);

    cout << "Сумма цифр в первом предложении: " << sum1 << endl;
    cout << "Сумма цифр во втором предложении: " << sum2 << endl;

    if (sum1 > sum2) {
        cout << "Сумма цифр в первом предложении больше." << endl;
    }
    else if (sum1 < sum2) {
        cout << "Сумма цифр во втором предложении больше." << endl;
    }
    else {
        cout << "Суммы цифр в обоих предложениях равны." << endl;
    }
}

void thirdPart() {
    int n;
    std::cout << "Введите количество пробелов: ";
    std::cin >> n;
    printPattern(n);
}

void fourthPart() {
    float x1 = -5.0;
    float result1 = F(x1);
    std::cout << "F(" << x1 << ") = " << result1 << std::endl;

    float x2 = 0.5;
    float result2 = F(x2);
    std::cout << "F(" << x2 << ") = " << result2 << std::endl;
    float x3 = 1.0;
    float result3 = F(x3);
    std::cout << "F(" << x3 << ") = " << result3 << std::endl;

    // Примеры использования второй версии функции F
    float x4 = -3.0;
    float result4;
    F(x4, result4);
    std::cout << "F(" << x4 << ", result) = " << result4 << std::endl;
    float x5 = 2.0;
    float result5;
    F(x5, result5);
    std::cout << "F(" << x5 << ", result) = " << result5 << std::endl;
}

void fifthPart() {

    int rows, cols;
    std::cout << "Введите количество строк и столбцов массива: ";
    std::cin >> rows >> cols;
    std::vector<std::vector<double>> array(rows, std::vector<double>(cols));
    inputArray(array, rows, cols);
    outputArray(array);
    int sum = sumSecondaryDiagonal(array);
    std::cout << "Сумма элементов на побочной диагонали: " << sum << std::endl;

}

int main() {
    setlocale(LC_ALL, "Russian");

    //secondPart();
    //thirdPart();
    fourthPart();
    //fifthPart();
    return 0;
}
