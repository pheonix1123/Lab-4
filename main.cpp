#include <iostream>
#include <cmath>

using namespace std;

// Функції для знаходження периметра
  void RunProc37();
  double RectP(double x1, double y1, double x2, double y2);

// Функції для пошуку меншого та більшого числа
  void RunProc11();
  void Minmax(double &X, double &Y);

// Функції для знаходження місяця та дня
  void RunInt34();
  bool InputNum(int &n);
  int FindMonth(int n);
  int FindDay(int n);
  void PrintResult(int month, int day);

int main()
{
    int menu;

    // Робимо меню для вибору задачі
    cout << "Choose task:" << endl;
    cout << "1 - Proc37" << endl;
    cout << "2 - Proc11" << endl;
    cout << "3 - Integer34" << endl;
    cout << "Your choice: ";
    cin >> menu;

    // Перевіряємо, чи правильно ввели число
    if (cin.fail())
    {
        cout << "Wrong input!" << endl;
        return 0;
    }

    // Запускаємо вибрану задачу
    switch (menu)
    {
        case 1: RunProc37(); break;
        case 2: RunProc11(); break;
        case 3: RunInt34(); break;
        default: cout << "Wrong choice!" << endl;
    }

    return 0;
}

// Proc37
// Вводимо координати трьох прямокутників
  void RunProc37()
{
    double x1, y1, x2, y2;

    cout << "Proc37" << endl;

    cout << "Rectangle 1 (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Перевіряємо введені координати
    if (cin.fail() || x1 < -100 || x1 > 100 ||
        y1 < -100 || y1 > 100 ||
        x2 < -100 || x2 > 100 ||
        y2 < -100 || y2 > 100 ||
        x1 == x2 || y1 == y2)
    {
        cout << "Wrong input!" << endl;
        return;
    }

    cout << "P1 = " << RectP(x1, y1, x2, y2) << endl;

    cout << "Rectangle 2 (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Перевіряємо другий прямокутник
    if (cin.fail() || x1 < -100 || x1 > 100 ||
        y1 < -100 || y1 > 100 ||
        x2 < -100 || x2 > 100 ||
        y2 < -100 || y2 > 100 ||
        x1 == x2 || y1 == y2)
    {
        cout << "Wrong input!" << endl;
        return;
    }

    cout << "P2 = " << RectP(x1, y1, x2, y2) << endl;

    cout << "Rectangle 3 (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Перевіряємо третій прямокутник
    if (cin.fail() || x1 < -100 || x1 > 100 ||
        y1 < -100 || y1 > 100 ||
        x2 < -100 || x2 > 100 ||
        y2 < -100 || y2 > 100 ||
        x1 == x2 || y1 == y2)
    {
        cout << "Wrong input!" << endl;
        return;
    }

    cout << "P3 = " << RectP(x1, y1, x2, y2) << endl;
}

// Знаходимо довжини сторін та периметр
  double RectP(double x1, double y1, double x2, double y2)
{
    double a = abs(x2 - x1);
    double b = abs(y2 - y1);

    return 2 * (a + b);
}

// Proc11
// Вводимо чотири числа та шукаємо найменше і найбільше
  void RunProc11()
{
    double A, B, C, D;

    cout << "Proc11" << endl;
    cout << "Enter A B C D: ";
    cin >> A >> B >> C >> D;

    // Перевіряємо, чи немає помилок у вводі
    if (cin.fail() || A < -100 || A > 100 ||
        B < -100 || B > 100 ||
        C < -100 || C > 100 ||
        D < -100 || D > 100)
    {
        cout << "Wrong input!" << endl;
        return;
    }

    // Порівнюємо числа між собою
    Minmax(A, B);
    Minmax(C, D);
    Minmax(A, C);
    Minmax(B, D);

    cout << "Min = " << A << endl;
    cout << "Max = " << D << endl;
}

// Якщо X більше за Y, міняємо їх місцями
  void Minmax(double &X, double &Y)
{
    if (X > Y)
    {
        double temp = X;
        X = Y;
        Y = temp;
    }
}

// Integer34
// За кількістю днів знаходимо місяць і день
  void RunInt34()
{
    int n;

    cout << "Integer34" << endl;

    // Якщо число правильне, рахуємо результат
    if (InputNum(n))
    {
        int month = FindMonth(n);
        int day = FindDay(n);

        PrintResult(month, day);
    }
}

// Вводимо кількість днів
  bool InputNum(int &n)
{
    cout << "Enter days: ";
    cin >> n;

    // Число повинно бути від 1 до 100
    if (cin.fail() || n < 1 || n > 100)
    {
        cout << "Wrong input!" << endl;
        return false;
    }

    return true;
}

// Рахуємо номер місяця
  int FindMonth(int n)
{
    return (n - 1) / 28 + 1;
}

// Рахуємо номер дня у місяці
  int FindDay(int n)
{
    return (n - 1) % 28 + 1;
}

// Показуємо місяць та день
  void PrintResult(int month, int day)
{
    cout << "Month = " << month << endl;
    cout << "Day = " << day << endl;
}
