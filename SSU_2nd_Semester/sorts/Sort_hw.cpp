#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void printArray(vector<int>& vec)
{
	int i;
	for (i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}


void selectionSort(vector<int>& vec)
{
	int minind;
	for (int i = 0; i < vec.size() - 1; ++i) {
		minind = i;
		for (int j = i + 1; j < vec.size(); ++j) {
			if (vec[j] < vec[minind]) {
				minind = j;
			}
			cout << "i = " << i << "\t" << "j = " << j << "\t" << "min ind = " << minind << "\t";
			printArray(vec);
		}
		swap(vec[minind], vec[i]);
		cout << "After swap" << "\t";
		printArray(vec);
	}
}


void insertionSort(vector<int>& vec)
{
	int i, j;
	for (i = 1; i < vec.size(); ++i) {
		j = i;
		while (j > 0 && vec[j] < vec[j - 1]) {
			swap(vec[j], vec[j - 1]);
			cout << "i = " << i << "\t" << "j = " << j << "\t";
			printArray(vec);
			j--;
		}
	}
}


int main()
{
	vector<int> arr;
	srand(time(0));
	for (int i = 0; i < 9; ++i) {
		arr.push_back(rand() % 20);
	}
	cout << "Array:  ";
	printArray(arr);
	//selectionSort(arr);
	insertionSort(arr);

	return 0;
}