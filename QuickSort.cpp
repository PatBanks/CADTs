
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>

void QuickSort(int *newArray, int left, int right);
void swap(int * newArray, int i, int j);


int main(int argc, char * argv)
{

	int size = 10;
	int maxIntSize = 15;
	int * newArray = new int[size];

	//generate array

	for (int i = 0; i < size; i++)
	{
		newArray[i] = (int)rand() % maxIntSize;
	}
	
	//print unsorted array

	for (int i = 0; i < size; i++)
	{
		std::cout << "Array Element " << i << " is: " << newArray[i] << "\n";
	}

	//set up boundaries

	int left = 0;
	int right = newArray[size - 1];

	// Sort Array

	QuickSort(newArray, left, right);

	//print sorted Array

	for (int i = 0; i < size; i++)
	{
		std::cout << "Sorted Array Element " << i << " is: " << newArray[i] << "\n";
	}



	// hold the command window

	getchar();

	return 0;
}


void QuickSort(int *newArray, int left, int right)
{
	// variables needed for partition

	int i = left;
	int j = right;
	int mid = (left + right)/ 2;
	int pivot = newArray[mid];

	//partition algorithm
	//sorts the array into numbers higher and lower than pivot point

	while (left < j || right > i)
	{

		while (i <= j)
		{ 

			while (newArray[i] < pivot)
			{
				i++;

				while (newArray[j] > pivot)
				{
					j--;

					if (i < j)
					{
						swap(newArray, i, j);
						j--;
						i++;
					}
				}
			}
		}
	}

	//recursive stuff. How the fuck does this work even. jesus murphy
	//Call first half of array. new pivot is set, sorted higher lower.
	//call first quarter of array. new pivot is set, sorted higher lower. 
	//first quarter ordered, second quarter called. 
	//continues until one element, then sorted, and calls the quicksort right.
	//continues until one element, etc. 

	if (left < j)
		QuickSort(newArray, left, j);
	if (right > i)
		QuickSort(newArray, i, right);
}

void swap(int * newArray, int i, int j)
{
	int tmp = newArray[i];
	newArray[i] = newArray[j];
	newArray[j] = tmp;
}


