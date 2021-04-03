#include <iostream>
#include <string>
#include <vector>


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


std::string getString()
{
	std::string postfixStr;
	std::cout << "Input your postfix thing: ";
	getline(std::cin, postfixStr);
	return postfixStr;
}


//bool isDigit(char letter)
//{
//	std::vector<char> stringDigits {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
//	for (int i = 0; i < stringDigits.size(); ++i) {
//		std::cout << stringDigits[i] << ' ';
//	}
//
//
//	return true;
//}


stack<int>* calcPostfixstring(std::string postfixStr)
{
	stack<int>* head = 0;
	int convertToint;
	for (int i = 0; i < postfixStr.size(); ++i) {
		if (isdigit(postfixStr[i])) {
			convertToint = postfixStr[i] - '0';
			push(head, convertToint);
		}
		else {
			int result;
			int digit1 = pop(head);
			int digit2 = pop(head);
			switch (postfixStr[i])
			{
			case('+'): result = (digit1 + digit2); break;
			case('-'): result = (digit2 - digit1); break;
			case('*'): result = (digit1 * digit2); break;
			case('/'): result = (digit2 / digit1); break;
			}
			push(head, result);
		}
	}


	return head;
}


int main()
{
	std::string mainString = getString();
	stack<int>* x = calcPostfixstring(mainString);
	std::cout << pop(x) << std::endl;


	return 0;
}