#ifndef NODE_H
#define NODE_H
template <typename T>
struct Node
{
    T data;
    Node* left = nullptr, *right = nullptr;
    Node(){}
    Node(const T& data) : data(data) {}
};
#endif //NODE_H