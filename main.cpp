// simple calculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <cmath>
#include <vector>
#include <limits>
#include <conio.h>

using namespace std; // что бы не писать лишний раз std::cout

vector<string> operations = {
	"Сумма",
	"Вычитание",
	"Деление",
	"Умножение",
	"Возведение в степень",
	"Возведение в квадрат",
	"Вычисление квадратного корня",
	"Преобразование градуса в оренбург"
};

// выносение void через extern, ибо он идет после функции main
extern void do_calculations(int op);

// создаем временную переменную для записи введенной пользователем цифры
int op;

int main()
{
	// устанавливаем русский язык для вывода в консоль
	setlocale(LC_ALL, "Russian");
	// вывод надписи в консоль
	cout << "Введите интересующую вас операцию" << std::endl;
	// список возможных операций
	for (int i = 0; i < operations.size(); i++)
	{
		cout << "[" << i << "] " << operations.at(i) << std::endl;
	}
	// получаем введенную пользователем цифру
	cin.ignore(DBL_MAX, '\n');
	cin >> op;
	// мы делаем расчёт в другом методе, потому что так код будет более читабельным и удобным
	do_calculations(op);

	return 1;
}

// я вынес глобальную переменную PI, что бы не делать ненужных определений в кейсе, это мешает читабельности кода
const double PI = 3.14159265358979323846;

void do_calculations(int op)
{
	// мы создаем обработчик try, что бы отловить ошибку и не произошел краш
	try
	{
		switch (op)
		{
		case 0:
		{
			double nums[2];
			cout << "Введите два числа: " << std::endl;
			cin >> nums[0] >> nums[1];
			cout << "Результат: " << (nums[0] + nums[1]);
		}
		break;
		case 1:
		{
			double nums[2];
			cout << "Введите два числа: " << std::endl;
			cin >> nums[0] >> nums[1];
			cout << "Результат: " << (nums[0] - nums[1]);
		}
		break;
		case 2:
		{
			double nums[2];
			cout << "Введите два числа: " << std::endl;
			cin >> nums[0] >> nums[1];
			cout << "Результат: " << (nums[0] * nums[1]);
		}
		break;
		case 3:
		{
			double nums[2];
			cout << "Введите два числа: " << std::endl;
			cin >> nums[0] >> nums[1];
			cout << "Результат: " << (nums[0] / nums[1]);
		}
		break;
		case 4:
		{
			double nums[2];
			cout << "Введите число и степень: " << std::endl;
			cin >> nums[0] >> nums[1];
			cout << "Результат: " << (pow(nums[0], nums[1]));
		}
		break;
		case 5:
		{
			double num;
			cout << "Введите число: " << std::endl;
			cin >> num;
			cout << "Результат: " << (pow(num, 2));

		}
		break;
		case 6:
		{
			double num;
			cout << "Введите число: " << std::endl;
			cin >> num;
			cout << "Результат: " << (sqrt(num));
		}
		break;
		case 7:
		{
			double radians, degrees, minutes, seconds;
			cout << "Введите число в формате радиан: " << std::endl;
			cin >> radians;
			degrees = radians * 180 / PI;
			minutes = (degrees - floor(degrees)) * 60;
			seconds = (minutes - floor(minutes)) * 60;
			cout << "Результат в градусах: " << floor(degrees) << "° " << floor(minutes) << "' " << seconds << "''" << endl;
		}
		break;
		default:
			cout << "Введен неправильный индекс, введите число нужной операции от 0 до " << (operations.size() - 1);
			break;
		}
	}
	catch (std::exception ex)
	{
		cout << "Произошла ошибка, возможно неправильно введены аргументы";
	};
	_getch();
}