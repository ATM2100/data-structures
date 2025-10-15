#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>
#include <vector>
#include <algorithm>

template<class T>
class BinaryTreeNode {
public:
    T val;
    BinaryTreeNode<T>* left, * right;
    BinaryTreeNode<T>() {

    }
    BinaryTreeNode<T>(T _val, BinaryTreeNode<T>* _left, BinaryTreeNode<T>* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
    ~BinaryTreeNode<T>()
    {
        
    }
};

template<class T>
class BinaryTree {
private:
    /* You fill in private member data. */

    /* Recommended, but not necessary helper function. */
    void put(BinaryTreeNode<T>* rover, BinaryTreeNode<T>* newNode);
    /* Recommended, but not necessary helper function. */
    std::string inorderStringP(BinaryTreeNode<T>* node);
public:
    BinaryTreeNode<T>* root;

    bool remove(BinaryTreeNode<T>* node);
    bool remove(const T& val);
    BinaryTree<T>* removeRec(BinaryTreeNode<T>* node, T val);
    /* Creates an empty binary tree. */
    BinaryTree();

    /* Does a deep copy of the tree. */
    BinaryTree(const BinaryTree<T>& tree);

    bool existsInRange(T min, T max) const;

    int countInRange(T min, T max) const;
    int countInRangeRec(BinaryTreeNode<T>* node, T min, T max) const;

    void inorderTraversal(void(*visit) (T& item)) const;
    void inorderTraversalRec(void(*visit) (T& item), BinaryTreeNode<T> *node) const;
    /* Add a given value to the Binary Tree.
     * Must maintain ordering!
     * Do NOT do ANY balancing!
     */
    void put(const T& val);

    /* Returns the height for the binary tree. */
    int getHeight();

    int getHeightRec(BinaryTreeNode<T>* node);

    /* Returns a string representation of the binary Tree in order. */
    std::string inorderString();

    /* Return the lowest common ancestor (LCA) of two values.
     * The LCA is the most immediate parent of both values.  For example:
     *      4
     *    /   \
     *   2     8
     *  / \   / \
     * 1   3 6   10
     * LCA(1, 3) = 2
     * LCA(1, 2) = 2
     * LCA(1, 6) = 4
     */
    T& lca(T& a, T& b);
    T& lca(BinaryTreeNode<T>* node, T& a, T& b);

    bool containsRec(BinaryTreeNode<T>* node, T val);
    bool contains(T val);
    /* Always free memory. */
    ~BinaryTree();
};

/* Since BinaryTree is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly
 * declared.)
 */
#include "binarytree.cpp"

#endif