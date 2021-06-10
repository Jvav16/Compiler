// defines
#define _CRT_SECURE_NO_WARNINGS true

// includes
#include <bits/stdc++.h>

using namespace std;

char* getPath(char*);

char Path[10009] = { "\0" };

bool earlyProcess(char* SourceFileName)
{
	char* targetFilePath = NULL;
	char ObjFile[10009] = { "\0" };
	targetFilePath = getPath(SourceFileName);
	strcpy(ObjFile, SourceFileName);
	ObjFile[strlen(ObjFile) - 4] = 'j';
	ObjFile[strlen(ObjFile) - 3] = 'v';
	ObjFile[strlen(ObjFile) - 2] = 'o';
	ObjFile[strlen(ObjFile) - 1] = 'b';
	ObjFile[strlen(ObjFile)] = 'j';
	FILE* objFile = NULL;
	objFile = fopen(ObjFile,"wb");
	if (!objFile)
	{
		cerr << "Failed create OBJ file!\n";
		exit(2);
	}
	fwrite("Hello, World!", 1, strlen("Hello, World!") + 1, objFile);
	return true;
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
