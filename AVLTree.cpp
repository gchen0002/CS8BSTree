#include "AVLTree.h"
#ifndef AVLTree_CPP
#define AVLTree_CPP

template <typename T>
int AVLTree<T>::getHeight(Node<T>* node) const{
    if(!node){
        return 0;
    }
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

template <typename T>
int AVLTree<T>::getBalancingFactor(Node<T>* node) const{
    if(!node){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
void AVLTree<T>::rotateLeft(Node<T>*& node, Node<T>*& heavyChild){
    Node<T>* temp = heavyChild;
    node->left = heavyChild->right;

    heavyChild = temp;
    node = temp;
}

template <typename T>
void AVLTree<T>::rotateRight(Node<T>*& node, Node<T>*& heavyChild){
    Node<T>* temp = heavyChild;
    node->right = heavyChild->right;

    heavyChild = temp;
    node = temp;
}

template <typename T>
void balance(Node<T>* node){
    if(!node) return;

    const int bf = getBalancingFactor(node);
    if(std::abs(bf) > 1){
        if(bf > 1){
            rotateRight(node);
        }
        else if(bf < -1){
            rotateLeft(node);
        }
    }

    balance(node->right);
    balance(node->left);
}
#endif