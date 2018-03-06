//Robert Dyer
//Manish Goel , CIS 22C Winter 18
//Lab 4
//Partners: John Le and Stephen Lee
//

//Lab 4 Pseudocode

//1. Start Program

//2. Declare function prototypes for the recursive Selection, Insertion, Quick, and Merge sorts

//3. Declare a global constant integer for the max size of the sorted arrays and initialize it to 32

//4. Begin main by declaring all variables necessary for menu choices; an integer to hold the menu choice, an integer for size of the dynamic array, and a char for holding a continue value

//5. Declare variables for data types being entered into the array

//6. Begin a do while loop that will print a menu while the user enters y or Y as a response to the continue question

//7. Inside the menu, the user is given the choice to create an array based on the data type they are entering; int, double, char, or string; all menu choices are assumed to be validated for proper input

//8. User is then prompted for the number of items they would like to store, and a series of conditional statements execute afterwards

//9. If the user chose integers, 4 objects of the tempArray class are created with the amount of items that were to be stored being passed as arguments to their overloaded constructors

//10. In the class tempArray, private member variables for the absolute max size of the array(const int), the count(int), and the max number of items being stored in the bag(int(may change, thus the extra variable)), and a pointer to a templated data type which will point to our dynamically allocated array

//11. Public functions are also defined to add, remove, check frequency of an entry, check if the array is empty, get the index of an entry, clear the array, check if the array contains an entry, and also a function returning the current size of the array, as well as a destructor to properly delete all dynamically allocated memory

//12. Back in main, the tempArray objects created, initialize their counts to 0 and their maxitems variables to the size entered by the user. The pointers arrptr are also given the addresses of dynamically allocated arrays of the data type input by the user as well as of the size input by the user

//13. Back in main, the user is prompted for their data, and a for loop is initiated to read in all the input from the user(each tempArr object's add function is called with the data input by the user as an argument)

//14. The contents of the first array object is then printed to verify user input, afterwards being sent to the recursive selection sort algorithm

//15. The recursive selection sort algorithm uses another function maxIndex to determine the index in the first array with the highest value, then using this it begins to swap the starting index with that maxIndex value, recursively calling itself with the initial index increasing by one each time

//16. This function effectively swaps all the values in the first array so that they are sorted in descending order

//17. Each recursive call to the algorithm is preceded by a call to the class's print function to visually show the process as it happens

//18. The first array is then printed once again using the class's print function, verifying the new sorted array

//19. The second array is then passed to an insertion sort algorithm

//20. The recursive insertion sort algorithm first checks the size of the array and whether it is less than or equal to 1. If yes, it returns, otherwise it calls itself recursively with size - 1.

//21. The algorithm then begins to swap all consecutive array locations with each other based on whether the value at the index given by the size - 2 is less than the value next to it

//22. Each recursive call also calls the object's print function to visually demonstrate the process

//23. Once the second array is sorted, the array is printed once again to verify results

//24. The third array is then passed to a recursive quick sort algorithm that




#include <iostream>
#include <string>
#include <fstream>

#include "tempArray.h"

using namespace std;

const int SORT_MAX_SIZE = 32;

template <typename Type>
int maxIndex(Array<Type>*, int, int);

template <typename Type>
void selectionSort(int, Array<Type>*, int index = 0);

template <typename Type>
void insertionSort(Array<Type>*, int);

template <typename Type>
int partition(Array<Type>*, int, int);

template <typename Type>
void quickSort(Array<Type>*, int, int);

template <typename Type>
void merge(Array<Type>*, int, int, int);

template <typename Type>
void mergeSort(Array<Type>*, int, int);

template <typename Type>
void print(Array<Type>*, int);

template <typename Type>
void print(Array<Type>*, int, int);


