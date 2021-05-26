/*
������� ����:
���� ��� �������, �� ���� �� ������� �������� n ����� (� ��������� n ��� height), ������ ������
���������� �������� � ����� ������� �� �������. ������ ������� � ���, ����� 
��������� �������� �� n ����� �� ���������� ����� ����� �� ������ ��������.
�� ���� ��� ����������� ���������� ������ ���� ������, ������ ������ ������ ������� ������ �� �������.
*/


#include <iostream>


void hanoiTowes(int height, int from_column, int to_column) {
	// ������, ���� �� ������� ������� ����� 1 ����.
	if (height == 1) {
		std::cout << "Disk number 1 moved from " << from_column << " column to " << to_column << " column." << std::endl;
	}
	else {
		// ������� ������ ���������� �������, �� ������� ����� ���������� ����.
		int temp_column = 6 - from_column - to_column;
		// � ������� 2 ����������� ������� ������������� ���� �� ���������� �������
		// �� ������ ����� ��������� ��������� �������.
		hanoiTowes(height - 1, from_column, temp_column);
		std::cout << "Disk number " << height << " moved from " << from_column << " column to " << to_column << " column." << std::endl;
		hanoiTowes(height - 1, temp_column, to_column);
	}
}


int main()
{
	int height, start, stop;
	std::cout << "Input heigh of towers, beginning tower and a final tower: " << std::endl;
	std::cin >> height >> start >> stop;
	hanoiTowes(height, start, stop);

	return 0;
}