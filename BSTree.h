#ifndef BSTREE_H
#define BSTREE_H

#include "Node.h"
#include <queue>
template<typename T>
class BSTree
{
protected:
    Node<T>* root = nullptr;
    void push(Node<T>* &node, const T& data);
    void inorder(Node<T>* node, int (*f)(T& data));
    void preorder(Node<T>* node, int (*f)(T& data));
    void postorder(Node<T>* node, int (*f)(T& data));
    void remove(Node<T>*& node, const T& data);

    // Helper functions for remove
    bool isLeaf(Node<T>* node) const;
    bool hasOneChild(Node<T>* node) const;
    bool hasTwoChildren(Node<T>* node) const;
    Node<T>* getOneChild(Node<T>* node);
    Node<T>*& getSuccessor(Node<T>* node);
    
    void copyTree(Node<T>*& thisNode, Node<T>* otherNode);
    void deleteSubtree(Node<T>*& node);
public:
    enum Traversal { PREORDER, INORDER, POSTORDER, BREADTHFIRST };

    // traversal by enum
    void traverse(Traversal t, int (*f)(T& data));
    BSTree();
    // big 3
    ~BSTree();
    BSTree(const BSTree<T>& other);
    BSTree<T> operator=(const BSTree<T>& other);

    
    void clear();
    void push(const T& data);
    void remove(const T& data);
    void inorder(int (*f)(T& data));
    void preorder(int (*f)(T& data));
    void postorder(int (*f)(T& data));
    void BFS(int (*f)(T& data));
};

#include "BSTree.cpp"

#endif //BSTREE_H