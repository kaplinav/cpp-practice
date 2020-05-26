//Задание 7*. Реализуйте задание №3, используя не встроенные,
//а ДИНАМИЧЕСКИЕ массивы (массив?). Так как строки могут быть разной длины,
//эффективным решением было бы отводить под каждую строку ровно столько байтов,
//сколько требуется для ее хранения.
//При этом необходимые параметры (количество строк
// сформируйте с помощью потока ввода

#define stop __asm nop

#include <string>
#include <iostream>

const char STOP_STRING = '*';
char zero = '\0';

int main()
{
	int nStringNumber = 0;

	std::cout << "please input number of rows = ";
	std::cin >> nStringNumber;
	std::cout << std::endl << "please input strings" << std::endl;

	char** strings = new char*[nStringNumber];
	bool found_stop = false;
// Счетчик пустых строк.
// Если n-ая строка будет содержать подстроку STOP_STRING и n < nStringNumber,
// то после ввода строк необходимо будет вычислить новое значение nStringNumber  
	size_t empty_rows = 0; 

//Цикл ввода строк:
	for (size_t i = 0; i < nStringNumber; i++)
	{
		std::string stop_s("*");
		std::string in;
		if (!found_stop)
		{
			std::cin >> in;
			size_t n = in.length();
			strings[i] = new char[in.length() + 1];
			strcpy_s(strings[i], in.length() + 1, in.c_str());
			if (in.find(STOP_STRING) != std::string::npos) found_stop = true;
		}
		else
		{
// для итераций после введенной строки, содержащий подстроку STOP_STRING
// вычислить количество "пустых" строк
			empty_rows++;
		}
	}
	std::cout << std::endl << "input completed" << std::endl;
	stop

// Нужно вычислить новое значение для nStringNumber
// чтобы исключить из обработки "пустые" строки,
// если таковые имеются
	if (empty_rows) nStringNumber -= empty_rows;
	
//Цикл сортировки строк по методу "всплывающего пузырька" в
//порядке возрастания кода первого символа
	bool swap = false;
	do
	{
		swap = false;
		for (size_t i = 0; i < (nStringNumber - 1); i++)
		{
			int result = strcmp(strings[i], strings[i + 1]);
			if (result > 0)
			{
				char* t = strings[i];
				strings[i] = strings[i + 1];
				strings[i + 1] = t;
				swap = true;
			}
		}

// После очередного прохода по массиву строк, вывести их на экран
		std::cout << std::endl;
		for (size_t i = 0; i < nStringNumber; i++)
		{
			std::cout << strings[i] << std::endl;
		}
		std::cout << std::endl;
	} while (swap);

//Освобождение занятой памяти:
	for (size_t i = 0; i < nStringNumber; i++) delete[] strings[i];
	delete[] strings;

return 0;
}