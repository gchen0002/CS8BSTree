#include "AVLTree.h"
#include <algorithm>
#ifndef AVLTree_CPP
#define AVLTree_CPP



template <typename T>
int AVLTree<T>::getHeight(Node<T>* node) const{
    if(!node){
        return 0;
    }
    return std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

template <typename T>
int AVLTree<T>::getBalancingFactor(Node<T>* node) const{
    if(!node){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
void AVLTree<T>::rotateLeft(Node<T>*& node){
    Node<T>* heavyChild = node->right;
    node->right = heavyChild->left;
    heavyChild->left = node;
    node = heavyChild;
}

template <typename T>
void AVLTree<T>::rotateRight(Node<T>*& node){
    Node<T>* heavyChild = node->left;
    node->left = heavyChild->right;
    heavyChild->right = node;
    node = heavyChild;
}

template <typename T>
void AVLTree<T>::balance(Node<T>*& node){
    if(!node) return;

    const int bf = getBalancingFactor(node);
    if(bf > 1){
        if(getBalancingFactor(node->left) < 0){
            rotateLeft(node->left);
        }
        rotateRight(node);
    }
    else if(bf < -1){
        if(getBalancingFactor(node->right) > 0){
            rotateRight(node->right);
        }
        rotateLeft(node);
    }
}
// PUBLIC METHODS
// big 3
template <typename T>
AVLTree<T>::AVLTree() :BSTree<T>(){
    // default constructor
}

template <typename T>
AVLTree<T>::~AVLTree(){
    // destructor
    this->clear();
}

template <typename T>
AVLTree<T>::AVLTree(const AVLTree<T>& other) : BSTree<T>(other){
    // copy constructor
}

template<typename T>
AVLTree<T> AVLTree<T>::operator=(const AVLTree<T>& other){
    // copy assignment operator
    if(this != &other){
        // use bstree assignment operator
        BSTree<T>::operator=(other);
    }
    return *this;
}

template <typename T>
void AVLTree<T>::copyTree(Node<T>*& thisNode, Node<T>* otherNode){
    BSTree<T>::copyTree(thisNode, otherNode);
}

template <typename T>
void AVLTree<T>::remove(const T& data){
    BSTree<T>::remove(this->root, data);
    balance(this->root);
}

template <typename T>
void AVLTree<T>::clear(){
    BSTree<T>::clear();
}

template <typename T>
void AVLTree<T>::push(const T& data){
    BSTree<T>::push(this->root, data);
    balance(this->root);
}
#endif