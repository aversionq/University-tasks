#include <iostream>
#include <string>
#include <cstring>


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


template <typename RType>
void reverseStack(stack<RType>*& h)
{
	stack<RType>* head1 = NULL;
	while (h) {
		push<RType>(head1, pop<RType>(h));
	}
	h = head1;
}


template <typename RType>
stack<RType>* result(stack<RType>*& h)
{
	stack<RType>* res = NULL;
	stack<RType>* h1 = NULL;
	while (h) {
		RType x = pop<RType>(h);
		push<RType>(res, x);
		while (h) {
			RType y = pop<RType>(h);
			if (x != y) {
				push<RType>(h1, y);
			}
		}
		reverseStack<RType>(h1);
		h = h1;
		h1 = NULL;
	}
	reverseStack<RType>(res);


	return res;
}


template <typename RType>
stack<RType>* insertNumbeforeMin(stack<RType>*& h)
{
	stack<RType>* h1 = NULL;
	stack<RType>* final = NULL;
	int x, min_el, check_init = 0, check_min, new_value;
	while (h) {
		x = pop(h);
		if (check_init == 0) {
			min_el = x;
			check_init++;
		}
		if (x < min_el) {
			min_el = x;
		}
		push(h1, x);
	}
	while (h1) {
		check_min = pop(h1);
		if (check_min == min_el) {
			std::cout << std::endl << "Min value detected, input new element: ";
			std::cin >> new_value;
			push(final, new_value);
			push(final, check_min);
		}
		else {
			push(final, check_min);
		}
	}


	return final;
}


int main()
{
	int n;
	std::cout << "Input amount of numbers: ";
	std::cin >> n;
	stack<int>* head = NULL;
	int x;
	std::cout << std::endl << "Input numbers: " << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		push<int>(head, x);
	}
	stack<int>* finalRes = insertNumbeforeMin<int>(head);
	reverseStack(finalRes);
	std::cout << std::endl << "New sequence:   ";
	while (finalRes) {
		std::cout << pop<int>(finalRes) << ' ';
	}


	return 0;
}