#include <cstdio>
#include <ctime>
#include "BookData.h" 
#include "fileFunc.h"

#define stop __asm nop



unsigned short getCurrentYear()
{
	const unsigned short startYear = 1900;

	// current date/time based on current system
	time_t now = time(0);

	// convert now to tm struct for UTC
	tm buf;
	gmtime_s(&buf, &now);
	
	return startYear + buf.tm_year;
}

void libraryToFile(int &savedEntries)
{	
	FILE *stream;
	errno_t err;
		
	if (myLibraryCount == 0) return;
	
	//Open file for write only library isn't empty 
	err = fopen_s(&stream, "myLib.txt", "r");
	if (err == 0)
	{
		//Write count of entries
		fprintf(stream, "%d", myLibraryCount);
		fprintf(stream, "\n");

		for (size_t i = 0; i < myLibraryCount; i++)
		{
			//id
			fprintf(stream, "%d", i);
			//Автор
			fprintf(stream, " %s", myLibrary[i].author);
			//Название
			fprintf(stream, " %s", myLibrary[i].name);
			//Год
			fprintf(stream, " %d", myLibrary[i].year);
			//Цена
			fprintf(stream, " %.2f", myLibrary[i].price);
			//Категория
			fprintf(stream, " %d", myLibrary[i].category);
			fprintf(stream, "\n");
		}
		savedEntries = myLibraryCount;
	}
	else printf("\nCouldn't open a file\n");
	// Close stream if it is not NULL
	if (stream) fclose(stream);
	
}

void libraryFromFileRead(FILE* stream, size_t countOfEntry)
{
	if (countOfEntry < 0) return;
	if (stream == nullptr) return;

	BOOK* libraryFromFile = new BOOK[countOfEntry];

	for (size_t i = 0; i < countOfEntry; i++)
	{
		BOOK t;
		int idEntry;
		//id
		fscanf_s(stream, "%d", &idEntry);
		//Автор
		fscanf_s(stream, "%s", libraryFromFile[i].author, sizeof(libraryFromFile[i].author));
		//Название
		fscanf_s(stream, "%s", libraryFromFile[i].name, sizeof(libraryFromFile[i].name));
		//Год
		fscanf_s(stream, "%d", &libraryFromFile[i].year);
		//Цена
		fscanf_s(stream, "%f", &libraryFromFile[i].price);
		//Категория
		fscanf_s(stream, "%d", &libraryFromFile[i].category);
	}

	delete[] myLibrary;
	myLibrary = libraryFromFile;
	myLibraryCount = countOfEntry;
}

void libraryFromFile(int &refCountOfEntries)
{
	FILE *stream;
	errno_t err;
	//open the file
	err = fopen_s(&stream, "myLib.txt", "r");
	//Number of added entries
	int countOfEntries = 0;
	
	if (err == 0)
	{
		//read count of entries from file
		fscanf_s(stream, "%d", &countOfEntries);

		if (countOfEntries > 0)
		{
			//read entries from file to array
			libraryFromFileRead(stream, countOfEntries);
		}
		
	}
	else printf("\nCouldn't open a file\n");

	// Close stream if it is not NULL   
	if (stream) fclose(stream);

	refCountOfEntries = countOfEntries;
}

//Initialization
void libraryInit()
{
	//Number of added entries
	int countOfEntries = 0;
	//Fill library from file
	libraryFromFile(countOfEntries);
	printf("Added %d entries\n", countOfEntries);
}

//End of work
void libraryEndOfWork()
{
	int savedEntries = 0;
	libraryToFile(savedEntries);
	printf("%d entries saved\n", savedEntries);
}