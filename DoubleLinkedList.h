#ifndef DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_DOUBLELINKEDLIST_H

#include "iostream"
#include "Node.h"

using namespace std;

template <typename T>
class DoubleLinkedList{
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    DoubleLinkedList();

    Node<T>* get_head();
    void set_head(Node<T>*);

    Node<T>* get_tail();
    void set_tail(Node<T>*);

    bool isEmpty();

    void addToBegin(T);
    void addToEnd(T);
    void addToIndex(T, int);

    void deleteFromBegin();
    void deleteFromEnd();
    void deleteFromIndex(int);

    void addAfterEl(Node<T>*, int, int);

    template<class Type> friend std::ostream & operator<<(std::ostream&, DoubleLinkedList<Type>&);
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = nullptr;
    tail = nullptr;
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
    auto *node = new Node<T>(val);
    node->set_next(head);
    node->set_prev(nullptr);
    head = node;
}

template<typename T>
void DoubleLinkedList<T>::addToEnd(T val) {
    auto *node = new Node<T>(val);
    if(tail == nullptr) tail = head;
    node->set_next(nullptr);
    node->set_prev(tail);
    auto ptr1 = node;
    tail->set_next(ptr1);
    tail = node;
}

template<typename T>
void DoubleLinkedList<T>::addToIndex(T val, int index) {
    auto *node = new Node<T>(val);
    auto ptr = head;
    for(int i = 0;i < index;i++){
        if(ptr == nullptr){
            cout << "Wrong index" << endl;
            return;
        }
        ptr = ptr->get_next();
    }
    auto ptr1 = ptr->get_next();
    ptr->set_next(node);
    node->set_next(ptr1);
    node->set_prev(ptr);
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
    Node<Type> node = *ll.get_head();
    while(node.get_next() != nullptr){
        cout << node.get_el() << " ";
        node = *node.get_next();
    }
    cout << node.get_el() << " ";
}

template<typename T>
void DoubleLinkedList<T>::addAfterEl(Node<T>* node, int pos, int val) {
    if(pos >= 0) {
        for (int i = 0; i < pos; i++)
            if (node->get_next() != nullptr)
                node = node->get_next();
    }
    else{
        for(int i = 0;i < 0 - pos;i++)
            if(node->get_prev() != nullptr)
                node = node->get_prev();
    }
    auto *node1 = new Node<T>(val);
    node1->set_prev(node);
    node1->set_next(node->get_next());
    node->get_next()->set_prev(node1);
    node->set_next(node1);
}

#endif //DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
