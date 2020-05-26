﻿
/*************************************************************
	Практическое занятие №2. Побитовые операторы.
							Директивы препроцессора.
							Указатели.
*************************************************************/

#define _USE_MATH_DEFINES // for C++  
#include <cmath> 

#include <iostream>
#include <tchar.h>

#include "Header_1.h"
#include "Header_2.h"

#define	  stop __asm nop	//с помощью директивы препроцессора задаем
							//макроподстановку
/***************************************************************
Задания, отмеченные * , не являются обязательными!
***************************************************************/

int _tmain()
{
// ********************************************************
	//Задание 1. Побитовая арифметика (and, or, xor, not), сдвиги.
	//1.1
	{
	int y;//Задайте значение y, например, с помощью потока ввода

	//С помощью побитовых операторов и операторов сдвига выведите значение "y"
	//на консоль в двоичном виде, например:
	//если y==9, то
	// а) 0 0 0 0 ...   0 0 1 0 0 1 (количество двоичных цифр зависит от платформы)
	


	//или пропустите незначащие нули - б) 1 0 0 1



	}
	

	//1.2 Дана целая переменная
	{
		int y;//Задайте значение y, например, с помощью потока ввода

		//"Сдвиньте" все единицы в этой переменной вправо, например:
		//было:   0100 1111 0000 0000 0110 1111 0000 0010
		//стало:  0000 0000 0000 0000 0000 1111 1111 1111
		//Реализовать задачу посредством одного цикла!


	}


	//1.3* Какие операции следует применить к заданному ниже операнду sNum для
	//того, чтобы переменная sRes приняла требуемое значение?
	//Замечание 1: значения подобраны таким образом, что в каждом случае достаточно
	//использовать один оператор (и при необходимости маску) 
	//Замечание 2: посредством оператора xor (подобрав соответствующую маску)
	//можно получить любое значение => этот оператор предполагается использовать
	//в том случае, когда все остальные уже "не спасают" 
	{
	short sNum = 0x8008;
	short sRes;

	//0x7ff7
	
	//0x8ff8

	//0x0008

	//0x7f08

	//0xf001

	//0x0010
	
	stop
	}

	
// ********************************************************
	//Задание 2. Директивы препроцессора

	//2.1. Использование "математических" макросов стандартной библиотеки:
	//в заголовочном файле <cmath> (который в свою очередь включает старый
	//файл math.h) определены часто используемые математические
	//константы, например M_PI. Воспользуйтесь этой константой для
	//вычисления длины окружности.
	//Обратите внимание: определения констант в свою очередь тоже заключены
	//в директивы условной трансляции. Что еще, кроме подключения заголовочного
	//файла, требуется сделать???

	double circle_length = 0.;
	int diameter = 7;
	float radius = 2.;

	circle_length = diameter * M_PI;
	circle_length = 2 * M_PI * radius;

	//2.2.Макросы с параметрами.
	//2.2.1 Напишите свою макроподстановку LENGHT которая вычисляет длину окружности.

	#define LENGHT(radius) ((2) * (M_PI) * (radius))

	// протестируйте написанный макрос для следующих ситуаций:
	{
		float l1 = LENGHT(1 + 2); // должно быть 18.8495...
		
		float l2 = 1 / LENGHT(2); // должно быть 0.07957...
		
		stop
	}

	//2.2.2* определите макрос MAX(A, B)  для вычисления б'ольшего
	//значения из двух.
	
	//Используйте макрос следующим образом. Следите за изменением
	//значений переменных k, i, j. Объясните результат.
	//Постарайтесь убрать побочные эффекты.
	//Отметьте случаи, когда избежать побочных эффектов невозможно
/*
	int i = 10, j = 12, k;
	k = MAX(i, j);
	k = MAX(j, i) * 2;
	k = MAX(j, i+3);
	k = MAX(i--, j++);
*/

	#define MAX(a, b) (((a) > (b))? (a) : (b))

	int i = 10, j = 12, max = 0;
	//int z = ((j) > (i + 3)) ? (j) : (i + 3) ;
	//int x = ((i--) > (j++)) ? (i--) : (j++);

	max = MAX(i, j); // i=10 j=12 max=12
	max = MAX(j, i) * 2; // i=10 j=12 max=24
	max = MAX(j, i + 3); // i=10 j=12 max=13
	max = MAX(i--, j++); // i=9 j=14 max=13

	/*
	Необходимо учитывать, что в постфиксной операции инкремента или декремента 
	значение выражения вычисляется до применения соответствующего оператора. 
	Операция инкремента или декремента выполняется после вычисления операнда. 
	Эта особенность возникает, только когда постфиксная операция инкремента или декремента выполняется в контексте выражения.
	*/
	
	//2.2.3 определите макрос EXCHANGE(X, Y)  для перестановки
	//двух объектов типа int в памяти местами. Проверьте для приведенного
	//фрагмента. Подумайте, что будет делать макроподстановка, если
	//переставляемые значения разного типа???
	
	//#define EXCHANGE(x, y) do{(x) = (x) + (y); (y) = (x) - (y);  (x) = (x) - (y);}while(false);
	#define EXCHANGE(x, y) (x) = (x) + (y); (y) = (x) - (y); (x) = (x) - (y);

	int x1=1, y1=-1;
	EXCHANGE(x1,y1);
	stop

	int x2=100, y2=-100;
	EXCHANGE(x2,y2);
	stop

	int x3 = 10;
	float y3 = 3.;
	EXCHANGE(x3, y3)
	/* x3 = 3 y3 = 10.0000000 
		Будет выполнено неявное приведение типов
	*/
	stop


	//2.3. Директивы условной трансляции
	//Выполняя следующий фрагмент, посмотрите, какое
	//значение принимает переменная iNN. Что нужно сделать
	//для того, чтобы результат был равен 0? 1? 2?

/*
// iNN = 0
#define NNN
#define MMM
*/
/*
// iNN = 1
#define MMM
*/
/*
// iNN = 2
#define NNN
*/

int iNN;
#if defined NNN && defined MMM
	iNN = 0;
#elif defined MMM
	iNN = 1;
#elif defined NNN 
	iNN = 2;

#else
	iNN = -1;
#endif
	stop

		//Задание 2.4. Загляните в Project/Properties -> диалоговая панель
		//- Property Pages/C\C++/Preprocessor/Preprocessor definitions.
		//В опциях командной строки в зависимости от мишени сборки проекта
		//(Debug или Release) может быть определено с помощью ключа /D
		//имя _DEBUG. С помощью директив условной
		//трансляции напишите фрагмент кода, который в зависимости от типа
		//мишени выводит с помощью cout разный текст на консоль. Проверьте
		//при разных мишенях сборки.

#if defined _DEBUG
	std::cout << "debug";
#else
	std::cout << "release" << std::endl;
#endif
	stop

		//Пусть
		//для мишени Debug в процессе выполнения данного участка
		//кода на экран выводится информация об
		//имени файла, номере строки с функцией вывода, дате и времени 
		//компиляции файла, содержащего данную функцию вывода,
		//а также имя функции, содержащей данную строку.
		//Для мишени Release должна быть просто выведена строка
		//"Release configuration!"

#define END_LINE std::endl
#if defined _DEBUG
		std::cout << __FILE__ << END_LINE;
		std::cout << __LINE__ << END_LINE;
		std::cout << __DATE__ << END_LINE;
		std::cout << __TIME__ << END_LINE;
		std::cout << __FUNCTION__ << END_LINE;
#else
		std::cout << "Release configuration!" << END_LINE;
#endif
	//Подсказка: для получения нужной информации введите в инструментальном
	//окне 'Index' справочной системы следующую ключевую фразу:	Predefined Macros
	
	//Подсказка: мишень сборки проекта можно
	//поменять следующим образом - Build/Configuration Manager/Configuration





	//Задание 2.5.* Управляя определенностью идентификатора _UNICODE и используя
	//возможности заголовочного <tchar.h>, определите и проинициализируйте переменную,
	//которая может становиться как однобайтовой, так и расширенной без 
	//изменения исходного текста.
	//С помощью отладчика проверьте результат.







// ********************************************************
	//Задание 3.Заголовочные файлы. Директива #include
	//3.1.Создайте и подключите к проекту два заголовочных файла 1.h и 2.h
	//В каждом заголовочном файле объявите перечисление с одинаковыми именами
	//констант, но сопоставьте именованным константам разные значения, например:
	//1.h - enum MyEnum{My1, My2, My3};  . 2.h - enum MyEnum{My1=5, My2, My3};
	//С помощью директив условной трансляции в DEBUG-версии пользуйтесь значениями
	//констант из 1.h, а в RELEASE-версии значениями констант из 2.h

	std::cout << Prime1 << std::endl;
	std::cout << Prime2 << std::endl;

// ********************************************************

	//Задание 4. Указатели
	//Объявите объекты разных типов и проинициализируйте их.
	//Объявите указатели соответствующих типов и проинициализируйте их
	//адресами заданных объектов. 
	//Выполняя задание, с помощью отладчика посмотрите, какие значения
	//будут присвоены переменным-указателям и на что эти указатели
	//"указывают"
	
	char char_number = 2;
	short short_number = 3;
	int int_number = 5;
	float float_number = 7.7;
	double double_number = 11.11;
	int prime_array[5] = {2, 3, 5, 7, 11};
	struct employee
	{
		int id;
		std::string name;
	};
	employee developer;
	developer.id = int_number;
	developer.name = "Alan Turing";

	char *char_p;
	short *short_p;
	int *int_p;
	float *float_p;
	double *double_p;
	int *array_p;
	employee *employee_p;

	char_p = &char_number; // значение 0x0043fccb, указывает на 2
	short_p = &short_number; // значение 0x0043fcbc, указывает на 3
	int_p = &int_number; // значение 0x0043fcb0, указывает на 5
	float_p = &float_number; // значение 0x0043fca4, указывает на 7.69999981
	double_p = &double_number; // значение 0x0043fc94, указывает на 11.109999999999999
	array_p = prime_array; // значение 0x0043fc78, указывает на элемент массива prime_array[0] = 2
	employee_p = &developer; // значение 0x0043fc50, указывает на структуру developer
	
/*
	//Задание 4а. Объявите указатель на тип char и проинициализируйте
	//его адресом строкового литерала. Присвойте переменной типа char значение
	//любого элемента строки.
	//Проверьте - возможно ли присвоить какое-либо значение по адресу,
	//задаваемому указателем?
	stop
*/
	/*
	char s_literal [5]= "five"; 
	char* s_literal_p = s_literal;
	char c_var = s_literal[3];
	*s_literal_p = c_var;
	*/

	const char* pc = "Hello";
	char cvar = *pc;
	//*pc = cvar;  Невозможно. Значение, храняещееся по адресу pc, является константным. 

	stop

	/*
	int x = 1, y = 0.;
	int *p = &((x > y) ? x : y); 
	*/

/*
	//Задание 5. Арифметика указателей. Операция разыменования указателя.
	//Выполняя задание, следите за изменением значений
	//указателей и значений объектов, на которые они указывают.
	//Интерпретируте наблюдаемые результаты
*/
	{
		int nAr[3] = {1,3}; 
		int* pn = &nAr[0]; // инициализирован указатель на элемент массива с индексом 0 *pn = 1
		(*pn)++; // постфиксно выполнен инкремент значения, на которое указывает указатель pn 
		pn++;	 // на sizeof(int) (т.к. тип элемента массива int) инкрементирован адрес, хранящийся в pn
				 // теперь *pn = 3

		char cAr[]={'A','B','C','D'};
		char* pc = &cAr[0]; // указатель инициализирован адресом элемента массива cAr[0] *pc = 'A'
		(*pc)=(*pc)+5;	// по указателю pc текущее значение кода символа + 5, теперь cAr[0] = 'F'
		pc=pc+3;	// на sizeof(char)*3 увеличить значение адреса в указателе pc, теперь pc указывает на cAr[3] = 'D'
	
		double dAr[3]={1.0,2.0}; 
		double* pd1 = &dAr[0]; // указатель инициализирован адресом элемента массива dAr[0] *pd1 = 1.0
		double* pd2 = pd1; // указатель иницилизирован адресом из указателя pd1, что аналогично pd2=&dAr[0]
		(*pd2)+=2; // текущее значение по указателю pd2 цвеличивается на 2 dAr[0] = 3.0
		pd2+=2; // адрес в pd2 увеличивается на sizeof(double)*2, что аналогично pd2=&dAr[2]

		//Объясните результат выполнения операции
		//вычитания двух указателей
		pd1 = &dAr[0];
		pd2 = &dAr[1];
		int nNumber=pd2 - pd1; 
		// nNumber = 1. Результат - частное от деления разницы адресов в указателях на sizeof(double)

		//Сравните указатели pd2 и pd1 и с помощью cout
		//выведите результаты сравнения.

		if (pd1 == pd2)
		{
			std::cout << "pd1 = pd2" << std::endl;
		}
		else
		{
			if (pd1 > pd2)
			{
				std::cout << "pd1 > pd2" << std::endl;
			}
			else
			{
				std::cout << "pd1 < pd2" << std::endl;
			}
		}
		stop
	}

/*
	//Задание 6. Явное преобразование указателя. Иногда возникает
	//необходимость одни и те же данные интерпретировать по-разному,
	//например, целое можно представить как совокупность четырех
	//байтов и работать с каждым байтом по отдельности. Для этого
	//нужно иметь возможность "указывать" как на целое, так и на байт. 
	//Следовательно, возникает необходимость явного преобразования
	//указателя. 
	//Подсказка: для правильной интерпретации этого задания воспользуйтесь
	//возможностями отладчика представлять данные в интересующем
	//Вас виде (в данном случае - в шестнадцатеричном) - для
	//этого используйте правую клавишу мыши,находясь в окне
	//переменных и изменяйте пункт - Hexadecimal display
*/
    unsigned int nObject5=0x55667788;
	unsigned int* pnObject5=&nObject5;


	//Раскомментировав следующую строчку кода, обратите внимание
	//на сообщение компилятора - он не считает преобразование 
	//"легальным" (безопасным)

	unsigned char* pucObject5;
//	pucObject5=static_cast<unsigned char*>(pnObject5);	//(1)
	pucObject5=reinterpret_cast<unsigned char*>(pnObject5);	// *pucObject5 = 0x88 младший байт nObject5
				//а такое
				//преобразование - целиком на совести программиста.
				//Его можно применять, только четко представляя себе
				//результат преобразования (2)

	//Откомментируйте следующие строчки сс==..., p - изменился? *p=...

	char cc = *(pucObject5++); // сс = 0x88, pucObject5 - выполнен постфиксный инкремент адреса на sizeof(unsigned char), *pucObject5 = 0x77, nObject5 не изменилась
	cc = (*pucObject5)++; // сс = 0x77, pucObject5 - адрес не изменился, *pucObject5 = 0x78, nObject5 теперь != 0x55667788, а = 0x55667888
	cc = ++*(pucObject5); // сс = 0x79, pucObject5 - адрес не изменился, *pucObject5 = 0x79, , nObject5 теперь != 0x55667888, а = 0x55667988
	cc = *(++pucObject5); // сс = 0x66, pucObject5 - выполнен префиксный инкремент адреса на sizeof(unsigned char), *pucObject5 = 0x66, nObject5 не изменилась
	stop


	//Задание 7. Void-указатель. 
	//Выполняя задание, посмотрите - какие значения присваиваются
	//void-указателю. Обратите внимание: средствами отладчика Вы
	//не можете посмотреть значения, на которые "указывает"
	//void-указатель

	void* pVoid;	//объявление void-указателя
	int	nObject3 = 5;
	int* pInt = &nObject3;
	char cObject3 = 'A';
	
	pVoid = &nObject3;
	int int_number1 = *(static_cast<int*>(pVoid));
	pVoid = &cObject3;
	char char_symbol = *(static_cast<char*>(pVoid));
	pVoid = pInt;
	int int_number2 = *(static_cast<int*>(pVoid));

	//Прежде, чем раскомментировать следующую строчку, вспомните:
	//что нужно сделать, чтобы выражение стало корректным 	

	pInt=static_cast<int*>(pVoid);

	//Что нужно сделать для того, чтобы следующее закомментированное выражение
	//стало корректным?
	{
		const int n = 1;
		const void* p = &n; //????объявить слева void-указатель
	}



	//7a. При выполнении следующего фрагмента посмотрите, какие неприятности
	//могут Вас ожидать при явном приведении типа void-указателя,
	//который в момент времени (1) указывает на double, к типу 
	//указателя на int (2) 

	double dObject3 = 33.33;
	pVoid = &dObject3;	//(1)

	int nTmp = *(static_cast<int*>(pVoid)); //(2) nTmp = 1889785610
	stop

		//Задание 8*. Модификатор const. В каждом из заданий
		//объявите указатель требуемого вида. Посредством каждого
		//указателя попробуйте:
		//получить значение по адресу
		//записать новое значение по адресу
		//модифицировать указатель
/*
		//Задание 8a. Указатель является константой. 
		char* const cp1 = nullptr;
	
	stop	 
*/
/*
		//Задание 8б. Указываемое значение является константой.
		const char* cp2 = nullptr;

	stop
*/
/*
		//Задание 8в. И указатель, и указываемое значение
		//являются константами. 
		char const* const cp3 = nullptr;

	stop
*/

		//Задание 8г. Указатель на переменную, объявленную с
		//ключевым словом const. 
	const int nN = 1;

	//Объявите указатель и проинициализируйте его выражением - &nN	

	const int*  pnN = &nN;

	stop



	//Задание 9.При выполнении задания обратите внимание на то,
	//как наглядно отладчик "раскрывает" конструкции типа
	//"указатель на указатель" и на способы получения конечного
	//объекта по таким "иерархическим" указателям
	int	n1 = 1;

    //Объявите указатель pn и проинициализируйте его так, чтобы он
	//"указывал" на n1
	int* pn = &n1;

    //Объявите указатель ppn и проинициализируйте его так, чтобы он
	//"указывал" на pn
	int** ppn = &pn;

    //Объявите указатель pppn и проинициализируйте его так, чтобы он
	//"указывал" на ppn
	int*** pppn = &ppn;
  
	//С помощью указателей pn, ppn и ppn получите значение объекта n1
	//и присвойте его n2
	int i_num1 = *pn;
	int i_num2 = **ppn;
	int i_num3 = ***pppn;	
	int n2 = i_num3;

	stop

	return 0;
}//end main
