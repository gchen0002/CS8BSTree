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
    if(node->left){
        return node->left;
    } else {
        return node->right;
    }
}

template<typename T>
Node<T>*& BSTree<T>::getSuccessor(Node<T>* node) {
    Node<T>* current = node->right;
    
    if (!current->left) {
        return node->right;
    }
    
    while (current->left->left) {
        current = current->left;
    }
    
    return current->left;
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

// helper for remove and destructor
template <typename T>
void BSTree<T>::deleteSubtree(Node<T>*& node){
    if(node == nullptr) {
        return;
    }
    deleteSubtree(node->left);
    deleteSubtree(node->right);
    delete node;
    node = nullptr;
}

// PUBLIC
template <typename T>
BSTree<T>::BSTree(){
    // default constructor
}

template <typename T>
BSTree<T>::BSTree(const BSTree<T>& other){
    // copy constructor
    copyTree(root, other.root);
}

template <typename T>
BSTree<T> BSTree<T>::operator=(const BSTree<T>& other){
    // copy assignment operator if it is different
    if(this != &other){
        copyTree(root, other.root);
    }
    return *this;
}

template <typename T>
void BSTree<T>::copyTree(Node<T>*& thisNode, Node<T>* otherNode){
    if(!otherNode){
        thisNode = nullptr;
        return;
    }
    thisNode = new Node<T>(otherNode->data);
    copyTree(thisNode->left, otherNode->left);
    copyTree(thisNode->right, otherNode->right);
}
template <typename T>
BSTree<T>::~BSTree(){
    // destructor
    clear();
}

template <typename T>
void BSTree<T>::clear(){
    deleteSubtree(root);
}



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

// traversal by enum
template<typename T>
void BSTree<T>::traverse(typename BSTree<T>::Traversal t, int (*f)(T& data)){
    switch(t){
        case BSTree<T>::PREORDER:
            preorder(root, f);
            break;
        case BSTree<T>::INORDER:
            inorder(root, f);
            break;
        case BSTree<T>::POSTORDER:
            postorder(root, f);
            break;
        case BSTree<T>::BREADTHFIRST:
            BFS(f);
            break;
        default:
            inorder(root, f);
            break;
    }
}

template <typename T>
void BSTree<T>::BFS(int (*f)(T& data)){
    if(!root) return;
    std::queue<Node<T>*> q;
    q.push(root);
    while(!q.empty()){
        Node<T>* curr = q.front();
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
        f(curr->data);
        q.pop();
    }
}
#endif