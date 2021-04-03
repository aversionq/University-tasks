#include <iostream>


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
std::pair< queue<RType>*, queue<RType>*> insertMinbeforeMax(queue<RType>*& h, queue<RType>*& t)
{
	queue<RType>* temp_h = 0;
	queue<RType>* temp_t = 0;
	queue<RType>* res_head = 0;
	queue<RType>* res_tail = 0;
	RType x, min_el, max_el, check_init = 0;


	while (t) {
		x = pop(h, t);
		if (check_init == 0) {
			min_el = x;
			max_el = x;
			check_init++;
		}
		if (x < min_el) {
			min_el = x;
		}
		else if (x > max_el) {
			max_el = x;
		}
		push(temp_h, temp_t, x);
	}


	while (temp_t) {
		x = pop(temp_h, temp_t);
		if (x == max_el) {
			push(res_head, res_tail, min_el);
			push(res_head, res_tail, x);
		}
		else {
			push(res_head, res_tail, x);
		}
	}


	return std::pair< queue<RType>*, queue<RType>*>(res_head, res_tail);
}


int main()
{
	int n, element_to_input;
	std::cout << "Input amount of numbers: ";
	std::cin >> n;


	queue<int>* head = 0;
	queue<int>* tail = 0;
	std::cout << "Input your values: " << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cin >> element_to_input;
		push<int>(head, tail, element_to_input);
	}


	queue<int>* result_head = insertMinbeforeMax(head, tail).first;
	queue<int>* result_tail = insertMinbeforeMax(head, tail).second;
	std::cout << std::endl << "New sequence:   ";
	while (result_head)
	{
		std::cout << pop(result_head, result_tail) << ' ';
	}
}