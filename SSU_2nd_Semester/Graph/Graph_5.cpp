#include <iostream>
#include <vector>
#include <algorithm>


void printArray(std::vector<int> vec) {
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << ' ';
	}
	std::cout << std::endl;
}


void insertEdge(std::vector< std::vector<int> > graph, int node_A, int node_B) {
	bool flag = false;
	for (int i = 0; i < graph[node_A].size(); ++i) {
		if (graph[node_A][i] == node_B) {
			flag = true;
		}
	}
	if (!flag) {
		graph[node_A].push_back(node_B);
		graph[node_B].push_back(node_A);
		std::sort(graph[node_A].begin(), graph[node_A].end());
		std::sort(graph[node_B].begin(), graph[node_B].end());
		std::cout << "New adjacency list: " << std::endl;
		for (int i = 0; i < graph.size(); ++i) {
			std::cout << '[' << i << "]\t";
			printArray(graph[i]);
		}
	}
	else {
		std::cout << std::endl << "There is already an edge between those nodes.";
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

	std::cout << "New adjacency list: " << std::endl;
	for (int i = 0; i < Graph.size(); ++i) {
		std::cout << '[' << i << "]\t";
		printArray(Graph[i]);
	}

	int node_A, node_B;
	std::cout << "Input 2 nodes that you want to connect: " << std::endl;
	std::cin >> node_A >> node_B;
	insertEdge(Graph, node_A, node_B);

	return 0;
}