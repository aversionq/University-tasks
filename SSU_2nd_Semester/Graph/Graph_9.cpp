#include <iostream>
#include <vector>
#include <fstream>


void getSemiExodus(std::vector< std::vector<int> > oriented_graph) {
	for (int i = 0; i < oriented_graph.size(); ++i) {
		std::cout << "Semi-exodus of " << i << " node: " << oriented_graph[i].size() << std::endl;
	}
}


int main()
{
	std::vector< std::vector<int> > oriented_graph(5);
	oriented_graph[0] = { 2 };
	oriented_graph[1] = { 0, 2 };
	oriented_graph[2] = { 4 };
	oriented_graph[3] = { 0, 1 };
	oriented_graph[4] = { 0, 1 };

	//int n, m, x;
	//std::cout << "Input amount of nodes: ";
	//std::cin >> n;
	//std::vector< std::vector<int> > oriented_graph(n);
	//for (int i = 0; i < n; ++i) {
	//	std::cout << "Input amount of edges for " << i << " node: ";      //Создание списка смежности заполнением с клавиатуры
	//	std::cin >> m;
	//	for (int j = 0; j < m; ++j) {
	//		std::cout << "Input node: ";
	//		std::cin >> x;
	//		oriented_graph[i].push_back(x);
	//	}
	//}

	getSemiExodus(oriented_graph);

	return 0;
}