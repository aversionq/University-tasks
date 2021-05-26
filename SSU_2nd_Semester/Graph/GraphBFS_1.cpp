#include <iostream>
#include <vector>


void findSource(std::vector< std::vector<int> > graph) {
	std::vector<int> checked(graph.size(), 0);
	std::vector<int> sources;
	for (int i = 0; i < graph.size(); ++i) {
		for (int j = 0; j < graph[i].size(); ++j) {
			checked[graph[i][j]] = 1;
		}
	}
	for (int i = 0; i < checked.size(); ++i) {
		if (checked[i] == 0) {
			sources.push_back(i);
		}
	}
	if (sources.size() > 0) {
		std::cout << std::endl << "Nodes of sources in this graph: ";
		for (int i = 0; i < sources.size(); ++i) {
			std::cout << sources[i] << ' ';
		}
	}
	else {
		std::cout << std::endl << "There are no any sources in this graph.";
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

	//	int n, m, x;
	//	std::cout << "Input amount of nodes: ";
	//	std::cin >> n;
	//	std::vector< std::vector<int> > oriented_graph(n);
	//	for (int i = 0; i < n; ++i) {
	//		std::cout << "Input amount of edges for " << i << " node: ";      //Создание списка смежности заполнением с клавиатуры
	//		std::cin >> m;
	//		for (int j = 0; j < m; ++j) {
	//			std::cout << "Input node: ";
	//			std::cin >> x;
	//			oriented_graph[i].push_back(x);
	//		}
	//	}

	findSource(oriented_graph);

	return 0;
}