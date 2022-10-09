#define _CRT_SECURE_NO_WARNINGS
#include"auxiliary.h"

void generateFile(string fileName, double sizeArray)
{
	ofstream fout(fileName);
	srand(time(NULL));
	for (int i = 0; i < sizeArray; i++)fout << generateNumber(1, 100) << " ";

	fout.close();
}
int generateNumber(int min, int max)
{
	return min + rand() % (max - min + 1);
}
void openFile(string fileName)
{
	char* fileNameChar = new char[fileName.length()];
	strcpy(fileNameChar, fileName.c_str());
	system(fileNameChar);
}