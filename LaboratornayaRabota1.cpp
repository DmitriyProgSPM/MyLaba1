// Лабораторная работа №1
#include<iostream>
int main()
{
	setlocale(0, "");
	// 1 Задание
	// Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных 
	// со спецификаторами и без: int, short int, long int, float, double, long double, char и bool.
	std::cout << "размер типа int:         ";
	std::cout << sizeof(int) << std::endl;
	std::cout << "размер типа short int:   ";
	std::cout << sizeof(short int) << std::endl;
	std::cout << "размер типа long int:    ";
	std::cout << sizeof(long int) << std::endl;
	std::cout << "размер типа float:       ";
	std::cout << sizeof(float) << std::endl;
	std::cout << "размер типа double:      ";
	std::cout << sizeof(double) << std::endl;
	std::cout << "размер типа long double: ";
	std::cout << sizeof(long double) << std::endl;
	std::cout << "размер типа char:        ";
	std::cout << sizeof(char) << std::endl;
	std::cout << "размер типа bool:        ";
	std::cout << sizeof(bool) << std::endl;

	// 2 Задание
	// Вывести на экран двоичное представление в памяти (все разряды) целого числа. При выводе 
	// необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом.
	int a;
	int mask = 1 << 31;
	std::cout << "Введите целое число в диапазоне - 128 : 127" << std::endl;
	std::cin >> a;
	for (int i = 0; i < 32; i++)
	{
		if (mask&a)
			std::cout << 1;
		else
			std::cout << 0;
		a <<= 1;
		if (i == 0)
			std::cout << " ";
	}

	std::cout << "\n";

	// 3 Задание
	// Вывести на экран двоичное представление в памяти (все разряды) типа float. При выводе 
	// необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок.
	union {
		float b = 3.14;
		int c;
	}bc;
	for (int i = 0; i < 32; i++)
	{
		if (mask&bc.c)
			std::cout << 1;
		else
			std::cout << 0;
		bc.c <<= 1;
		if (i == 0 || i == 10)
			std::cout << " ";
	}

	std::cout << "\n";

	// 4 Задание
	// Вывести на экран двоичное представление в памяти (все разряды) типа double. 
	// При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок.
	union
	{
		int arr[2]; // Применяем массив из двух int, под который будет отведено 8 байт.
		double k;
	};
	unsigned int doublemask = 1 << 31;
	std::cout << "Вывод на экран двоичного представления в памяти числа типа double , Введите число: ";
	std::cin >> k; // Вводим число типа double
	std::cout << " Результат: ";
	for (int l = 0; l <= 31; l++)
	{
		if (l == 1 || l == 12) // Визуально обозначаем знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок. Для double под мантиссу отводится 52 бита, под экспоненту – 11, под знак – 1
		{
			std::cout << " ";
		}
		putchar(arr[1] & doublemask ? '1' : '0');
		arr[1] <<= 1;
	}
	for (int l = 0; l <= 31; l++)
	{
		putchar(arr[0] & doublemask ? '1' : '0');
		arr[0] <<= 1;
	}
	std::cout << "\n";














	return 0;
}

//https://github.com/DmitriyProgSPM/MyLaba1/blob/main/%D0%9E%D1%82%D1%87%D1%91%D1%82%20%D0%BF%D0%BE%20Lab1.docx      ОТЧЁТ
