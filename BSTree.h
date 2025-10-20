#ifndef BSTREE_H
#define BSTREE_H

#include "Node.h"

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
public:
    void push(const T& data);
    void inorder(int (*f)(T& data));
    void preorder(int (*f)(T& data));
    void postorder(int (*f)(T& data));

};

#include "BSTree.cpp"

#endif //BSTREE_H