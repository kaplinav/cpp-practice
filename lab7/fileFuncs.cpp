/*
This file contains Functions for working with input file
*/

#include <stdio.h>
#include <regex>

const int argcMin = 2;
const char txt[] = ".txt";

struct charBuffer
{
	char* pTop;
	char* pNext;
	size_t size;

	void init()
	{
		size = 10;
		pTop = pNext = new char[size];
		*pNext = '\0';
	}
	
	void resize()
	{
		char* t = new char[size + 10];
		memcpy(t, pTop, sizeof(char) * size);
		delete[] pTop;
		pTop = t;
		t = NULL;
		pNext = pTop + (size - 2);
		size += 10;
	}

	void setChar(char c)
	{
		if (!pNext)
			return;

		if ((pNext - pTop) == (size - 2))
			this->resize();

		*pNext = c;
		pNext++;
		*pNext = '\0';
	}
};

charBuffer testBuffer;

/* Argument with file name is necessary */
bool checkArgcCount(int argc)
{
	if (argc < argcMin)
		return false;
	else
		return true;
}


bool checkExtensionNoReg(const char* argv, const char* extension)
{
	while (*argv && *argv != '.')
		argv++;
	
	if (!*argv)
		return false;

	while (*argv && (*argv == *extension) )
	{
		argv++;
		extension++;
	}

	return (*argv - *extension) ? false : true ;
}

/* File must have extension '.txt' */
bool checkExtensionReg(const char* argv)
{
	std::regex mask(".*\\.txt$");
	return std::regex_match(argv, mask);
}

/* File must have extension '.txt' */
bool checkExtension(const char* argv)
{
	return (1) ? checkExtensionNoReg(argv, txt) : checkExtensionReg(argv);
}

void getStringFromFile(const char* fileName)
{
	FILE* stream;
	errno_t error;
	error = fopen_s(&stream, fileName, "r");

	if (error)
	{
		/* Couldn't open file*/
		return;
	}

	testBuffer.init();


	int c = 0;
	do
	{
		
		c = fgetc(stream);
		if (c != ' ' && c != EOF)
		{
			testBuffer.setChar(c);
		}

	} while (c != EOF);

	if (stream)
		fclose(stream);
	

}