#ifndef DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_DOUBLELINKEDLIST_H

#include "iostream"
#include "Node.h"

template <typename T>
class DoubleLinkedList{
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    DoubleLinkedList();
    explicit DoubleLinkedList(int);

    Node<T>* get_head()
    void set_head(Node<T>*)

    Node<T>* get_tail()
    void set_tail(Node<T>*)

    bool isEmpty()

    void addToBegin(T)
    void addToEnd(T)
    void addToIndex(T, int)

    void deleteFromBegin()
    void deleteFromEnd()
    void deleteFromIndex(int)

    template<class Type> friend std::ostream & operator<<(std::ostream&, DoubleLinkedList<Type>&);
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(int) {

}

template<typename T>
Node <T> *DoubleLinkedList<T>::get_head() {
    return head;
}

template<typename T>
void DoubleLinkedList<T>::set_head(Node<T> * node) {
    head = node;
}

template<typename T>
Node <T> *DoubleLinkedList<T>::get_tail() {
    return tail;
}

template<typename T>
void DoubleLinkedList<T>::set_tail(Node <T> *node) {
    tail = node;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() {
    if(head != nullptr) return false;
    return true;
}

template<typename T>
void DoubleLinkedList<T>::addToBegin(T val) {
    Node<T> node(val);
    node.set_next(head);
    head = *node;
}

template<typename T>
void DoubleLinkedList<T>::addToEnd(T val) {
    Node<T> node(val);
    node.set_prev(tail);
    tail = *node;
}

template<typename T>
void DoubleLinkedList<T>::addToIndex(T val, int index) {
    Node<T> node(val);
    auto ptr = head;
    for(int i = 0;i < index;i++){
        if(ptr == nullptr){
            cerr << "Wrong index" << endl;
            return;
        }
        ptr = ptr->get_next();
    }
    ptr1 = ptr->get_next();
    ptr->set_next(*node);
    node.set_next(ptr1);
    node.set_prev(ptr);
}

template<typename T>
void DoubleLinkedList<T>::deleteFromBegin() {
    auto ptr = head->get_next();
    delete head;
    head = ptr;
}

template<typename T>
void DoubleLinkedList<T>::deleteFromEnd() {
    auto ptr = tail->get_prev();
    delete tail;
    tail = nullptr;
    tail = ptr;
}

template<typename T>
void DoubleLinkedList<T>::deleteFromIndex(int index) {
    auto ptr = head;
    for(int i = 0;i < index;i++){
        if(ptr == nullptr){
            cerr << "Wrong index" << endl;
            return;
        }
        ptr = ptr->get_next();
    }
    ptr->get_prev()->set_next(ptr->get_next());
    delete ptr;
}

template<class Type>
std::ostream &operator<<(std::ostream &out, DoubleLinkedList <Type> & ll) {
    auto ptr = ll.get_head();
    cout << ptr->get_el();
    while(ptr->get_next() != nullptr)
        cout << ptr->get_el();
}

#endif //DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
