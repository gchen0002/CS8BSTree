#include "BSTree.h"
#ifndef BSTREE_CPP
#define BSTREE_CPP
template<typename T>
void BSTree<T>::push(Node<T> *&node, const T &data)
{
    ///Base case
    if(node == nullptr){
        node = new Node<T>;
        node->data = data;
        return;
    }
    /// else check whether I need to call the recursion on the left or the right child
    if(data < node->data){
        push(node->left, data);
    } else {
        push(node->right, data);
    }
}

template<typename T>
void BSTree<T>::inorder(Node<T> *node, int(*f)(T &data))
{
    if(node == nullptr){
        return;
    }
    inorder(node->left, f);
    f(node->data);
    inorder(node->right, f);
}


template<typename T>
void BSTree<T>::preorder(Node<T> *node, int(*f)(T &data))
{
    if(node == nullptr){
        return;
    }
    f(node->data);
    preorder(node->left, f);
    preorder(node->right, f);
}

template<typename T>
void BSTree<T>::postorder(Node<T> *node, int(*f)(T &data))
{
    if(node == nullptr){
        return;
    }
    postorder(node->left, f);
    postorder(node->right, f);
    f(node->data);
}

template<typename T>
void BSTree<T>::remove(Node<T>*& node, const T& data){
    if(!node) return;
    if(isLeaf(node)){
        delete node;
        return;
    }
    else if(hasOneChild(node)){
        node = getOneChild(node);
    }
    else if(hasChildren(node)){
        Node *& n = getNextSuccessor(node);
        swap(n->data, node->data);
        remove(n, n->data);
    }
}

// PUBLIC
template<typename T>
void BSTree<T>::push(const T &data)
{
    push(root, data);
}

template<typename T>
void BSTree<T>::inorder(int(*f)(T &data))
{
    inorder(root, f);
}

template<typename T>
void BSTree<T>::preorder(int(*f)(T &data))
{
    preorder(root, f);
}

template<typename T>
void BSTree<T>::postorder(int(*f)(T &data))
{
    postorder(root, f);
}

#endif