int main()
{
    ofstream myfile;
    string type;
    string sort;
    int dataitems;
    
    myfile.open("output.txt");
    cout << "Enter the type of data items that will be entered. string, int, double, or char" << endl << endl;
    cin >> type;
    cin.ignore();
    cout << endl << endl;
    
    cout << "Enter the number of data items that will be entered" << endl << endl;
    cin >> dataitems;
    cin.ignore();
    cout << endl << endl;
    
    int n = dataitems - 1;
    
    if (dataitems <= 0 || dataitems > SORT_MAX_SIZE)
    {
        cout << "Invalid dataitem entered" << endl << endl;
        cout << "Number entered was either too small or too large please enter a number 1-32" << endl << endl;
    }
    
    else if (type == "string")
    {
        Array<string> arrays1(dataitems);
        Array<string> arrays2(dataitems);
        Array<string> arrays3(dataitems);
        Array<string> arrays4(dataitems);
        Array<string> *selectCopy = &arrays1;
        Array<string> *insertCopy = &arrays2;
        Array<string> *quickCopy = &arrays3;
        Array<string> *mergeCopy = &arrays4;
        
        for (int x = 0; x < dataitems; x++)
        {
            string inputted;
            cout << "Enter the " << x + 1 << "th string" << endl << endl;
            cin >> inputted;
            cout << endl << endl;
            arrays1[x] = inputted;
            arrays2[x] = inputted;
            arrays3[x] = inputted;
            arrays4[x] = inputted;
        }
        
        cout << "Array contents as entered:" << endl << endl;
        
        print(selectCopy, dataitems);
        
        cout << endl << endl;
        
        //Selection Sort
        cout << "Selection Sort: " << endl << endl;
        myfile << "Selection Sort: " << endl << endl;
        selectionSort(dataitems, selectCopy);
        print(selectCopy, dataitems);
        cout << endl << endl;
        
        //Insertion Sort
        cout << "Insertion Sort: " << endl << endl;
        myfile << "Insertion Sort: " << endl << endl;
        insertionSort(insertCopy, dataitems);
        print(insertCopy, dataitems);
        cout << endl << endl;
        
        //Quick Sort
        cout << "Quick Sort: " << endl;
        myfile << "Quick Sort: " << endl;
        quickSort(quickCopy, 0, dataitems);
        print(quickCopy, dataitems);
        cout << endl << endl;
        
        //Merge Sort
        cout << "Merge Sort: " << endl << endl;
        myfile << "Merge Sort: " << endl << endl;
        mergeSort(mergeCopy, 0, n);
        print(mergeCopy, dataitems);
        cout << endl << endl;
        
    }
    
    else if (type == "int")
    {
        Array<int> arrayi1(dataitems);
        Array<int> arrayi2(dataitems);
        Array<int> arrayi3(dataitems);
        Array<int> arrayi4(dataitems);
        Array<int> *selectCopy = &arrayi1;
        Array<int> *insertCopy = &arrayi2;
        Array<int> *quickCopy = &arrayi3;
        Array<int> *mergeCopy = &arrayi4;
        
        for (int x = 0; x < dataitems; x++)
        {
            int inputted;
            cout << "Enter the " << x + 1 << "th string" << endl << endl;
            cin >> inputted;
            cout << endl << endl;
            arrayi1[x] = inputted;
            arrayi2[x] = inputted;
            arrayi3[x] = inputted;
            arrayi4[x] = inputted;
        }
        
        cout << "Array contents as entered:" << endl << endl;
        
        print(selectCopy, dataitems);
        
        cout << endl << endl;
        
        //Selection Sort
        cout << "Selection Sort: " << endl << endl;
        myfile << "Selection Sort: " << endl << endl;
        selectionSort(dataitems, selectCopy);
        print(selectCopy, dataitems);
        cout << endl << endl;
        
        //Insertion Sort
        cout << "Insertion Sort: " << endl << endl;
        myfile << "Insertion Sort: " << endl << endl;
        insertionSort(insertCopy, dataitems);
        print(insertCopy, dataitems);
        cout << endl << endl;
        
        //Quick Sort
        cout << "Quick Sort: " << endl;
        myfile << "Quick Sort: " << endl;
        quickSort(quickCopy, 0, dataitems);
        print(quickCopy, dataitems);
        cout << endl << endl;
        
        //Merge Sort
        cout << "Merge Sort: " << endl << endl;
        myfile << "Merge Sort: " << endl << endl;
        mergeSort(mergeCopy, 0, n);
        print(mergeCopy, dataitems);
        cout << endl << endl;
        
    }
    
    else if (type == "double")
    {
        Array<double> arrayd1(dataitems);
        Array<double> arrayd2(dataitems);
        Array<double> arrayd3(dataitems);
        Array<double> arrayd4(dataitems);
        Array<double> *selectCopy = &arrayd1;
        Array<double> *insertCopy = &arrayd2;
        Array<double> *quickCopy = &arrayd3;
        Array<double> *mergeCopy = &arrayd4;
        
        for (int x = 0; x < dataitems; x++)
        {
            double inputted;
            cout << "Enter the " << x + 1 << "th string" << endl << endl;
            cin >> inputted;
            cout << endl << endl;
            arrayd1[x] = inputted;
            arrayd2[x] = inputted;
            arrayd3[x] = inputted;
            arrayd4[x] = inputted;
        }
        
        cout << "Array contents as entered:" << endl << endl;
        
        print(selectCopy, dataitems);
        
        cout << endl << endl;
        
        //Selection Sort
        cout << "Selection Sort: " << endl << endl;
        myfile << "Selection Sort: " << endl << endl;
        selectionSort(dataitems, selectCopy);
        print(selectCopy, dataitems);
        cout << endl << endl;
        
        //Insertion Sort
        cout << "Insertion Sort: " << endl << endl;
        myfile << "Insertion Sort: " << endl << endl;
        insertionSort(insertCopy, dataitems);
        print(insertCopy, dataitems);
        cout << endl << endl;
        
        //Quick Sort
        cout << "Quick Sort: " << endl;
        myfile << "Quick Sort: " << endl;
        quickSort(quickCopy, 0, dataitems);
        print(quickCopy, dataitems);
        cout << endl << endl;
        
        //Merge Sort
        cout << "Merge Sort: " << endl << endl;
        myfile << "Merge Sort: " << endl << endl;
        mergeSort(mergeCopy, 0, n);
        print(mergeCopy, dataitems);
        cout << endl << endl;
        
    }
    
    else if (type == "char")
    {
        Array<char> arrayc1(dataitems);
        Array<char> arrayc2(dataitems);
        Array<char> arrayc3(dataitems);
        Array<char> arrayc4(dataitems);
        Array<char> *selectCopy = &arrayc1;
        Array<char> *insertCopy = &arrayc2;
        Array<char> *quickCopy = &arrayc3;
        Array<char> *mergeCopy = &arrayc4;
        
        for (int x = 0; x < dataitems; x++)
        {
            char inputted;
            cout << "Enter the " << x + 1 << "th string" << endl << endl;
            cin >> inputted;
            cout << endl << endl;
            arrayc1[x] = inputted;
            arrayc2[x] = inputted;
            arrayc3[x] = inputted;
            arrayc4[x] = inputted;
        }
        
        cout << "Array contents as entered:" << endl << endl;
        
        print(selectCopy, dataitems);
        
        cout << endl << endl;
        
        //Selection Sort
        cout << "Selection Sort: " << endl << endl;
        myfile << "Selection Sort: " << endl << endl;
        selectionSort(dataitems, selectCopy);
        print(selectCopy, dataitems);
        cout << endl << endl;
        
        //Insertion Sort
        cout << "Insertion Sort: " << endl << endl;
        myfile << "Insertion Sort: " << endl << endl;
        insertionSort(insertCopy, dataitems);
        print(insertCopy, dataitems);
        cout << endl << endl;
        
        //Quick Sort
        cout << "Quick Sort: " << endl;
        myfile << "Quick Sort: " << endl;
        quickSort(quickCopy, 0, dataitems);
        print(quickCopy, dataitems);
        cout << endl << endl;
        
        //Merge Sort
        cout << "Merge Sort: " << endl << endl;
        myfile << "Merge Sort: " << endl << endl;
        mergeSort(mergeCopy, 0, n);
        print(mergeCopy, dataitems);
        cout << endl << endl;
        
    }
    
    else
    {
        cout << "You did not enter a data type." << endl << endl;
    }
    
    cin.get();
    return 0;
}




