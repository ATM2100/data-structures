#ifdef BINARY_TREE_H
#define BINARY_TREE_H
#include <sstream>
#include <iostream>

template<class T>
BinaryTree<T>::BinaryTree() {
	root = NULL;
}

template<class T>
BinaryTree<T>* BinaryTree<T>::removeRec(BinaryTreeNode<T>* node, T val)
{
	if (node->val > val)
	{
		if (node->left == NULL)
			return NULL;
		return removeRec(node->left, val);
	}
	else if (node->val < val)
	{
		return removeRec(node->right, val);
	}
}

template<class T>
bool BinaryTree<T>::remove(const T& val)
{
	if (!contains(val))
	{
		return false;
	}

	removeRec(root, val);
	
	return true;
}

template<class T>
bool BinaryTree<T>::existsInRange(T min, T max) const
{
	if (countInRange(min, max) == 0)
		return false;

	return true;
}

template<class T>
int BinaryTree<T>::countInRange(T min, T max) const
{
	return countInRangeRec(root, min, max);
}

template<class T>
int BinaryTree<T>::countInRangeRec(BinaryTreeNode<T>* node, T min, T max) const
{
	if (node == NULL)
		return 0;

	if (node->val >= min && node->val <= max)
	{
		return (countInRangeRec(node->left, min, max) + countInRangeRec(node->right, min, max) + 1);
	}

	if (node->val < min)
		return countInRangeRec(node->right, min, max);

	if (node->val > max)
		return countInRangeRec(node->left, min, max);

}

template<class T>
void BinaryTree<T>::inorderTraversalRec(void(*visit) (T& item), BinaryTreeNode<T> *node) const
{
	if (node == NULL)
	{
		return;
	}

	std::string ret = "";

	inorderTraversalRec(visit, node->left);

	visit(node->val);

	inorderTraversalRec(visit, node->right);
}



template<class T>
void BinaryTree<T>::inorderTraversal(void(*visit) (T& item)) const
{
	inorderTraversalRec(visit, root);
}

template<class T>
T& BinaryTree<T>::lca(BinaryTreeNode<T> *node, T& a, T& b)
{
	if (node->val > a && node->val > b)
		return lca(node->left, a, b);

	if (node->val < a && node->val < b)
	{
		return lca(node->right, a, b);
	}

	return node->val;
}

template<class T>
T& BinaryTree<T>::lca(T& a, T& b)
{
	if (!(contains(a) && contains(b)))
	{
		T nothing = root->val;
		return nothing;
	}

	if (root->val == a || root->val == b)
	{
		return root->val;
	}

	if (a == b)
		return a;

	return lca(root, a, b);

	/*
	while (rover->left != NULL && rover->right != NULL)
	{
		if (rover->val < a && rover->val < b)
		{
			rover = rover->right;
		}
		else if (rover->val > a && rover->val > b)
		{
			rover = rover->left;
		}

		return rover->val;
	}*/
}

template<class T>
int BinaryTree<T>::getHeight()
{
	return getHeightRec(root) + 1;
}

template<class T>
int BinaryTree<T>::getHeightRec(BinaryTreeNode<T>* node)
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (node->left != NULL)
	{
		leftHeight = getHeightRec(node->left);
		++leftHeight;
	}

	if (node->right != NULL)
	{
		rightHeight = getHeightRec(node->right);
		rightHeight++;
	}

	return (rightHeight > leftHeight) ? rightHeight : leftHeight;
}

template<class T>
void BinaryTree<T>::put(const T& val)
{
	BinaryTreeNode<T>* node = new BinaryTreeNode<T>(val, NULL, NULL);
	if (root == NULL)
	{
		root = node;
		return;
	}

	BinaryTreeNode<T>* rover = root;

	while (rover) {
		if (rover->val < val)
		{
			if (rover->right == NULL) {
				rover->right = node;
				return;
			}
			rover = rover->right;
		}
		else
		{
			if (rover->left == NULL) {
				rover->left = node;
				return;
			}
			rover = rover->left;
		}
	}

	return;
}

template<class T>
std::string BinaryTree<T>::inorderStringP(BinaryTreeNode<T>* node)
{
	if (node == NULL)
	{
		return "";
	}

	std::string ret = "";

	ret.append(inorderStringP(node->left));

	std::ostringstream stream;
	stream << node->val;
	ret.append(stream.str() + ' ');

	ret.append(inorderStringP(node->right));

	return ret;
}

template<class T>
std::string BinaryTree<T>::inorderString()
{
	return inorderStringP(root);
}

template<class T>
bool BinaryTree<T>::containsRec(BinaryTreeNode<T>* node, T val)
{
	if (node == NULL) { return false; }
	if (node->val == val) { return true; }

	if (node->val < val) { return containsRec(node->right, val); }
	return containsRec(node->left, val);
}

template<class T>
bool BinaryTree<T>::contains(T val) {
	return containsRec(root, val);
}

template<class T>
BinaryTree<T>::~BinaryTree() {
	bool onStack = remove(root);
	root = NULL;
}

template<class T>
bool BinaryTree<T>::remove(BinaryTreeNode<T>* node)
{
	if (node == NULL)
	{
		return false;
	}

	if (node->left != NULL)
	{
		remove(node->left);
		node->left = NULL;
	}

	if (node->right != NULL)
	{
		remove(node->right);
		node->right = NULL;
	}

	delete node;
	return true;

}

#endif