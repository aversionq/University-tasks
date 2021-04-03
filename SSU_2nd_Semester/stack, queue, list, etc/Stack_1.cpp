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


stack<std::string>* wordEndcheck(stack<std::string>*& h, char restrictedLetter)
{
	stack<std::string>* res = NULL;
	stack<std::string>* h1 = NULL;
	while (h) {
		std::string x = pop<std::string>(h);
		if (x[x.size() - 1] != restrictedLetter) {
			push<std::string>(res, x);
		}
		while (h) {
			std::string y = pop<std::string>(h);
			if (x != y) {
				push<std::string>(h1, y);
			}
		}
		reverseStack<std::string>(h1);
		h = h1;
		h1 = NULL;
	}
	reverseStack<std::string>(res);


	return res;
}


int main()
{
	char restrictedLetter;
	std::cout << "Input restricted letter: ";
	std::cin >> restrictedLetter;
	int n = 5;
	stack<std::string>* head = NULL;
	std::string x;
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		push<std::string>(head, x);
	}
	reverseStack<std::string>(head);
	stack<std::string>* res = wordEndcheck(head, restrictedLetter);
	std::cout << std::endl << "New sequence:   ";
	while (res) {
		std::cout << pop<std::string>(res) << ' ';
	}


	return 0;
}