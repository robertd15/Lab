#ifndef SORTINGMETHODS_H
#define SORTINGMETHODS_H
#include <iostream>
#include <string>
#include <fstream>
//Print Functions
//Prints array to file and console
template <typename Type>
void print(Array<Type> &a, int b)
{
	ofstream myfile;
	myfile.open("output.txt");
	cout << "printing list: ";
	for (int x = 0; x < b; x++)
	{
		cout << (a)[x] << ", ";
	}
	cout << endl;
	myfile << "printing list: ";
	for (int x = 0; x < b; x++)
	{
		myfile << (a)[x] << ", ";
	}
	myfile << endl;
}

template <typename Type>
void print(Array<Type> &a, int b, int c)
{
	ofstream myfile;
	myfile.open("output.txt");
	cout << "printing list: ";
	for (int x = b; x < c + 1; x++)
	{
		cout << (a)[x] << ", ";
	}
	cout << endl;
	myfile << "printing list: ";
	for (int x = b; x < c + 1; x++)
	{
		myfile << (a)[x] << ", ";
	}
	myfile << endl;
}
//Merge Sort
template <typename Type>
void merge(Array<Type> &a, int index, int middle, int n) //ind 0 mid 2 n 4
{
	int i, j, k;
	int leftSize = middle - index + 1; //3
	int rightSize = n - middle; //2

	Array<Type> left(leftSize);
	Array<Type> right(rightSize);

	for (i = 0; i < leftSize; i++)
		left[i] = a[index + i]; //0 to 2
	for (j = 0; j < rightSize; j++)
	{
		right[j] = a[middle + j + 1]; // 3 to 4
	}
	i = 0;
	j = 0;
	k = 1;
	while (i < leftSize && j < rightSize)
	{
		if (left[i] <= right[j])
		{
			(a)[k] = left[i];
			i++;
			k++;
		}
		else
		{
			(a)[k] = right[j];
			j++;
			k++;
		}
	}
	while (i < leftSize)
	{
		(a)[k] = left[i];
		i++;
		k++;
	}
	while (j < rightSize)
	{
		(a)[k] = right[j];
		j++;
		k++;
	}
	print(a, index, n);
	left.Erase();
	right.Erase();
}

template <typename Type>
void mergeSort(Array<Type> &a, int index, int n)
{
	if (index < n)
	{
		cout << "Sorting...";
		int middle = index + (n - index) / 2;
		cout << middle << endl;
		mergeSort(a, index, middle);
		mergeSort(a, middle + 1, n);
		merge(a, index, middle, n);
		print(a, n);
	}
}
//quickSort
template <typename Type>
void quickSort(int n, Array<Type>* a, int index = 0)
{
	// Return when starting and size are same
	if (index == n)
		return;

	// calling minimum index function for minimum index
	int k = minIndex(a, index, n - 1);

	// Swapping when index nd minimum index are not same
	if (k != index)
		swap((*a)[k], (*a)[index]);

	// Recursively calling selection sort function
	quickSort(n, a, index + 1);
	return;
}

template <typename Type>
int minIndex(Array<Type>* a, int i, int j)
{
	if (i == j)
		return i;

	// Find minimum of remaining elements
	int k = minIndex(a, i + 1, j);

	// Return minimum of current and remaining
	Type c = (*a)[i];
	Type d = (*a)[k];
	if (c < d)
		return i;
	else
		return k;
}

/*
Hold onto the last element.
Iterate from the first element and compare to the last.
If element is less than/equal to the last,
swap the first and the current.
Through each full iteration, swap the current element with the last.
Afterwards, iterate to the next element.

arr --> Array to be sorted
low --> Starting index
high --> Ending index

@return the partition index
*/
template <class T>
int partition(Array<T>* arr, int low, int high)
{
	T pivot = (*arr)[high];    // pivot
	int i = (low - 1);		   // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if ((*arr)[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap((*arr)[i], (*arr)[j]);
		}
	}
	swap((*arr)[i + 1], (*arr)[high]);
	return (i + 1);
}

/* Go through each element and find the partitioning index.
Then sort the elements that are before and after that partition.
arr --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quickSort(Array<int>* arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);	// Partitioning Index

											// Sort elements
		quickSort(arr, low, pi - 1);	// Before partition
		quickSort(arr, pi + 1, high);	// After partition
	}
}


#endif