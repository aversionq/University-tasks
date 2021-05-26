#include <iostream>
#include <vector>


void nonAdjNodes(std::vector< std::vector<int> > graph, int node) {
	bool non_adj_check = true;
	std::cout << "Non adjacent nodes for " << node << " node: " << std::endl;
	for (int i = 0; i < graph.size(); ++i) {
		bool flag = true;
		for (int j = 0; j < graph[i].size(); ++j) {
			if (graph[i][j] == node || node == i) {
				flag = false;
				non_adj_check = false;
			}
		}
		if (flag) {
			std::cout << i << ' ';
		}
	}
	if (non_adj_check) {
		std::cout << std::endl << "There is no non adjacent nodes for " << node << " node.";
	}
}


int main()
{
	std::vector< std::vector<int> > Graph(7);
	Graph[0] = { 1, 2, 4, 5 };
	Graph[1] = { 0, 3 };
	Graph[2] = { 0, 5 };
	Graph[3] = { 1 };
	Graph[4] = { 0, 6 };
	Graph[5] = { 0, 2, 6 };
	Graph[6] = { 4, 5 };

	//int n, m, x;
	//std::cout << "Input amount of nodes: ";
	//std::cin >> n;
	//std::vector< std::vector<int> > Graph(n);
	//for (int i = 0; i < n; ++i) {
	//	std::cout << "Input amount of edges for " << i << " node: ";      //Создание списка смежности заполнением с клавиатуры
	//	std::cin >> m;
	//	for (int j = 0; j < m; ++j) {
	//		std::cout << "Input node: ";
	//		std::cin >> x;
	//		Graph[i][j] = x;
	//	}
	//}

	int your_node;
	std::cout << "Input your node: ";
	std::cin >> your_node;
	nonAdjNodes(Graph, your_node);

	return 0;
}