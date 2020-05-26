#pragma once

/* Argument with file name is necessary */
bool checkArgcCount(int argc);

/* File must have extension '.txt' */
bool checkExtension(const char* argv);

/**/
void getStringFromFile(const char* fileName);