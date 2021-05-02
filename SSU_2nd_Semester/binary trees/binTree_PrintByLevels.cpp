#include <iostream>
#include <queue>
#include <string>
#include <cassert>
#include <queue>


struct tree
{
	int inf;
	tree* right;
	tree* left;
};


tree* node(int x) {
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = 0;
	return n;
}


void create(tree*& tr, int n) {
	int x;
	std::vector<int> nodes;
	if (n > 0) {
		std::cout << "Input element: ";
		std::cin >> x;
		tr = node(x);
		int nl = n / 2;
		int nr = n - nl - 1;
		create(tr->left, nl);
		create(tr->right, nr);
	}
}


void preorder(tree* tr) {
	if (tr) {
		std::cout << tr->inf << " ";
		preorder(tr->left);
		preorder(tr->right);
	}
}


int lefth(tree* tr) {
	int k = 0;
	tree* x = tr;
	while (x)
	{
		k++;
		x = x->left;
	}
	return k - 1;
}


int righth(tree* tr) {
	int k = 0;
	tree* x = tr;
	while (x)
	{
		k++;
		x = x->right;
	}
	return k - 1;
}


void add(tree* tr, int x) {
	tree* n = node(x);
	tree* y = tr;
	if (lefth(tr) == righth(tr)) {
		do {
			y = y->left;
		} while (y->left);
		if (!y->left) {
			y->left = n;
		}
		else {
			y->right = n;
		}
	}
	else {
		do {
			y = y->right;
		} while (y->right);
		if (!y->left) {
			y->left = n;
		}
		else {
			y->right = n;
		}
	}
}


void find(tree* tr, int x, tree*& res) {
	if (tr) {
		if (tr->inf == x) {
			res = tr;
		}
		else {
			if (tr->left) {
				find(tr->left, x, res);
			}
			if (tr->right) {
				find(tr->right, x, res);
			}
		}
	}
}


void del_n(tree* tr, int val) {
	tree* y;
	find(tr, val, y);
	std::cout << y->inf << std::endl;
	if (y) {
		if (lefth(tr) == 0) {
			tr = 0;
		}
		else if (lefth(tr) != righth(tr)) {
			tree* x = tr->left;
			while (x->left->left) {
				x = x->left;
			}
			if (x->right) {
				if (x->right->inf == val) {
					x->right = 0;
				}
				else {
					y->inf = x->right->inf;
					x->right = 0;
				}
				delete x->right;
			}
			else {
				if (x->left->inf == val) {
					x->left = 0;
				}
				else {
					y->inf = x->left->inf;
					x->left = 0;
				}
				delete x->left;
			}
		}
		else {
			tree* x = tr->right;
			while (x->right->right) {
				x = x->right;
			}
			if (x->right) {
				if (x->right->inf == val) {
					x->right = 0;
				}
				else {
					y->inf = x->right->inf;
					x->right = 0;
				}
				delete x->right;
			}
			else {
				if (x->left->inf == val) {
					x->left = 0;
				}
				else {
					y->inf = x->left->inf;
					x->left = 0;
				}
				delete x->left;
			}
		}
	}
}


void print(tree* tr, int k) {
	if (!tr) {
		std::cout << "Empty tree\n";
	}
	else {
		std::queue<tree*> cur, next;
		tree* r = tr;
		cur.push(r);
		int j = 0;
		while (cur.size()) {
			if (j == 0) {
				for (int i = 0; i < (int)pow(2.0, k) - 1; ++i) {
					std::cout << ' ';
				}
			}
			tree* buf = cur.front();
			cur.pop();
			j++;
			if (buf) {
				std::cout << buf->inf;
				next.push(buf->left);
				next.push(buf->right);
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; ++i) {
					std::cout << ' ';
				}
			}
			if (!buf) {
				for (int i = 0; i < (int)pow(2.0, k + 1) - 1; ++i) {
					std::cout << ' ';
				}
				std::cout << ' ';
			}
			if (cur.empty()) {
				std::cout << std::endl;
				swap(cur, next);
				j = 0;
				k--;
			}
		}
	}
}


void pop_front(std::vector<int>& vec)
{
	assert(!vec.empty());
	vec.erase(vec.begin());
}


int treeHeight(tree* tr) {
	if (tr == 0) {
		return 0;
	}
	int left_side, right_side, height = 0;
	// Считаем высоту слева и справа.
	left_side = tr->left ? treeHeight(tr->left) + 1 : 0;
	right_side = tr->right ? treeHeight(tr->right) + 1 : 0;
	// Определяем, где высота была больше, соответственно, это и будет высота дерева.
	height += right_side > left_side ? right_side : left_side;
	return height;
}


std::vector<int> getNodeArray(tree* tr) {
	std::vector<int> nodes;
	std::queue<tree*> head;
	head.push(tr);

	while (!head.empty()) {
		tree* tmp = head.front();
		head.pop();
		nodes.push_back(tmp->inf);
		if (tmp->left) {
			head.push(tmp->left);
		}
		if (tmp->right) {
			head.push(tmp->right);
		}
	}
	return nodes;
}


void printByLevels(tree* tr, bool fully_balanced, std::vector<int> nodes) {
	if (!tr) {
		return;
	}
	int height = treeHeight(tr);
	if (fully_balanced) {
		for (int i = 1; i <= height + 1; ++i) {
			std::cout << "Row " << i << ' ';
			for (int j = 0; j < pow(2, i) - pow(2, i - 1); ++j) {
				if (!nodes.empty()) {
					std::cout << nodes[0] << ' ';
					pop_front(nodes);
				}
				else {
					break;
				}
			}
			std::cout << std::endl;
		}
	}
	else {
		int difference;
		for (int i = 1; i <= height + 1; ++i) {
			std::cout << "Row " << i << ' ';
			difference = (i == height + 1) ? 1 : 0;
			for (int j = 0; j < pow(2, i) - pow(2, i - 1) - difference; ++j) {
				if (!nodes.empty()) {
					std::cout << nodes[0] << ' ';
					pop_front(nodes);
				}
				else {
					break;
				}
			}
			std::cout << std::endl;
		}
	}
}


int main()
{
	int n, to_find;
	std::cout << "Input amount of nodes: ";
	std::cin >> n;
	std::cout << std::endl;
	int k = log((float)n) / log((float)2.0);
	tree* root = 0;

	std::vector<int> tree_nodes;
	create(root, n);
	std::cout << std::endl;
	print(root, k);

	bool fully_balanced = n % 2 == 0 ? false : true;
	int height = treeHeight(root);
	std::vector<int> nodes_by_levels = getNodeArray(root);
	printByLevels(root, fully_balanced, nodes_by_levels);

	return 0;
}