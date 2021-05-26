/*
Правила игры:
Даны три стержня, на один из которых нанизаны n колец (в программе n это height), причём кольца
отличаются размером и лежат меньшее на большем. Задача состоит в том, чтобы 
перенести пирамиду из n колец за наименьшее число ходов на другой стержень.
За один раз разрешается переносить только одно кольцо, причём нельзя класть большее кольцо на меньшее.
*/


#include <iostream>


void hanoiTowes(int height, int from_column, int to_column) {
	// Случай, если на столбце остался всего 1 диск.
	if (height == 1) {
		std::cout << "Disk number 1 moved from " << from_column << " column to " << to_column << " column." << std::endl;
	}
	else {
		// Находим индекс временного столбца, на который можно переложить диск.
		int temp_column = 6 - from_column - to_column;
		// С помощью 2 рекурсивных функций перекладываем диск со стартового столбца
		// на нужный через временный свободный столбец.
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