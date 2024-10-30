#include <iostream>
#include <math.h>
#include <iomanip>
#include <map>
#include <vector>
#include <locale>
#include <cstdlib> // Для функции rand()
#include <ctime>   // Для инициализации генератора случайных чисел

// Функция для создания и заполнения двумерного массива случайными числами
std::vector<std::vector<int>> createRandomMatrix(int n, int m) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 100; // Случайные числа от 0 до 99
        }
    }
    return matrix;
}

// Функция для вывода массива
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            std::cout << elem << "\t";
        }
        std::cout << std::endl;
    }
}

// Функция для поиска минимального и максимального элементов и их индексов
void findMinMax(const std::vector<std::vector<int>>& matrix, int& minVal, int& maxVal, int& minIdx, int& maxIdx) {
    int n = matrix.size();
    int m = matrix[0].size();
    minVal = matrix[0][0];
    maxVal = matrix[0][0];
    minIdx = 0;
    maxIdx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int index = i * m + j; // Преобразование двумерного индекса в одномерный
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minIdx = index;
            }
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxIdx = index;
            }
        }
    }
}

// Функция для вычисления суммы элементов между минимальным и максимальным элементами
int calculateSumBetweenMinMax(const std::vector<std::vector<int>>& matrix, int minIdx, int maxIdx) {
    int n = matrix.size();
    int m = matrix[0].size();
    int sum = 0;

    // Обеспечение правильного порядка индексов
    if (minIdx > maxIdx) {
        std::swap(minIdx, maxIdx);
    }

    // Суммируем элементы от минимального до максимального индексов
    for (int index = minIdx; index <= maxIdx; index++) {
        int row = index / m;    // Преобразование обратно в строку
        int col = index % m;    // Преобразование обратно в столбец
        sum += matrix[row][col];
    }

    return sum;
}


using namespace std;

//cw: first part
double f(int x, int y) {
    return 1 + sin(sqrt(x + 1)) / cos(12 * y - 4);
}

void part1() {
    int x, y;
    cout << "Task 12" << endl << "enter x: ";
    cin >> x;
    cout << "enter y: ";
    cin >> y;
    double res = f(x, y);
    cout << "result: " << setprecision(6) << res;
}


//cw: second part
double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

void part2() {
    //12) площадь треугольника, заданного координатами вершин xl, yl, х2, у2, хЗ, уЗ;
    double x1, y1, x2, y2, x3, y3;
    cout << "enter vertexes of the triangle (x1, y1, x2, y2, x3, y3):" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double area = triangleArea(x1, y1, x2, y2, x3, y3);
    cout << "area: " << area;
}


//cw: third part
bool isMultiple(int num, int A) {
    int digSum = num / 10 + num % 10;
    if (digSum % A == 0) return true;
    else return false;
}

void part3() {
    //12) кратна ли числу А сумма цифр двухзначного числа;
    int A, num;
    cout << "enter a two-digit number: ";
    cin >> num;
    cout << "enter a number: ";
    cin >> A;
    bool res = isMultiple(num, A);

}

void printRes(bool& res, int& num, int& A) {
    res == true
        ? cout << "The sum of the digits of the number " << num << " is a multiple of the number " << A << endl
        : cout << "The sum of the digits of the number " << num << " is not a multiple of the number " << A << endl;
}

void hw001() {
    //hw: Задание 12. Определить, как наименьшим числом купюр можно выдать сумму K руб. (K < 9999), если есть купюры 
    // достоинством 1000 руб., 500 руб., 100 руб., 50 руб.и 10 руб.Оставшуюся мелочь выдать рублями.
    // Инициализируем словарь для хранения количества купюр
    int K;
    cout << "Enter the amount K (K < 9999): ";
    cin >> K;

    if (K >= 9999) {
        cout << "Amount must be less than 9999." << endl;
        return;
    }
    map<string, int> result;

    result["1000 rub. banknote"] = K / 1000;
    K %= 1000;

    result["500 rub. banknote"] = K / 500;
    K %= 500;

    result["100 rub. banknote"] = K / 100;
    K %= 100;

    result["50 rub. banknote"] = K / 50;
    K %= 50;

    result["10 rub. banknote"] = K / 10;
    K %= 10;

    result["Remaining rubs"] = K;

    for (const auto& pair : result) {
        cout << pair.first << ": " << pair.second << endl;
    }
}



bool isTwoDigit(int num) {
    return num / 10 < 10;
}

int reverseNum(int num) {
    return num / 10 + num % 10 * 10;
}

int f(int x) {

    if (isTwoDigit(x)) return reverseNum(x);
    else return x;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    //part1();
    //part2();
    ////part3();
    ////12) кратна ли числу А сумма цифр двухзначного числа;
    /*int A, num;
    cout << "enter a two-digit number: ";
    cin >> num;
    cout << "enter a number: ";
    cin >> A;
    bool res = isMultiple(num, A);
    printRes(res, num, A);*/
    //hw001();


    //lesson002
    /*int userNum;
    cout << "Enter a number: ";
    cin >> userNum;
    cout << f(userNum);*/


    //12. Дан двумерный массив размером n * m, заполненный случайными числами.Найти сумму его элементов, 
    // расположенных между максимальным и минимальным элементами(включая оба этих числа).
    srand(time(0)); // Инициализация генератора случайных чисел

    int n, m;
    std::cout << "Введите количество строк (n) и столбцов (m) массива: ";
    std::cin >> n >> m;

    //// Создание и заполнение массива
    std::vector<std::vector<int>> matrix = createRandomMatrix(n, m);

    //// Вывод массива
    std::cout << "Массив: " << std::endl;
    printMatrix(matrix);

    //// Поиск минимального и максимального элементов и их индексов
    int minVal, maxVal, minIdx, maxIdx;
    findMinMax(matrix, minVal, maxVal, minIdx, maxIdx);

    //// Вычисление суммы между минимальным и максимальным элементами
    int sum = calculateSumBetweenMinMax(matrix, minIdx, maxIdx);

    //// Вывод результатов
    std::cout << "Минимальный элемент: " << minVal << std::endl;
    std::cout << "Максимальный элемент: " << maxVal << std::endl;
    std::cout << "Сумма элементов между минимальным и максимальным: " << sum << std::endl;


    return 0;
}

