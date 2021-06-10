// includes
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

// refers
char targetFile[10009] = { "\0" };

char* getFileName(int num, char* data[])
{
	if (num > 1) // cmd argument exists
	{
		if (data[1][0] == '\"' || data[1][0] == '\'') // check if there is ' or " in the path
		{
			for (int i = 1; i <= strlen(data[1]); i++)
			{
				data[1][i - 1] = data[1][i];
			}
			data[1][strlen(data[1])-1] = '\0';
		}
		bool fileOpened = false;
		ifstream fin; // check if the file exist
		for (int i = 1; i <= 3; i++)
		{
			fin.open(data[1]);
			if (fin.is_open())
			{
				fin.close();
				fileOpened = true;
				break;
			}
			Sleep(100);
		}
		if (!fileOpened) // failed
		{
			cout << "Failed open required source file.\n";
			exit(1);
		}
		else // success
		{
			return data[1];
		}
	}
	else
	{
		cout << "Please enter a jvav filename (*.jvav):";
		gets_s(targetFile); // input filename
		bool fileOpened = false;
		if (targetFile[0] == '\"' || targetFile[0] == '\'') // check if there is ' or " in the path
		{
			for (int i = 1; i <= strlen(targetFile); i++)
			{
				targetFile[i - 1] = targetFile[i];
			}
			targetFile[strlen(targetFile)-1] = '\0';
		}
		ifstream fin; // check the file
		for (int i = 1; i <= 3; i++)
		{
			fin.open(targetFile);
			if (fin.is_open())
			{
				fin.close();
				fileOpened = true;
				break;
			}
			Sleep(100);
		}
		if (!fileOpened) // failed
		{
			cout << "Failed open required source file.\n";
			exit(1);
		}
		else // success
		{
			return targetFile;
		}
	}
}
