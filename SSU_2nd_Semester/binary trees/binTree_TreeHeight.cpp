#include <iostream>


struct tree
{
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};


tree* node(int x) {
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = 0;
	n->parent = 0;
	return n;
}


void insert(tree*& tr, int x) {
	tree* n = node(x);
	if (!tr) {
		tr = n;
	}
	else {
		tree* y = tr;
		while (y) {
			if (n->inf > y->inf) {
				if (y->right) {
					y = y->right;
				}
				else {
					n->parent = y;
					y->right = n;
					break;
				}
			}
			else if (n->inf < y->inf) {
				if (y->left) {
					y = y->left;
				}
				else {
					n->parent = y;
					y->left = n;
					break;
				}
			}
		}
	}
}


void inorder(tree* tr) {
	if (tr) {
		inorder(tr->left);
		std::cout << tr->inf << " ";
		inorder(tr->right);
	}
}


tree* find(tree* tr, int x) {
	if (!tr || x == tr->inf) {
		return tr;
	}
	if (x < tr->inf) {
		return find(tr->left, x);
	}
	else {
		return find(tr->right, x);
	}
}


tree* Min(tree* tr) {
	if (!tr->left) {
		return tr;
	}
	else {
		return Min(tr->left);
	}
}


tree* Max(tree* tr) {
	if (!tr->right) {
		return tr;
	}
	else {
		return Max(tr->right);
	}
}


tree* Next(tree* tr, int x) {
	tree* n = find(tr, x);
	if (n->right) {
		return Min(n->right);
	}
	tree* y = n->parent;
	while (y && n == y->right) {
		n = y;
		y = y->parent;
	}
	return y;
}


tree* Prev(tree* tr, int x) {
	tree* n = find(tr, x);
	if (n->left) {
		return Max(n->left);
	}
	tree* y = n->parent;
	while (y && n == y->left) {
		n = y;
		y = y->parent;
	}
	return y;
}


void Delete(tree*& tr, tree* v) {
	tree* p = v->parent;
	if (!p) {
		tr = 0;
	}
	else if (!v->left && !v->right) {
		if (p->left == v) {
			p->left = 0;
		}
		if (p->right == v) {
			p->right = 0;
		}
		delete v;
	}
	else if (!v->left || !v->right) {
		if (!p) {
			if (!v->left) {
				tr = v->right;
				v->parent = 0;
			}
			else {
				tr = v->left;
				v->parent = 0;
			}
		}
		else {
			if (!v->left) {
				if (p->left == v) {
					p->left = v->right;
				}
				else {
					p->right = v->right;
				}
				v->right->parent = p;
			}
			else {
				if (p->left == v) {
					p->left = v->left;
				}
				else {
					p->right = v->left;
				}
			}
			delete v;
		}
	}
	else {
		tree* succ = Next(tr, v->inf);
		v->inf = succ->inf;
		if (succ->parent->left == succ) {
			succ->parent->left = succ->right;
			if (succ->right) {
				succ->right->parent = succ->parent;
			}
		}
		else {
			succ->parent->right = succ->parent;
		}
		delete succ;
	}
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


int main()
{
	tree* root = 0;
	int x, n;
	std::cout << "Input amount of nodes: ";
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		insert(root, x);
	}
	std::cout << "Height of tree is " << treeHeight(root);

	return 0;
}