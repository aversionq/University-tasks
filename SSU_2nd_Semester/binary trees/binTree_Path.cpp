#include <iostream>
#include <queue>
#include <string>


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


std::vector<int> create(tree*& tr, int n) {
	int x;
	std::vector<int> nodes;
	if (n > 0) {
		std::cout << "Input element: ";
		std::cin >> x;
		nodes.push_back(x);
		tr = node(x);
		int nl = n / 2;
		int nr = n - nl - 1;
		create(tr->left, nl);
		create(tr->right, nr);
	}
	return nodes;
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


bool isValid(std::vector<int> values, int el) {
	bool flag = false;
	for (int i = 0; i < values.size(); ++i) {
		if (el == values[i]) {
			flag = true;
		}
	}
	return flag;
}


void getLeaves(tree* tr, std::vector<int>& leaves) {
	if (!tr->left && !tr->right) {
		leaves.push_back(tr->inf);
	}
	if (tr->left) {
		getLeaves(tr->left, leaves);
	}
	if (tr->right) {
		getLeaves(tr->right, leaves);
	}
}


void getPathsToLeaf(tree* tr, int leaf, std::vector<int> values, std::string& result) {
	if (!tr) {
		return;
	}
	if (tr->left == 0 && tr->right == 0 && tr->inf == leaf) {
		values.push_back(tr->inf);
		result += std::to_string(values[0]);
		for (int i = 1; i < values.size(); ++i) {
			result += "->";
			result += std::to_string(values[i]);
		}
		values.pop_back();
		return;
	}
	values.push_back(tr->inf);
	getPathsToLeaf(tr->left, leaf, values, result);
	getPathsToLeaf(tr->right, leaf, values, result);
	values.pop_back();
}


int main()
{
	int n, to_find;
	std::cout << "Input amount of nodes: ";
	std::cin >> n;
	std::cout << std::endl;
	int k = log((float)n) / log((float)2.0);
	tree* root = 0;
	tree* start_node;

	std::vector<int> tree_nodes;
	tree_nodes = create(root, n);
	std::cout << std::endl;
	print(root, k);

	std::cout << "Input node: ";
	std::cin >> to_find;
	find(root, to_find, start_node);
	std::vector<int> leaves;
	getLeaves(start_node, leaves);
	std::cout << std::endl << "Available leaves for your node: " << std::endl;
	for (int i = 0; i < leaves.size(); ++i) {
		std::cout << leaves[i] << ' ';
	}

	int choice;
	std::string res_str = "";
	std::vector<int> node_values;
	std::cout << std::endl << "Pick one of these leaves: " << std::endl;
	std::cin >> choice;

	if (isValid(leaves, choice)) {
		getPathsToLeaf(start_node, choice, node_values, res_str);
		std::cout << std::endl << "Path: " << res_str << std::endl;
	}
	else {
		std::cout << "That leaf does not exist in this tree!" << std::endl;
	}

	return 0;
}
