
#include <iostream>
#define stop __asm nop

const size_t x = 4;
const size_t y = 3;
const size_t z = 3;

void show_array(double (*dArray)[3][3])
{
	for (size_t r = 0; r < y; r++) // rows
	{
		for (size_t l = 0; l < x; l++) // layers
		{
			for (size_t e = 0; e < z; e++) // elements
			{
				std::cout << dArray[l][r][e];
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

int main() 
{

	//Задание 4*. Объявление и использование указателей на многомерные
	// массивы. Проинициализируйте трехмерный массив
	//double dArray[4][3][3] так, как показано на рисунке и напишите фрагмент
	//кода, который меняет местами значения элементов четных
	//и нечетных слоев:
	//	было:			     |--------|
	//  				   / |4  4  4 |
	//					 |--------|	4 |
	//				   / |3  3  3 |	4 |
	//    			 |---------|3 |   |
	//			   / | 2  2  2 |3 | /
	//			  |---------|2 |__|
	//			  | 1  1  1 |2 | /
	//			  | 1  1  1 |__|
	//			  | 1  1  1 | /
	//			  |_________|

	//	стало:			     |--------|
	//  				   / |3  3  3 |
	//					 |--------|	3 |
	//				   / |4  4  4 |	3 |
	//    			 |---------|4 |   |
	//			   / | 1  1  1 |4 | /
	//			  |---------|1 |__|
	//			  | 2  2  2 |1 | /
	//			  | 2  2  2 |__|
	//			  | 2  2  2 | /
	//			  |_________|
	/*
	for (int i = 0; i < ...; ...)
	{
		//Замечание: НЕ НУЖНО МОДИФИЦИРОВАТЬ ВЫРАЖЕНИЯ СПРАВА ОТ ЗНАКА РАВЕНСТВА!!!
		... = dArray[i];
		... = dArray[i + 1];
		//переставляем местами элементы i-того и i+1-ого слоев


	}
	*/

	const size_t x = 4;
	const size_t y = 3;
	const size_t z = 3;
	double dArray[x][y][z];

	for (size_t i = 0; i < x; i++)
	{
		double* dptr = &dArray[i][0][0];
		for (size_t j = 0; j < (y * z); j++, dptr++) *dptr = (i + 1);
	}
	show_array(dArray);

	for (size_t i = 0; i < x; i += 2)
	{
		double* lp = &dArray[i][0][0];
		double* rp = &dArray[(i + 1)][0][0];

		for (size_t j = 0; j < (y * z); j++, lp++, rp++)
		{
			double t = *lp;
			*lp = *rp;
			*rp = t;
		}
	}
	std::cout << std::endl;
	show_array(dArray);


	stop
	return 0;
}