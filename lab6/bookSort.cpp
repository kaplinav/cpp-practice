
#include <iostream>
#include "bookSort.h"

const unsigned short precision = 100;

typedef int(*typeCompareFuncs[])(BOOK* p1, BOOK* p2);

int compareAuthor(BOOK* p1, BOOK* p2)
{
	return strcmp(p1->author, p2->author);
}

int compareName(BOOK* p1, BOOK* p2)
{
	return strcmp(p1->name, p2->name);
}

int compareYear(BOOK* p1, BOOK* p2) 
{ 
	return p1->year - p2->year; 
}

int comparePrice(BOOK* p1, BOOK* p2)
{
	return ( (p1->price - p2->price) * precision);
}

int compareCategory(BOOK* p1, BOOK* p2) 
{ 
	return static_cast<int>(p1->category) - static_cast<int>(p2->category);
}

typeCompareFuncs compareFuncs = { compareAuthor, compareName, compareYear, comparePrice, compareCategory };

void swap(BOOK* p1, BOOK* p2)
{
	BOOK t = *p1; 
	*p1 = *p2;
	*p2 = t;
}

void bookSort(enSortType sortType, enSortField sortField)
{
	for (size_t i = 1; i < myLibraryCount; i++)
	{
		for (size_t j = (myLibraryCount - 1); j >= i; j--)
		{
			BOOK* pCurr = myLibrary + j;
			BOOK* pPrev = myLibrary + j - 1;
			int compareResult = compareFuncs[sortField](pPrev, pCurr);
			if (sortType == ascending)
			{
				if (compareResult > 0) swap(pPrev, pCurr);
			}
			else
			{
				if (compareResult < 0) swap(pPrev, pCurr);
			}
		}
	}
}




