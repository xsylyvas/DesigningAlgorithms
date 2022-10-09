#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;
void sort(string fileNameA, string fileNameB, string fileNameC,int length);
void splitIntoFiles(string fileNameA, string fileNameB, string fileNameC, int length);
void mergingFile(string fileNameA, string fileNameB, string fileNameC, int length);
void preliminarySorting(string fileNameA, string fileNameB,int size);