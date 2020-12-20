//Лабораторная работа 2
#include <iostream> 
#include <cstdlib> 
#include <chrono>
using namespace std;
using namespace chrono;
int main()
{
	setlocale(0, "");

	//1 задание. 
	//Создает целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99.

	const int N = 100;
	int arr[N];
	int minInUnsorted;
	int maxInUnsorted;
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 199 - 99;//Заполняем массив рандомными числами
	}
	cout << " Элементы массива, с которыми мы будем дальше работать: ";
	for (int i = 0; i < 100; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;

	//2 задание.
	//Отсортировать заданный в пункте 1 элементы массива […] сортировкой (от меньшего к большему). 
	//Определить время, затраченное на сортировку, используя библиотеку chrono.

	auto insertSortTime = system_clock::now();//Запускаем время сортировки 
	for (int l = 1; l < N; l++)
	{
		int z = arr[l];
		int x = l - 1;
		while (x >= 0 && arr[x] > z)
		{
			arr[x + 1] = arr[x];
			arr[x] = z;
			x--;

		}
	}
	auto endCountingTime = system_clock::now();//Останавливаем время сортировки
	duration<double> elapsed = endCountingTime - insertSortTime;//Находим время сортировки 
	cout << " Отсортированный массив: ";
	for (int j = 0; j < N; ++j)
	{
		std::cout << arr[j] << ' ';
	}
	cout << "\n";
	cout << std::fixed << "Отсортировала методом insert за : " << elapsed.count() << " секунд" << "\n";

	//3 задание.
	//Найти максимальный и минимальный элемент массива. 
	//Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono.

// Найдем минимальный элемент отсортированного массива и замерим время его поиска
	auto startToSearchMinimum = system_clock::now();//Начинаем отсчет времени поиска миниамльного значения массива
	cout << "Минимальный элемент отсортированного массива: " << arr[0] << "\n";//Выводим  минимальный элемент массива
	auto finishSearchingMinimum = system_clock::now();//Останавливаем время поиска минимального массива
	duration<double> timeForSearchMinimum = finishSearchingMinimum - startToSearchMinimum;//находим время поиска
	cout << fixed << "Время на поиск минимального элемента в отсортированном массиве: " << timeForSearchMinimum.count() << " секунд" "\n";

	// Найдем максимальный элемент отсортированного массива и замерим время его поиска
	auto startToSearchMaximum = system_clock::now();
	cout << "Максимальный элемент отсортированного массива: " << arr[99] << "\n";
	auto finishSearchingMaximum = system_clock::now();
	duration<double> timeForSearchMaximum = finishSearchingMaximum - startToSearchMaximum;
	cout << fixed << "Время на поиск максимального элемента в отсортированном массиве: " << timeForSearchMaximum.count() << " секунд" "\n";
	cout << "\n";



	// Найдем минимальный  и максимальный элемент неотсортированного массива
	minInUnsorted = arr[0];
	maxInUnsorted = arr[0];

	// Начало замера времени поиска Мин и Макс элементов в неотсортированном массиве
	auto startToSearchMaxAndMinInUnsorted = system_clock::now();
	for (int f = 0; f < 100; f++)
	{
		if (arr[f] <= minInUnsorted)
		{
			minInUnsorted = arr[f];
		}
		if (arr[f] >= maxInUnsorted)
		{
			maxInUnsorted = arr[f];
		}
	}
	// Конец замера времени поиска Мин и Макс элементов в неотсортированном массиве
	auto endToSearchMaxAndMinInUnsorted = system_clock::now();
	duration<double> searchMaxAndMinInUnsorted = endToSearchMaxAndMinInUnsorted - startToSearchMaxAndMinInUnsorted;
	cout << "Минимальный элемент неотсортированного массива: " << minInUnsorted << "\n";
	cout << "Максимальный элемент неотсортированного массива: " << maxInUnsorted << "\n";
	cout << fixed << "Время на поиск минимального элемента в неотсортированном массиве: " << searchMaxAndMinInUnsorted.count() << " секунд" "\n";
	cout << fixed << "Время на поиск максимального элемента в неотсортированном массиве: " << searchMaxAndMinInUnsorted.count() << " секунд" "\n";
	cout << "\n";

	//4 задание.
	//Выводит среднее значение (если необходимо, число нужно округлить) максимального и минимального значения. 
	//Выводит индексы всех элементов, которые равны этому значению, и их количество.
	   // Выведем среднее значение между максимум и минимум
	int middle = (arr[0] + arr[99]) / 2;
	cout << "Среднее значение максимального и минимального числа: " << middle << "\n";
	cout << "\n";
	// Ищем в массиве числа, равные среднему значению
	int znach = 0;
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] == middle)
		{
			znach += 1;
			cout << "Равное значение в массиве на позиции " << i << "\n";
			cout << "Всего таких в массиве " << znach << "\n";
			cout << "\n";
		}
	}
	//5 задание.
	//Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем.

	cout << "Для поиска элементов в отсортированном массиве, которые меньше числа a, введите a: ";
	int a, znaschmen = 0;
	cin >> a;
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] < a)
		{
			znaschmen += 1;//Счётчик
		}
	}
	cout << "Меньше числа a: " << znaschmen << " элементов";
	cout << "\n";

	//6 задание.
	//Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем.

	cout << "Для поиска элементов в отсортированном массиве, которые меньше больше b, введите b: ";
	int b, znaschbol = 0;
	cin >> b;
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] > b)
		{
			znaschbol += 1;
		}
	}
	cout << "Больше числа b: " << znaschbol << " элементов";
	cout << "\n";

	//7 задание.
	//Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве. 
	//Реализуйте алгоритм бинарного поиска. Сравните скорость его работы с обычным перебором. 
	int numberpol;
	bool ifFound = false;
	int minInd = 0;
	int maxInd = 99;
	int binInd = (maxInd + minInd) / 2;

	cout << "Какое число необходимо найти в массиве? ";
	cin >> numberpol;

	// Пройдемся перебором и замерим время
	auto startssrectSearch = system_clock::now();
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] == numberpol)
		{
			ifFound = true;
		}
	}
	auto finishssrectSearch = system_clock::now();
	duration<double> timeForDirectSearch = finishssrectSearch - startssrectSearch;


	// Пройдемся бинарным поиском и замерим время
	auto startBinary = system_clock::now();
	while (numberpol != arr[binInd]) //Пока введенное число != массиву от бинарного индекса
	{
		if ((maxInd - minInd) == 1) //проверяем , чтоб не оказалось одно число в массиве, если оказалось одно число, то у нас нет чисел, которые повторяются
		{
			cout << "Такого числа в массиве нет" << "\n";
			break;
		}

		if (numberpol > arr[binInd]) //Отсеиваем значения для поиска, котрые меньше массива от бинарного индекса
		{
			minInd = binInd;
			binInd = (maxInd + minInd) / 2;

		}
		else if (numberpol < arr[binInd]) //Отсеиваем значения для поиска, котрые больше массива от бинарного индекса
		{
			maxInd = binInd;
			binInd = (maxInd + minInd) / 2;
		}

	}
	if (numberpol == arr[binInd])
	{
		cout << "Найден на позиции " << binInd << "\n";
	}
	auto finishBinary = system_clock::now();
	duration<double> timeForBinarySearch = finishBinary - startBinary;
	cout << fixed << "Разница между Бинарным поиском и перебором= " << timeForBinarySearch.count() - timeForDirectSearch.count() << " секунд" << "\n";
	cout << "\n";

	//8 задение.
	//Меняет местами элементы массива, индексы которых вводит пользователь. Выведите скорость обмена, используя библиотеку chrono.

	  //  Меняем два введенных элемента в массиве
	cout << "Чтобы поменять местами два элемента массива, введи их индексы:  ";
	cout << "\n";
	int elementToChange1, elementToChange2;
	cout << "Первый: ";
	cin >> elementToChange1;
	cout << "Второй: ";
	cin >> elementToChange2;
	cout << "\n";

	//  Замеряем время на замену
	auto startExchange = system_clock::now();
	swap(arr[elementToChange1], arr[elementToChange2]);
	auto finishExchange = system_clock::now();
	duration<double> exchangeDuration = finishExchange - startExchange;
	cout << fixed << "Поменял за: " << exchangeDuration.count() << " секунд" "\n";
	cout << "\n";

	// Выводим готовый массив (после замены)
	cout << "Поменялось вот так: " << "\n";
	for (int i = 0; i < 100; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}

https://github.com/DmitriyProgSPM/MyLaba1/blob/main/%D0%9E%D1%82%D1%87%D1%91%D1%82%20%D0%BF%D0%BE%20Laba2.docx  ОТЧЁТ
