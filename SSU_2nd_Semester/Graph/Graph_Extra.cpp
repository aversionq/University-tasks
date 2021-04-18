#include <iostream>
#include <vector>


template <typename RType>
struct queue
{
	RType inf;
	queue<RType>* next;
};


template <typename RType>
void push(queue<RType>*& h, queue<RType>*& t, RType x)
{
	queue<RType>* r = new queue<RType>;
	r->inf = x;
	r->next = 0;
	if (!h && !t) {
		h = t = r;
	}
	else {
		t->next = r;
		t = r;
	}
}


template <typename RType>
RType pop(queue<RType>*& h, queue<RType>*& t)
{
	queue<RType>* r = h;
	RType i = h->inf;
	h = h->next;
	if (!h) {
		t = 0;
	}
	delete r;
	return i;
}


template <typename RType>
struct stack
{
	RType inf;
	stack<RType>* next;
};


template <typename RType>
void push(stack<RType>*& h, RType x)
{
	stack<RType>* r = new stack<RType>;
	r->inf = x;
	r->next = h;
	h = r;
}


template <typename RType>
RType pop(stack<RType>*& h)
{
	RType i = h->inf;
	stack<RType>* r = h;
	h = h->next;
	delete r;
	return i;
}


// Обход в ширину.
void BFtraversal(std::vector< std::vector<int> >& Graph, int n, int start)
{
	int y;
	queue<int>* head = 0;
	queue<int>* tail = 0;
	std::vector<int> check_apex(n, 0);
	check_apex[start] = 1;
	push(head, tail, start);
	std::cout << start << std::endl;

	while (head) {
		start = pop(head, tail);
		for (unsigned int i = 0; i < Graph[start].size(); ++i) {
			if (check_apex[Graph[start][i]] == 0) {
				check_apex[Graph[start][i]] = 1;
				y = Graph[start][i];
				push(head, tail, y);
				std::cout << y << std::endl;
			}
		}
	}
	// Проверка на наличие непосещённой вершины.
	for (unsigned int i = 0; i < check_apex.size(); ++i) {
		if (check_apex[i] == 0) {
			return BFtraversal(Graph, n, i);
		}
	}
}


// Обход в глубину.
void DFtraversal(std::vector< std::vector<int> >& Graph, int n, int start)
{
	int y;
	stack<int>* head = 0;
	std::vector<int> check_apex(n, 0);
	check_apex[start] = 1;
	push(head, start);
	std::cout << start << std::endl;

	while (head) {
		bool fl = false;
		start = head->inf;
		for (unsigned int i = 0; i < Graph[start].size(); ++i) {
			if (check_apex[Graph[start][i]] == 0) {
				y = Graph[start][i];
				fl = true;
				break;
			}
		}
		if (fl == true) {
			check_apex[y] = 1;
			push(head, y);
			std::cout << y << std::endl;
		}
		else {
			pop(head);
		}
	}
	// Проверка на наличие непосещённой вершины.
	for (unsigned int i = 0; i < check_apex.size(); ++i) {
		if (check_apex[i] == 0) {
			return DFtraversal(Graph, n, i);
		}
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

	std::cout << "Breadth-first traversal (V shirinu): " << std::endl;
	BFtraversal(Graph, 7, 0);

	std::cout << std:: endl << "Depth-first traversal (V glubinu): " << std::endl;
	DFtraversal(Graph, 7, 0);

	return 0;
}