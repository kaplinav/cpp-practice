﻿/*************************************************************
	Практическое занятие №5. Структуры
//динамический массив структур
//поиск
//сортировка
//сохранение в файле
//чтение из файла
*************************************************************/



#define	  stop __asm nop	


#include <ctime>
#include "BookData.h"
#include "fileFunc.h"
#include "bookSort.h"

void main()
{
	
	libraryInit();
	
	bookSort(ascending, name);
	bookSort(descending, name);

	libraryEndOfWork();

	stop




	//Используйте структуру BOOK, созданную в предыдущей работе.
	//Для этого достаточно переписать и подключить к проекту файлы
	//book.h и book.cpp
	

	//Упрощения:
	//1. пусть автор и заглавие книги состоят из одного слова
	//2. все строки можно задавать латинскими буквами. Если хочется
	//   не только выводить, но и вводить русские символы, следует
	//   а) пользоваться расширенными функциями ввода/вывода - wprintf(), wscanf()
	//   б) хранить строки как расширенные - wchar_t
	//   в) установить кодировку - setlocale(LC_CTYPE, ".866");


	//Задание 1. Создаем «картотеку».
	//«Картотека» - это массив структур => нужно такой массив создать.
	//Замечание: размер массива придется увеличиватьпо мере добавления книг =>
	//каким должен быть такой массив???
	

	//Пользователь должен иметь возможность по своему желанию выполнять
	//разные действия с картотекой => нужно такую возможность ему
	//предоставить: это может выглядеть как вывод "меню" (перечень
	//возможных действий и соответствующих реакций пользователя), например:
	//Распечатать содержимое картотеки (1)
	//Ввести новую книгу (2)
	//Удалить существующую(ие) (3)
	//Записать текущее содержимое картотеки в файл (4)
	//Считать из файла содержимое в картотеку (5)
	//...
	//Выход из программы (...)


	//Реализуйте посредством функций разные возможности работы с картотекой




	//Подсказка: для файлового ввода/вывода используйте функции fprintf и fscanf
	//(заголовочный файл <cstdio>



	




	//****************************************************************
	//Задание 2. Предоставьте пользователю возможность выводить перечень книг
	//в определенном порядке => напишите функцию (функции) сортировки массива
	//по любому из полей структуры.
	//Замечание: признак - "по какому полю сортируем" можно ввести с помощью
	//перечисления.



}