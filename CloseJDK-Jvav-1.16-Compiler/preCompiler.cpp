// defines
#define _CRT_SECURE_NO_WARNINGS true

// includes
#include <bits/stdc++.h>

using namespace std;

char tmp[100000009] = { "\0" };

bool comment = false;

void judge(FILE* objFile)
{
	for (int i = 0; i < strlen(tmp); i++) // loop the whole line
	{
		if (tmp[i] == '/' && tmp[i + 1] == '*') // prevent comments
		{
			comment = true;
		}
		if (tmp[i] == '*' && tmp[i + 1] == '/')
		{
			comment = false;
			i += 2;
		}
		if (tmp[i] == '/' && tmp[i + 1] == '/')
		{
			return;
		}

		if (comment)
		{
			continue;
		}
		if (tmp[i] == ' ' || tmp[i] == '\b' || tmp[i] == '\r' || tmp[i] == '\n') // prevent spaces
		{
			continue;
		}
		if (tmp[i] == '\t') // prevent tabs
		{
			continue;
		}
		fwrite(tmp+i,1,1,objFile); // write to file
	}
	return;
}

bool preProcess(char* SourceFile, FILE* objFile, char* path)
{
	FILE* sourceFile = NULL;
	sourceFile = fopen(SourceFile, "r");
	while (!feof(sourceFile)) // loop the whole file
	{
		memset(tmp, '\0', strlen(tmp)); // clear tmp
		fgets(tmp, 100000009, sourceFile); // get a line of tmp
		judge(objFile); // prevent sth.
	}
	fclose(objFile);
	return true;
}