//Function definitions

//Selection Sort
//maxIndex function to sort descending
template <typename Type>
int maxIndex(Array<Type>* a, int i, int j)
{
    if (i == j)
        return i;
    
    // Find minimum of remaining elements
    int k = maxIndex(a, i + 1, j);
    
    // Return minimum of current and remaining
    Type c = (*a)[i];
    Type d = (*a)[k];
    if (c > d)
        return i;
    else
        return k;
}

//Actual Selection sort algorithm
template <typename Type>
void selectionSort(int n, Array<Type>* a, int index)
{
    // Return when starting and size are same
    if (index == n)
        return;
    
    // calling minimum index function for minimum index
    int k = maxIndex(a, index, n - 1);
    
    // Swapping when index nd minimum index are not same
    if (k != index)
        swap((*a)[k], (*a)[index]);
    
    print(a, n);
    
    // Recursively calling selection sort function
    selectionSort(n, a, index + 1);
    return;
}

//Insertion sort
template <typename Type>
void insertionSort(Array<Type>* a, int size)
{
    //Base case
    if (size <= 1)
        return;
    
    //print(a, size);
    
    //Recursive call
    insertionSort(a, size - 1);
    
    Type last = (*a)[size - 1];
    int i = size - 2;
    
    while (i >= 0 && (*a)[i] < last)
    {
        (*a)[i + 1] = (*a)[i];
        i--;
    }
    
    (*a)[i + 1] = last;
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
    int i = (low - 1);           // Index of smaller element
    
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
template <class T>
void quickSort(Array<T>* arr, int low, int high)
{
    print(arr, low, high + 1);
    if (low < high)
    {
        int pi = partition(arr, low, high);    // Partitioning Index
        // Sort elements
        quickSort(arr, low, pi - 1);    // Before partition
        quickSort(arr, pi + 1, high);    // After partition
    }
}



//Merge Sort
template <typename Type>
void merge(Array<Type> *a, int index, int middle, int n) //ind 0 mid 2 n 4
{
    int i, j, k;
    int leftSize = middle - index + 1; //3
    int rightSize = n - middle; //2
    
    Array<Type> left(leftSize);
    Array<Type> right(rightSize);
    
    for (i = 0; i < leftSize; i++)
        left[i] = (*a)[index + i]; //0 to 2
    
    for (j = 0; j < rightSize; j++)
    {
        right[j] = (*a)[middle + j + 1]; // 3 to 4
    }
    
    i = 0;
    j = 0;
    k = 1;
    
    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            (*a)[k] = left[i];
            i++;
            k++;
        }
        
        else
        {
            (*a)[k] = right[j];
            j++;
            k++;
        }
        
    }
    
    while (i < leftSize)
    {
        (*a)[k] = left[i];
        i++;
        k++;
    }
    
    while (j < rightSize)
    {
        (*a)[k] = right[j];
        j++;
        k++;
    }
    
    print(a, index, n);
    left.Erase();
    right.Erase();
}


template <typename Type>
void mergeSort(Array<Type> *a, int index, int n)
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




//Print Functions
//Prints array to file and console
//Use this print array to print final list
template <typename Type>
void print(Array<Type> *a, int b)
{
    ofstream myfile;
    myfile.open("output.txt");
    
    cout << "Result: ";
    
    for (int x = 0; x < b; x++)
    {
        cout << (*a)[x] << ", ";
    }
    
    cout << endl << endl;
    
    myfile << "Result: ";
    
    for (int x = 0; x < b; x++)
    {
        myfile << (*a)[x] << ", ";
    }
    
    myfile << endl << endl;
}

//Use this print to print each step, b = pivots
template <typename Type>
void print(Array<Type>*  a, int b, int c)
{
    ofstream myfile;
    myfile.open("output.txt");
    
    cout << "Printing Step: " << "(" << b << ")";
    
    for (int x = b; x < c; x++)
    {
        cout << (*a)[x] << ", ";
    }
    
    cout << endl;
    myfile << "Printing Step: " << "(" << b << ")";
    
    for (int x = b; x < c; x++)
    {
        myfile << (*a)[x] << ", ";
    }
    
    myfile << endl;
}

