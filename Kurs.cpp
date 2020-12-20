// Kurs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <cctype>
#include <conio.h>

extern void Laba1();
extern void Laba2();
extern void Lab3();
extern void Laba4(std::list<std::string> text);
extern std::list<std::string> ReadStream(std::istream& source);

int Menu()
{

	std::cout << std::endl << "Press the digit from '1' to '4' to select a laboratory work or press 'Q' tu quite"
		<< std::endl << "\t1 - Laboratory work #1"
		<< std::endl << "\t2 - Laboratory work #2"
		<< std::endl << "\t3 - Laboratory work #3"
		<< std::endl << "\t4 - Laboratory work #4"
		<< std::endl << "\tQ - Quite"
		<< std::endl;

	while (true)
	{
		while (!_kbhit());
		char key = std::tolower(_getch());
		if (key == 'q')
 			return 0;
		if (key >= '1' && key <= '4')
			return key - '0';
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	while (auto m = Menu())
	{
		switch (m)
		{
		case 1:
			Laba1();
			break;
		case 2:
			Laba2();
			break;
		case 3:
			Lab3();
			break;
		case 4:
		{
			std::cout << "Type the text, please:";
			auto text = ReadStream(std::cin);
			Laba4(text);
			break;
		}
		}
	}
}

https://github.com/DmitriyProgSPM/MyLaba1/blob/main/%D0%9A%D1%83%D1%80%D1%81%D0%BE%D0%B2%D0%B0%D1%8F.docx ОТЧЁТ
