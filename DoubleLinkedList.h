#ifndef DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_DOUBLELINKEDLIST_H

template <typename T>
class DoubleLinkedList{
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    DoubleLinkedList();
    DoubleLinkedList(int);

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

    template<class Type> friend std::ostream & operator<<(std::ostream&, LinkedList<Type>&);
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {

}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(int) {

}

template<typename T>
Node <T> *DoubleLinkedList<T>::get_head() {
    return nullptr;
}

template<typename T>
void DoubleLinkedList<T>::set_head(Node <T> *) {

}

template<typename T>
Node <T> *DoubleLinkedList<T>::get_tail() {
    return nullptr;
}

template<typename T>
void DoubleLinkedList<T>::set_tail(Node <T> *) {

}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() {
    return false;
}

template<typename T>
void DoubleLinkedList<T>::addToBegin(T) {

}

template<typename T>
void DoubleLinkedList<T>::addToEnd(T) {

}

template<typename T>
void DoubleLinkedList<T>::addToIndex(T, int) {

}

template<typename T>
void DoubleLinkedList<T>::deleteFromBegin() {

}

template<typename T>
void DoubleLinkedList<T>::deleteFromEnd() {

}

template<typename T>
void DoubleLinkedList<T>::deleteFromIndex(int) {

}

template<class Type>
std::ostream &operator<<(std::ostream &, LinkedList <Type> &) {
    return <#initializer#>;
}

#endif //DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
