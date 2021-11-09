#ifndef DOUBLELINKEDLIST_NODE_H
#define DOUBLELINKEDLIST_NODE_H

template <typename T>
class Node{
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    T data;
public:
    Node();
    Node(T);

    T get_el();
    void set_el(T);

    Node<T>* get_next();
    void set_next(Node<T>*);

    Node<T>* get_prev();
    void set_prev(Node<T>*);
};

template<typename T>
Node<T>::Node() {
    next = nullptr;
    prev = nullptr;
    data = 0;
}

template<typename T>
Node<T>::Node(T el) {
    next = nullptr;
    prev = nullptr;
    data = el;
}

template<typename T>
T Node<T>::get_el() {
    return data;
}

template<typename T>
void Node<T>::set_el(T el) {
    data = el;
}

template<typename T>
Node<T> *Node<T>::get_next() {
    return next;
}

template<typename T>
void Node<T>::set_next(Node<T> *next_) {
    next = next_;
}

template<typename T>
Node<T> *Node<T>::get_prev() {
    return prev;
}

template<typename T>
void Node<T>::set_prev(Node<T> *prev_) {
    prev = prev_;
}


#endif //DOUBLELINKEDLIST_NODE_H
