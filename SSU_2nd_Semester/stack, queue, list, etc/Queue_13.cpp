#include <iostream>


template <typename RType>
struct queue
{
	RType inf;
	queue<RType>* next;
};


template <typename RType>
void push(queue<RType>*&h, queue<RType>*&t, RType x)
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
std::pair< queue<RType>*, queue<RType>* > insertNumafterX(queue<RType>*& h, queue<RType>*& t, int to_divide)
{
	queue<RType>* res_head = 0;
	queue<RType>* res_tail = 0;
	RType x, min_el, check_init = 0, new_value;


	while (t) {
		x = pop(h, t);
		if (x % to_divide == 0) {
			std::cout << "Element multiple of X found detected, input value of a new element: ";
			std::cin >> new_value;
			push<int>(res_head, res_tail, x);
			push<int>(res_head, res_tail, new_value);
		}
		else {
			push<int>(res_head, res_tail, x);
		}
	}


	return std::pair< queue<RType>*, queue<RType>*>(res_head, res_tail);
}


int main()
{
	int n, element_to_input, x;
	std::cout << "Input amount of numbers: ";
	std::cin >> n;
	std::cout << "Input X: ";
	std::cin >> x;


	queue<int>* head = 0;
	queue<int>* tail = 0;
	std::cout << "Input your values: " << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cin >> element_to_input;
		push<int>(head, tail, element_to_input);
	}


	queue<int>* result_head = insertNumafterX<int>(head, tail, x).first;
	queue<int>* result_tail = insertNumafterX<int>(head, tail, x).second;
	std::cout << std::endl << "New sequence:   ";
	while (result_head)
	{
		std::cout << pop(result_head, result_tail) << ' ';
	}
}