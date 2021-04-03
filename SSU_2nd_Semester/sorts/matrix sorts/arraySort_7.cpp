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
	ifstream in("in_shellSort.txt");
	int size;
	in >> size;


	return size;
}


vector< vector<int> > convertTomatrix(int size)
{
	ifstream in("in_shellSort.txt");
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
	ofstream out("out_shellSort.txt");
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			out << matrix[i][j];
			out << ' ';
		}
		out << "\n";
	}
}


void shellSort(vector<int>& vec)
{
	int inc = 1, k = 0;
	while (inc < vec.size() + 1) {
		for (int i = inc; i < vec.size(); ++i) {
			int cur = vec[i];
			int j = i;
			while (j >= inc && vec[j - inc] > cur) {
				vec[j] = vec[j - inc];
				j -= inc;
			}
			vec[j] = cur;
		}
		k += 1;
		inc = pow(3, k) - 1;
	}
}


void matrixSort(vector< vector<int> >& matrix, int size)
{
	for (int i = 0; i < size; ++i) {
		vector<int> row;
		for (int j = 0; j < size; ++j) {
			row.push_back(matrix[i][j]);
		}
		shellSort(row);
		if (i % 2 == 0) {
			reverse(row.begin(), row.end());
		}
		for (int j = 0; j < size; ++j) {
			matrix[i][j] = row[j];
		}
	}
}


int main()
{
	int size = getSize();
	vector< vector<int> > matrix = convertTomatrix(size);
	matrixSort(matrix, size);
	matrixTofile(matrix, size);
	cout << endl << "Sorting is done! Check your 'out_shellSort.txt' file!" << endl;


	return 0;
}