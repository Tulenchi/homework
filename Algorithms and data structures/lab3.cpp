#include <iostream>

using namespace std;

void Print(int array[], int size) 
{
	for (int i = 0; i < size; i++) 
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void Insertion_Sort(int array[], int size)
{
	int count = 0;
	//cout << "Transposition:" << endl;
	for (int i = 1; i < size; i++) 
	{
		int subarr = array[i];
		int j = i - 1;
		while (subarr < array[j] && j >= 0) 
		{
			array[j + 1] = array[j];
			--j;
			//cout << "Subarr: " << subarr << endl;
			//cout << "Element: " << array[j + 1] << endl;
			count++;
		}
		array[j + 1] = subarr;
	}
	//cout << "Count of transposition: " << count << "\n";
}

void Selection_Sort(int array[], int size)
{
	int count1 = 0;
	int subarr;
	//cout << "Transposition:" << endl;
	for (int i = 0; i < size - 1; i++)
	{
		int count = 0;
		int position = 0;
		int min_element = array[i];
		for (int j = i + 1; j < size; j++)
		{
			if (min_element > array[j])
			{
				min_element = array[j];
				count++;
				position = j;
			}
		}
		if (count != 0)
		{
			count1++;
			subarr = array[i];
			array[i] = min_element;
			array[position] = subarr;
			//cout << "Min: " << min_element << endl;
			//cout << "Element: " << array[position] << endl;
		}
	}
	//cout << "Count of transposition: " << count1 << "\n";
}

void Bubble_Sort(int array[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				count++;
				int subarr = array[j];
				array[j] = array[j + 1];
				array[j + 1] = subarr;
				//cout << "First element: " << subarr << endl;
				//cout << "Second element: " << array[j] << endl;
			}
		}
	}
	//cout << "Count of transposition: " << count << "\n";
}

void Merge(int array[], int left, int middle, int right)
{
	int i = left;
	int j = middle + 1;
	int k = left;
	int subarr[50];
	while (i <= middle && j <= right)
	{
		if (array[i] < array[j])
		{
			subarr[k] = array[i];
			k++;
			i++;
		}
		else
		{
			subarr[k] = array[j];
			k++;
			j++;
		}
	}
	while (i <= middle)
	{
		subarr[k] = array[i];
		k++;
		i++;
	}
	while (j <= right)
	{
		subarr[k] = array[j];
		k++;
		j++;
	}
	for (i = left; i < k; i++)
	{
		array[i] = subarr[i];
	}
}

void Merge_Sort(int array [], int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		Merge_Sort(array, left, middle);
		Merge_Sort(array, middle + 1, right);
		Merge(array, left, middle, right);
	}
}

void Shell_Sort(int array[], int size)
{
	int count = 0;
	for (int dist = size / 2; dist > 0; dist /= 2)
	{
		for (int i = dist; i < size; i += 1)
		{
			int subarr = array[i];
			int j;
			for (j = i; j >= dist && array[j - dist] > subarr; j -= dist)
			{
				array[j] = array[j - dist];
			}
			array[j] = subarr;

		}
	}
}

void Quick_Sort(int array[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = array[(i + j) / 2];
	int subarr;
	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j)
		{
			subarr = array[i];
			array[i] = array[j];
			array[j] = subarr;
			i++;
			j--;
		}
	}
	if (j > left)
		Quick_Sort(array, left, j);
	if (i < right)
		Quick_Sort(array, i, right);
}

int main()
{
	int array[] = {8, 73, 68, 5, 45, 33, 42, 100, 0, -101, -52, -37, -4, -555, -6, -57};
	int size = sizeof(array) / sizeof(array[0]);
	cout << "Array:\n";
	Print(array, size);
	if (size == 0)
	{
		cout << "No elem";
		return 0; 
	}
	int choice;

	cout << "Choose sort:\n"
		"1 - Insertion Sort\n"
		"2 - Selection Sort\n"
		"3 - Bubble Sort\n"
		"4 - Merge Sort\n"
		"5 - Shell Sort\n"
		"6 - Quick Sort\n"
		"7 - End.\n";

	cin >> choice;
	switch (choice)
	{
	case 1:
		Insertion_Sort(array, size);
		cout << "Result:\n";
		Print(array, size);
		break;
	case 2:
		Selection_Sort(array, size);
		cout << "Result:\n";
		Print(array, size);
		break;
	case 3:
		Bubble_Sort(array, size);
		cout << "Result:\n";
		Print(array, size);
		break;
	case 4:
		Merge_Sort(array, 0, size - 1);
		cout << "Result:\n";
		Print(array, size);
		break;
	case 5:
		Shell_Sort(array, size);
		cout << "Result:\n";
		Print(array, size);
		break;
	case 6:
		Quick_Sort(array, 0, size - 1);
		cout << "Result:\n";
		Print(array, size);
		break;
	case 7:
		cout << "Result:\n";
		Print(array, size);
		cout << "Program is over";
	}
	return 0;
}
