//Задание 3*.С помощью данной заготовки напишите программу,
//которая:
//вводит строки с клавиатуры с помощью cin>>...
//в объявленный Вами двухмерный ВСТРОЕННЫЙ массив 5*80 элементов типа char;
//признаком конца ввода является символ * (то есть строка - "*") или
//заполнение массива (больше свободных строк нет);
//сортировка строк в алфавитном порядке. Пояснение: крайне
//не рекомендуется для сортировки сложных объектов физически
//перемещать их в памяти. Намного эффективнее завести массив
//указателей на соответствующие строки и перемещать только
//указатели.

//Подсказка: для лексиграфического сравнения строк пользуйтесь
//функцией стандартной библиотеки strcmp(...), заголовочный файл <string>.

#include <iostream>
#include <string>

#define stop __asm nop

//Определите необходимые значения как константы
//STOP_STRING  -  "*"	//признак "прекратить ввод"
//M  -  80	//максимальный размер одной строки
//N  -  10	//максимальное количество строк в массиве

const char STOP_STRING = '*';
const size_t M = 80;
const size_t N = 10;

//strcmp
/*
Negative value if lhs appears before rhs in lexicographical order.
Zero if lhs and rhs compare equal.
Positive value if lhs appears after rhs in lexicographical order.
*/

// вывод строк на экран
void show_srings(char* p[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		if (*p[i])
		{
			std::cout << p[i] << std::endl;
		}
	}
}

void bubble_sort(char* p[], size_t length)
{
	bool swap = false;
	do
	{
		swap = false;
		for (size_t i = 0; i < (length - 1); i++)
		{
			int result = strcmp(p[i], p[i + 1]);
			if (result > 0)
			{
				char* t = p[i];
				p[i] = p[i + 1];
				p[i + 1] = t;
				swap = true;
			}
		}
		show_srings(p, length);
		std::cout << std::endl;
	} while (swap);
}

bool find_stop(char* p, size_t length)
{
	// если первый символ == STOP_STRING
	if (*p == STOP_STRING) return true; 
	// поиск подстроки STOP_STRING в строке
	else for (size_t i = 0; i < length; i++) if (*(p + i) == STOP_STRING) return true;
	return false;
}

int main()
{
	//Объявите двухмерный массив с именем cBuffer типа char и
	// размерностью N*M
	char cBuffer[N][M] = { {'\0'} };

	//Объявите массив (с именем cPointers) указателей на строки
	//размерностью N
	char* cPointers[N];

	//Цикл ввода строк:
	//а) выведите приглашение для ввода
	std::cout << "please input strings" << std::endl;

	size_t counter = 0;
	bool is_end = false;

	//б) пока не введена строка STOP_STRING или не заполнен весь массив
	for (size_t i = 0; i < N; i++)
	{
		if (!(is_end))
		{
			//ввод строки в массив cBuffer:
			std::cin >> cBuffer[i];

			//если введена строка - признак окончания, то выйти из цикла
			//проверка строки на наличие подстроки с STOP_STRING
			is_end = find_stop(cBuffer[i], M);
		}
		//Присвойте элементу массива cPointers с индексом nIndex
		//указатель на строку с номером nIndex в массиве cBuffer
		cPointers[i] = cBuffer[i];
	}
	//Выдать диагностику о том, что прием строк завершен.
	std::cout << std::endl << "input completed" << std::endl;

	//Теперь сортируем строки:
	//Цикл сортировки строк по методу "всплывающего пузырька" в
	//порядке возрастания. На каждой итерации - промежуточная печать
	//отсортированных строк
	bubble_sort(cPointers, N);
	stop
}