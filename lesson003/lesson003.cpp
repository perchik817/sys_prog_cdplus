#include <iostream>
#include <locale>
#include <string>
#include <cmath>
#include <iomanip>

std::string pointLocation(float x, float y) {
    const float minX = 0, minY = 0;
    const float maxX = 40, maxY = 40;
    if ((x == minX || x == maxX) && (y >= minY && y <= maxY) ||
        (y == minY || y == maxY) && (x >= minX && x <= maxX)) return "на границе";
    else if (x > minX && x < maxX && y > minY && y < maxY) return "да";
    else return "нет";
}

void firstPart() {
    //I. Дана точка на плоскости с координатами (х, у). Составить программу, которая выдает одно из сообщений «Да», «Нет», 
    // «На границе» в зависимости от того, лежит ли точка внутри заштрихованной области, вне заштрихованной области или на 
    // ее границе.Области задаются графически следующим образом :
    float x, y;
    std::cout << "Введите координаты точек x y: ";
    std::cin >> x >> y;
    std::cout << "x\t" << "y\t" << "ответ" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::string answer = pointLocation(x, y);
    std::cout << x << "\t" << y << "\t" << answer << std::endl;
}

void printNames(const std::string names[]) {
    for (int i = 0; i < names->length(); i++) {
        std::cout << names[i] << " ";
    }
    std::cout << std::endl;
}

void secondPart() {
    // 12. Дан пол человека: м — мужчина, ж — женщина. Вывести на экран возможные мужские и женские имена в зависимости от введенного пола
    std::string gender;
    std::string maleNames[] = { "Алексей", "Дмитрий", "Михаил", "Иван", "Сергей" };
    std::string femaleNames[] = { "Анна", "Елена", "Мария", "Ольга", "Татьяна" };

    std::cout << "Введите пол (м - мужчина, ж - женщина): ";
    std::cin >> gender;
    if (gender == "m") {
        std::cout << "Возможные мужские имена: ";
        printNames(maleNames);
    }
    else if (gender == "f") {
        std::cout << "Возможные женские имена: ";
        printNames(femaleNames); 
    }
    else {
        std::cout << "Некорректный ввод! Введите 'm' или 'f'.\n";
    }
}

void thirdPart() {
    //12) все целые числа из диапазона отАдо В (А <В), оканчивающиесяналюбую четную цифру;

    int a, b;
    std::cout << "enter a and b: ";
    std::cin >> a >> b;
    if (!(a % 2 == 0)) {
        std::cout << a << " ";
        a++;
    }
    for (a; a <= b; a += 2) {
        std::cout << a << std::endl;
    }
}

void fourthPart() {
    for (int i = 1; i <= 5; i++, std::cout << std::endl) // внешний цикл
        for (int j = i; j >= 1; j--)
            std::cout << j << "\t";
}

float f(float x) {
    if ((pow(x, 4) - 1) <= 0 || (1 + x) <= 0) {
        throw std::domain_error("Function is undefined at this point.");
    }
    return log10(pow(x, 4) - 1) * log10(1 + x);
}
void fifthPart() {
    //V.Построить таблицу значений функции у = f(x) для х е[а, b] с шагом h.Если в некоторой точке х функция не определена, 
    // вывести на экран сообщение об этом.
    float a, b, h;
    std::cout << "Enter start (a): ";
    std::cin >> a;
    std::cout << "Enter end (b): ";
    std::cin >> b;
    std::cout << "Enter step (h): ";
    std::cin >> h;

    std::cout << "x\tf(x)\n";
    for (float x = a; x <= b; x += h) {
        try {
            float result = f(x);
            std::cout << x << "\t" << std::fixed << std::setprecision(5) << result << "\n";
        }
        catch (const std::domain_error& e) {
            std::cout << x << "\t" << "Function is undefined\n";
        }
    }
}

double func(double x) {
    double y;
    if (x < 0) return y = 0;
    else if (x > 0 && x != 1) return pow(x, 2) + 1;
    else if (x == 1) return y = 1;
}

void printTable(double& a, double& b, double& h) {
    //std::setw(10) - это означает, что следующий элемент, который будет выведен, будет занимать минимум 
    // 10 символов в ширину. Если строка или число короче этого значения, вывод будет дополнен пробелами 
    // слева. Если строка длиннее, она будет выведена полностью, без обрезки.
    std::cout << std::setw(24) << "x" << std::setw(24) << "y" << std::endl;
    std::cout << "--------------------" << std::endl;

    for (double x = a; x <= b; x += h) {
        double y = func(x);
        std::cout << std::setw(24) << x << std::setw(24) << y << std::endl;
    }
}
void sixthPart() {
    //VI. Построить таблицу значений функции у = f(x) для х in [а, b] с шагом h.
    //        0, если х<0;
    //12. у = х^2 + 1, если х>0 и x!= 1;
    //        1, если х = 1
    double a, b, h;
    std::cout << "Введите a (начало диапазона): ";
    std::cin >> a;
    std::cout << "Введите b (конец диапазона): ";
    std::cin >> b;
    std::cout << "Введите h (шаг): ";
    std::cin >> h;
    if (h == 0) {
        std::cout << "Шаг h не может быть равен нулю!" << std::endl;
        return;
    }
    else {
        printTable(a, b, h);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //firstPart();
    //secondPart();
    //thirdPart();
    //fourthPart();
    //fifthPart();
    //sixthPart();
    return 0;
}
