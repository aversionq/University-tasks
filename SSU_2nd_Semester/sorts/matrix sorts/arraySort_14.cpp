#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


void printMatrix(vector< vector<int> >& matrix, int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}


int getSize()
{
	ifstream in("in_selectionSort.txt");
	int size;
	in >> size;


	return size;
}


vector< vector<int> > convertTomatrix(int size)
{
	ifstream in("in_selectionSort.txt");
	string skip;
	in >> skip;
	vector< vector<int> > matrix(size, vector<int>(size));
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			in >> matrix[i][j];
		}
	}


	return matrix;
}


void matrixTofile(vector< vector<int> >& matrix, int size)
{
	ofstream out("out_selectionSort.txt");
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			out << matrix[i][j];
			out << ' ';
		}
		out << "\n";
	}
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
		}
		swap(vec[minind], vec[i]);
	}
}


void matrixSort(vector< vector<int> >& matrix, int size)
{
	int diag_amount = -(size - 1);
	for (int k = 0; k < (size * 2 - 1); ++k) {
		vector<int> diag;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (i == (j + diag_amount)) {
					diag.push_back(matrix[i][j]);
				}
			}
		}
		if (diag_amount != 0) {
			selectionSort(diag);
			reverse(diag.begin(), diag.end());
		}
		int index = 0;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (i == (j + diag_amount)) {
					matrix[i][j] = diag[index];
					index++;
				}
			}
		}
		diag_amount++;
	}
}


int main()
{
	int size = getSize();
	vector< vector<int> > matrix = convertTomatrix(size);
	matrixTofile(matrix, size);
	matrixSort(matrix, size);
	matrixTofile(matrix, size);
	cout << endl << "Sorting is done! Check your 'out_selectionSort.txt' file!" << endl;


	return 0;
}