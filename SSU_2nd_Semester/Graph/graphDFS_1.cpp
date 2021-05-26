#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>


void addCycles(int start, int end, std::vector<int>& pr, std::vector< std::vector<int> >& cycles, std::vector< std::vector<int> >& cycles_sort) {
	int cur = end;
	std::vector<int> tmp;
	while (cur != start) {
		tmp.push_back(cur);
		cur = pr[cur];
	}
	tmp.push_back(start);
	std::reverse(tmp.begin(), tmp.end());
	cycles.push_back(tmp);
	std::sort(tmp.begin(), tmp.end());
	cycles_sort.push_back(tmp);
}


void findCycles(std::vector< std::vector<int> >& graph, int begin, std::vector<int>& pr, std::vector< std::vector<int> >& cycles, std::vector< std::vector<int> >& cycles_sort, std::vector<int>& used) {
	used[begin] = 1;
	for (int i = 0; i < graph[begin].size(); ++i) {
		if (pr[graph[begin][i]] == begin) {
			continue;
		}
		if (used[graph[begin][i]] == 0) {
			pr[graph[begin][i]] = begin;
			findCycles(graph, graph[begin][i], pr, cycles, cycles_sort, used);
		}
		else if (used[graph[begin][i]] == 1) {
			addCycles(graph[begin][i], begin, pr, cycles, cycles_sort);
		}
	}
	used[begin] = 0;
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
	//		Graph[i].push_back(x);
	//	}
	//}

	std::vector<int> used(Graph.size(), 0);
	std::vector< std::vector<int> > cycles_sort;
	std::vector<int> pr(7, -1);
	std::vector< std::vector<int> > cycles;

	findCycles(Graph, 0, pr, cycles, cycles_sort, used);
	for (int i = 0; i < cycles.size(); ++i) {
		std::cout << "Cycle : ";
		for (int j = 0; j < cycles[i].size(); ++j) {
			std::cout << cycles[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	
	return 0;
}