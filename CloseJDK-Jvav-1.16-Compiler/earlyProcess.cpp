// defines
#define _CRT_SECURE_NO_WARNINGS true

// includes
#include <bits/stdc++.h>

using namespace std;

// refers

bool preProcess(char* , FILE* , char*);

char* getPath(char*);

char Path[10009] = { "\0" };

FILE* earlyProcess(char* SourceFileName)
{
	char* targetFilePath = NULL;
	char ObjFile[10009] = { "\0" };

	targetFilePath = getPath(SourceFileName); // get file path (without filename)
	strcpy(ObjFile, SourceFileName); // set obj file path
	ObjFile[strlen(ObjFile) - 4] = '\0';
	strcat(ObjFile, "jvobj");
	FILE* objFile = NULL;
	objFile = fopen(ObjFile,"wb"); // create obj file
	if (!objFile)
	{
		cerr << "Failed to create OBJ file!\n";
		exit(2);
	}
	preProcess(SourceFileName,objFile,targetFilePath);
	objFile = fopen(ObjFile, "rb+");
	return objFile;
}

char* getPath(char* targetFile)
{
	strcpy_s(Path,targetFile);
	for (int i = strlen(Path); i >= 1; i--)
	{
		if (Path[i] == '\\' || Path[i] == '/')
		{
			Path[i + 1] = '\0';
			break;
		}
	}
	return Path;
}
