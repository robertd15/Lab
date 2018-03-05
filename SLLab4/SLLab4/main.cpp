#include <iostream>
#include <string>
#include <fstream>
#include "TemplateArrays.h"
#include "SortingMethods.h"
#define SORT_MAX_SIZE = 32;
using namespace std;

int main()
{
	ofstream myfile;
	myfile.open("output.txt");
	string type;
	int dataitems;
	cout << "Enter the type of data items that will be entered. string, int, double, or char" << endl;
	cin >> type;
	cout << "Enter the number of data items that will be entered" << endl;
	cin >> dataitems;
	int n = dataitems - 1;
	if (dataitems <= 0)
	{
		cout << "Invalid dataitem entered" << endl;
	}
	else if (type == "string")
	{
		Array<string> arrays(dataitems);
		for (int x = 0; x < dataitems; x++)
		{
			string inputted;
			cout << "Enter the " << x + 1 << "th string" << endl;
			cin >> inputted;
			arrays[x] = inputted;
		}
	}
	else if (type == "int")
	{
		Array<int> arrays(dataitems);
		for (int x = 0; x < dataitems; x++)
		{
			int inputted;
			cout << "Enter the " << x + 1 << "th number" << endl;
			cin >> inputted;
			arrays[x] = inputted;
		}
		mergeSort(arrays, 0, n);
		print(arrays, dataitems);
	}
	else if (type == "double")
	{
		Array<double> arrays(dataitems);
		for (int x = 0; x < dataitems; x++)
		{
			double inputted;
			cout << "Enter the " << x + 1 << "th number" << endl;
			cin >> inputted;
			arrays[x] = inputted;

		}
	}
	else if (type == "char")
	{
		Array<char> arrays(dataitems);
		for (int x = 0; x < dataitems; x++)
		{
			char inputted;
			cout << "Enter the " << x + 1 << "th char" << endl;
			cin >> inputted;
			arrays[x] = inputted;
		}
	}

	else
	{
		cout << "you did not enter a data type." << endl;
	}
	system("PAUSE");
}
