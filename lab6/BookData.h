#pragma once

enum enSortType
{
	ascending,
	descending
};

enum enSortField
{
	author,
	name,
	year,
	price,
	category
};

enum eCategory
{
	Art,
	Database,
	History,
	Math,
	Tourism
};

struct BOOK
{
	char author[30];
	char name[30];
	unsigned short year;
	float price;
	eCategory category;
};

extern BOOK* myLibrary;
extern size_t myLibraryCount;
