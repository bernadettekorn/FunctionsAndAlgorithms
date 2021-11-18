#include <iostream>
using namespace std;

//Selection Sort***************************************************************
void swap(int a, int b, int list[])
{ //we will use this to swap a and b
	int temp = list[a];
	list[a] = list[b];
	list[b] = temp;
}

void selectionSort(int list[], int size)
{
	int smallest;

	for (int i = 0; i < size; i++)
	{ // we will use this to increment our smallest
		int smallest = list[i];
		for (int j = 0; j < size ;j++)
		{ //if a smaller value is found they will swap
			if (smallest < list[j])
				swap(j, i, list);
		}
		
	}

	for (int k = 0; k < size; k++)
	{
		cout << list[k] << " ";
	}
}

//Merge Sort ******************************************************************
void merge(int arrayOne[], int arrayTwo[], int size, int sorted[])
{ //Merge two arrays back together
	//arrayOne is right 
	//arrayTwo is left
	int left = 0, //index on left array
		index = 0, //index on sorted
		right = 0; //index on right 

	//will continue as long as there are still values in both arrays to check 
	while (left < size && right < size)
	{
		if (arrayOne[left] < arrayTwo[right])
		{
			sorted[index] = arrayOne[left];
			//keeps track of what elements in the left array have been moved
			left++;

		}
		else
		{
			sorted[index] = arrayTwo[right];
			//keeps track of what elements in the right array have been moved
			right++;
		}
		//keeps track the last null value in the sorted array
		index++;

	}

	//Now we move any elemnts that may be left in one of the sub arrays

	if (left < size)
	{
		for (int i = left; left < size; left++)
		{
			sorted[index] = arrayOne[left];
			index++;
		}
	}
	if (right < size)
	{
		for (int j = right; right < size; right++)
		{
			sorted[index] = arrayTwo[right];
			index++;
		}
	}
}
void mergeSort(int list[], int size)
{ //creates the two subarrays
	if (size > 1)
	{
		int split = size / 2;
		int* subarrayleft = new int[split];
		int* subarrayright = new int[split];
		int* sort = new int[size];

		for (int i = 0; i < split; i++)
		{ //copies to the left array
			subarrayleft[i] = list[i];
		}
		for (int k = split; k < size; k++)
		{ //copies to the right array
			subarrayright[k - split] = list[k];
		}
		mergeSort(subarrayleft, split);
		mergeSort(subarrayright, split);
		merge(subarrayright, subarrayleft, size, sort);

	}
	else
		return;
}

//*****************************************************************************
//Number of comparisons based off of number of elements
//
//Selection Sort
//n = 100
//4950
//n = 1000
//499500
//n = 10000
//49995000
//
//Merge Sort
//n = 100
//200
//n = 1000
//3000
//n = 10000
//40000
//*****************************************************************************