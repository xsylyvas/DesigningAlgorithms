#include"sort.h"
void splitIntoFiles(string fileNameA, string fileNameB, string fileNameC, int length)
{
	ifstream finA(fileNameA);
	ofstream foutB(fileNameB);
	ofstream foutC(fileNameC);

	int temp, count = 1;
	bool writeToB = true;
	while (!finA.eof())
	{
		finA >> temp;
		if (writeToB)foutB << " " << temp;
		else foutC << " " << temp;
		count++;
		if (count > length)
		{
			count = 1;
			writeToB = !writeToB;

		}
	}
	foutB << "";
	foutC << "";
	finA.close();
	foutB.close();
	foutC.close();
}
void mergingFile(string fileNameA, string fileNameB, string fileNameC, int length)
{
	ifstream finB(fileNameB);
	ifstream finC(fileNameC);
	ofstream foutA(fileNameA);

	int pointerB = 0, pointerC = 0;

	int tempB, tempC;

	bool isstartSegment = true;

	bool endC = false;
	while (!finB.eof())
	{

		finB >> tempB;
		if (finC.eof())// ���������� ����� ����� C, ��� �� �����, �� ��������� ������� �������
		{
			if (tempB < tempC)
			{
				foutA << " " << tempB;
				pointerB++;
			}

			if (tempB >= tempC && !endC)
			{
				endC = true;
				foutA << " " << tempC;
				pointerC++;
				foutA << " " << tempB;
				pointerB++;
			}
			else if (tempB >= tempC && endC)
			{
				foutA << " " << tempB;
				pointerB++;
			}

		}
		if (isstartSegment && !finC.eof())//��'������� ����� ���� ���� ��������
		{

			while (!finC.eof() && pointerC < length)
			{
				finC >> tempC;
				if (tempB < tempC)
				{
					foutA << " " << tempB;
					pointerB++;
					break;
				}
				else
				{
					foutA << " " << tempC;
					pointerC++;
					if (finC.eof())endC = true;
				}
			}
			if (tempC <= tempB)
			{
				foutA << " " << tempB;
				pointerB++;
			}

		}
		else
			if (!isstartSegment && !finC.eof())//��'������� ���� ��������, �� ��� ��������������� �� ��������� ���������
			{
				if (pointerC == length || tempB < tempC)
				{
					foutA << " " << tempB;
					pointerB++;
				}
				else
				{
					foutA << " " << tempC;
					pointerC++;
					while (!finC.eof() && pointerC < length)
					{
						finC >> tempC;
						if (tempB < tempC)
						{
							foutA << " " << tempB;
							pointerB++;
							break;
						}
						else
						{
							foutA << " " << tempC;
							pointerC++;
							if (finC.eof())endC = true;
						}
					}
					if (tempC <= tempB)
					{
						foutA << " " << tempB;
						pointerB++;
					}
				}
			}
		
		if (pointerB == length && pointerC != length)//���������� ����� ����� B, ��� ����� ������� ������� ����� ������ ���������
		{
			if (finC.eof() && tempB < tempC && !endC)//�������� ������� ������� ����� C, ��� ���� �� ������� ���� ���� C,��� ������� ������� ���� �� �� ���������
			{
				foutA << " " << tempC;
				pointerC++;
				if (finC.eof())endC = true;
			}
			else
				if (!finC.eof())//�������� �� ������� ����� C, �� ����������
				{
					foutA << " " << tempC;
					pointerC++;
					if (finC.eof())endC = true;
					while (!finC.eof() && pointerC < length)
					{
						finC >> tempC;
						foutA << " " << tempC;
						if (finC.eof())endC = true;
						pointerC++;
					}
				}
		}
		if (pointerC == length && pointerB == length)// ����������� ���� �������� � ����� B �� � �����������
		{
			isstartSegment = true;
			pointerB = 0;
			pointerC = 0;
		}
		else isstartSegment = false;
	}

	finB.close();
	finC.close();
	foutA.close();
}
void sort(string fileNameA, string fileNameB, string fileNameC,int length)
{
	while (1)
	{
		splitIntoFiles(fileNameA, fileNameB, fileNameC, length);
		ifstream fileC(fileNameC);
		if (fileC.peek() == std::ifstream::traits_type::eof())break;
		mergingFile(fileNameA, fileNameB, fileNameC, length);
		
		length *= 2;
		cout << length << endl;
	}

}
void preliminarySorting(string fileNameA, string fileNameB,int size)
{
	int* arrayT = new int[size];
	ifstream finA(fileNameA);
	ofstream foutB(fileNameB);

	int temp,iter=0;
	while (!finA.eof())
	{
		finA >> arrayT[iter];
		iter++;
		if (iter == size)
		{
			sort(arrayT, arrayT + size);
			for (int i = 0; i < size; i++)foutB << " " << arrayT[i];
			iter = 0;
		}
	}
	if (iter != 0)
	{
		sort(arrayT, arrayT + iter);
		for (int i = 0; i < iter; i++)foutB << " " << arrayT[i];
	}
	finA.close();
	foutB.close();
}