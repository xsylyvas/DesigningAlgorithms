#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
void sort(string fileNameA,string fileNameB, string fileNameC);
void splitIntoFiles(string fileNameA, string fileNameB, string fileNameC, int length);
void mergingFile(string fileNameA, string fileNameB, string fileNameC, int length);