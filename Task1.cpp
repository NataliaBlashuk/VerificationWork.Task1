#include <iostream>
#include<fstream>

using namespace std;

const int N = 286;

int ContentsFile(char*);
int* InitArray(char*, int);
void CreateFile(char*, int*, int);
int* MergeArrays(int*, int, int*, int, int&);
void DisplayArray(int*, int);

int main()
{
	char fileNameFirst[N], fileNameSecond[N], fileNameThird[N];
	cout << "Enter the name of file with first array: ";
	cin.getline(fileNameFirst,N,'\n');
	cout << "Enter the name of file with second array: ";
	cin.getline(fileNameSecond, N, '\n');
	system("cls");
	int l = 0;
	int n = ContentsFile(fileNameFirst);
	int* arrayF = InitArray(fileNameFirst, n);
	int m = ContentsFile(fileNameSecond);
	int* arrayS = InitArray(fileNameSecond, m);
	int* arrayTh = MergeArrays(arrayF, n, arrayS, m, l);
	cout << "Creating of new array is ended. The result is" << endl;
	DisplayArray(arrayTh, l);
	cout << endl << "Please, enter the name of new file" << endl;
	cin.getline(fileNameThird, N, '\n');
	CreateFile(fileNameThird, arrayTh, l);
	system("pause");
	return 0;
}

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file for read!" << endl;
		system("pause");
		exit(1);
	}
	int count = 0, term;
	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int* array = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> array[i];
	streamIn.close();
	return array;
}

int* MergeArrays(int* arrayF, int n, int* arrayS, int m, int &l)
{
	l = m + n;
	int* arrayTh = new int[l];
	int i = 0, j = 0, k = 0;
	for (; i < n && j < m; k++)
	{
		if (arrayF[i] < arrayS[j])
		{
			arrayTh[k] = arrayF[i];
			i++;
		}
		else
		{
			arrayTh[k] = arrayS[j];
			j++;
		}
		if (i == n)
			for (; j < m; j++, k++)
				arrayTh[k] = arrayS[j];
		else
		{
			for (; i < n; i++, k++)
				arrayTh[k] = arrayF[i];
		}
	}
	return arrayTh;
}

void DisplayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

void CreateFile(char* fileName, int* array, int n)
{
	ofstream streamOut(fileName);
	if (!streamOut.is_open())
	{
		cout << " Cannot open file for write!" << endl;
		system("pause");
		exit(1);
	}
	int temp;
	for (int i = 0; i < n; i++)
	{
		temp = array[i];
		streamOut << temp << " ";
	}
	streamOut.close();
}
