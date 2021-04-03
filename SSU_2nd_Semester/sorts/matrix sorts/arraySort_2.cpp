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
	ifstream in("in_countSort.txt");
	int size;
	in >> size;


	return size;
}


vector< vector<int> > convertTomatrix(int size)
{
	ifstream in("in_countSort.txt");
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


void countSort(vector<int>& vec, int arrMax, int arrMin)
{
	int xtr_size = arrMax - arrMin + 1;
	vector<int> extra(xtr_size, 0);
	for (int i = 0; i < vec.size(); ++i) {
		extra[vec[i]]++;
	}
	int index = 0;
	for (int i = 0; i < xtr_size; ++i) {
		for (int j = 0; j < extra[i]; ++j) {
			vec[index++] = i + arrMin;
		}
	}
}


void matrixTofile(vector< vector<int> >& matrix, int size)
{
	ofstream out("out_countSort.txt");
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			out << matrix[i][j];
			out << ' ';
		}
		out << "\n";
	}
}


void matrixSort(vector< vector<int> >& matrix, int size)
{
	for (int i = 0; i < size; ++i) {
		vector<int> column;
		int column_max, column_min;
		for (int j = 0; j < size; ++j) {
			column.push_back(matrix[j][i]);
		}


		column_max = *max_element(column.begin(), column.end());
		column_min = *min_element(column.begin(), column.end());
		countSort(column, column_max, column_min);


		for (int j = 0; j < column.size(); ++j) {
			matrix[j][i] = column[j];
		}
	}
	matrixTofile(matrix, size);
}


int main()
{
	int size = getSize();
	convertTomatrix(size);
	vector< vector<int> > matrix = convertTomatrix(size);
	matrixSort(matrix, size);
	cout << endl << "Sorting done! Check your 'out_countSort.txt' file!" << endl;


	return 0;
}