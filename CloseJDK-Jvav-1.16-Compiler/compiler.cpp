// defines
#define _CRT_SECURE_NO_WARNINGS true

// includes
#include <bits/stdc++.h>

using namespace std;

// refers

bool preProcess(char*, FILE*, char*);

char* getPath(char*);

FILE* classFile = NULL;
FILE* objectFile = NULL;
char temp[100009] = { "\0" };
int layer = 0;

void errs(int num)
{
	switch(num)
	{
	case 1:
		cout << "ERROR: Invalid sentence.\n";
		break;


	default:
		cout << "ERROR: Unknown Error.\n";
		break;
	}
	return;
}

int quotes(int start)
{
	for (int i = start; true; i++)
	{
		fread(temp + i, 1, 1, objectFile);
		if (*(temp + i) == '\"' || *(temp + i) == '\0')
		{
			return i;
		}
		else
		{
			fwrite(temp + i, 1, 1, classFile);
		}
	}
}
int brackets(int start)
{
	int x = 0;
	for (int i = start; true; i++)
	{
		fread(temp+i, 1, 1, objectFile);
		if (temp[i] == '\"')
		{
			i=quotes(i)+1;
		}
		if (temp[i] == ')')
		{
			break;
		}
		fwrite(temp+i, 1, 1, classFile);
		x = i;
	}
	return x;
}

bool compile(FILE* KLAS, FILE* objFile)
{
	classFile = KLAS;
	objectFile = objFile;

	fwrite("jvav!",1,sizeof("jvav!")-1,KLAS);
	fwrite("¸ò?~|$.This Program Can Not Be Run In DDoS Mode.|~\n", 1,sizeof("¸ò?~|$.This Program Can Not Be Run In DDoS Mode.|~\n")-1,KLAS);

	while (!feof(objFile))
	{
		memset(temp, '\0', strlen(temp));
		fread(temp, 1, 1, objFile);
		switch (temp[0])
		{
		case ';': // prevent "code here or nothing + ;;;;;;;;;;;;;;;;;;; + code here..."
			break;
		case '}': // end of function
			--layer;
			fwrite("\n-\n", 1, 3, KLAS);
			break;
		case 'p':
			if (layer <= 0) { errs(1); break; } // prevent errors
			for (int i = 1; temp[i-1] != '('; i++)
			{
				fread(temp + i, 1, 1, objFile);
			}
			if(!strncmp("print", temp, 5))
			{
				fwrite("1 ", 1, 2, KLAS);
				memset(temp, '\0', strlen(temp));
				brackets(0);
			}
			break;
		case 'm':
			for (int i = 1; temp[i - 1] != '('; i++)
			{
				fread(temp + i, 1, 1, objFile);
			}
			if (!strncmp("main", temp, 4))
			{
				fwrite("3 main\'", 1, 7, KLAS);
				memset(temp, '\0', strlen(temp));
				brackets(0);
				fwrite("\'\n+\n", 1, 4, KLAS);
				++layer;
			}
			break;
		}
	}

	fwrite("-1\n", 1, 3, KLAS);
	fclose(objFile);
	fclose(KLAS);
	return true;
}

char klasFile[10009] = { "\0" };

char* compiler(FILE* objFile, char* sourceFile)
{
	char* targetFilePath = NULL;

	targetFilePath = getPath(sourceFile); // get file path (without filename)
	strcpy(klasFile, sourceFile); // set obj file path
	klasFile[strlen(klasFile) - 4] = '\0';
	strcat(klasFile, "klas");
	FILE* KLAS = NULL;
	KLAS = fopen(klasFile, "wb"); // create obj file
	if (!KLAS)
	{
		cerr << "Failed to create KLAS file!\n";
		exit(5);
	}
	compile(KLAS,objFile);
	return klasFile;
}
