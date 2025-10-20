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
bool BSTree<T>::isLeaf(Node<T>* node) const {
    return !node->left && !node->right;
}

template<typename T>
bool BSTree<T>::hasOneChild(Node<T>* node) const {
    return (node->left && !node->right) || (!node->left && node->right);
}

template<typename T>
bool BSTree<T>::hasTwoChildren(Node<T>* node) const {
    return node->left && node->right;
}

template<typename T>
Node<T>* BSTree<T>::getOneChild(Node<T>* node) {
    return (node->left) ? node->left : node->right;
}

template<typename T>
Node<T>*& BSTree<T>::getSuccessor(Node<T>* node) {
    Node<T>* current = node->right;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

template<typename T>
void BSTree<T>::remove(Node<T>*& node, const T& data) {
    if (!node) return;

    if (data < node->data) {
        remove(node->left, data);
    } else if (data > node->data) {
        remove(node->right, data);
    } else { // Node to remove found
        Node<T>* temp = node;
        if (isLeaf(node)) {
            delete node;
            node = nullptr;
        } else if (hasOneChild(node)) {
            node = getOneChild(node);
            delete temp;
        } else if (hasTwoChildren(node)) {
            Node<T>*& successor = getSuccessor(node);
            node->data = successor->data;
            remove(node->right, successor->data);
        }
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

template<typename T>
void BSTree<T>::remove(const T& data)
{
    remove(root, data);
}

#endif