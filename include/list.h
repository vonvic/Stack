#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iter.h"
using namespace std;

/**
 * @brief Implemention of the doubly linked list
 * data structure.
 * 
 * @param T the type of data to be stored into List object.
 * 
 */
template <class T>
class List {
    public:
        /**
         * Default constructor.
         * Constructs a new list to its empty state.
         * 
         * @param none
         * 
         * @returns none
         * 
         * Precondition: List object is uninitialized
         * Postcondition: List object is initialized to its empty state
         * Exception: None
         */
        List() {
            length = 0;
            head = nullptr;
            tail = nullptr;
        }

        /**
         * Destructor (called automatically)
         * Frees all nodes from head to tail.
         * 
         * Precondition: List object is initialized.
         * Postcondition: List object nodes are free'd, head and tail are set to nullptr,
         *                and length is set to zero (0).
         * Exception: None
         */
        ~List() {
            Node<T> *curr = head;
            while (curr) { // Loops every node and deletes it.
                Node<T> *temp = curr;
                curr = curr->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
        }

        /**
         * Output operator<< overload
         * Overloads the "<<" operator for use of any output function
         * call. I.e.
         *           std::cout << <List object>
         * 
         * @param os
         * 
         * 
         * Precondition: List is initialized.
         * Postcondition: Reference to the ostream parameter is passed, with
         *                objects sent to the ostream.
         * Exception: None.
         */
        template <class S>
        friend ostream& operator<<(ostream& os, const List<S>&);

        /**
         * Pushes a new item to the front of the list.
         * 
         * @param item the item to be pushed
         * 
         * @returns none
         * 
         * Precondition: List object is initialized
         * Postcondition: item is pushed to the front of the List.
         * Exception: None.
         */
        void pushFront(T item) {
            Node<T>* newNode = new Node<T>();
            newNode->value = item;
            newNode->prev = nullptr;

            if (length == 0) {
                newNode->next = nullptr;
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }

            ++length;
        }

        /**
         * Pushes a new item to the back of the list.
         * 
         * @param item the item to be pushed
         * 
         * @returns none
         * 
         * Precondition: List object is initialized
         * Postcondition: item is pushed to the back of the List.
         * Exception: None.
         */
        void pushBack(T item) {
            Node<T>* newNode = new Node<T>();
            newNode->value = item;
            newNode->next = nullptr;

            if (length == 0) {
                newNode->prev = nullptr;
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }

            ++length;
        }

        /**
         * Pops the item at the front of the list.
         * 
         * @param none
         * 
         * @returns value of popped item.
         * 
         * Precondition: List object is initialized
         * Postcondition: item is popped from the front of the List object.
         * Exception: Throws runtime_error if the list is empty.
         */
        T popFront() {
            if (length == 0)
                throw runtime_error("Cannot pop an empty list");
            
            Node<T> *temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            }
            else {
                head = head->next;
            }

            T poppedItem = temp->value;
            delete temp;
            --length;
            return poppedItem;
        }

        /**
         * Pops the item at the back of the list.
         * 
         * @param none
         * 
         * @returns value of popped item.
         * 
         * Precondition: List object is initialized
         * Postcondition: item is popped from the back of the List object.
         * Exception: Throws runtime_error if the list is empty.
         */
        T popBack() {
            if (length == 0)
                throw runtime_error("Cannot pop an empty list");
            
            Node<T> *temp = tail;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            }
            else {
                tail = tail->prev;
            }

            T poppedItem = temp->value;
            delete temp;
            --length;
            return poppedItem;
        }

        /**
         * Returns the first item of the list as an iterator. If the
         * list is empty, returns nullptr as an iterator.
         * 
         * @param none
         * 
         * @returns the head member variable as an iterator
         * 
         * Precondition: List is initialized.
         * Postcondition: Iterator<T> of head or nullptr is returned.
         * Exception: None.
         */
        Iterator<T> begin() const {
            return Iterator<T>(head);
        }

        /**
         * Returns the last item of the list as an iterator. If the
         * list is empty, returns nullptr as an iterator.
         * 
         * @param none
         * 
         * @returns the head member variable as an iterator
         * 
         * Precondition: List is initialized.
         * Postcondition: Iterator<T> of EITHER tail  OR NULLPTRis returned.
         * Exception: None.
         */
        Iterator<T> end() const {
            if (tail) return Iterator<T>(tail->next);
            return Iterator<T>(tail);
        }
        
    private:
        unsigned int length;
        Node<T> *head, *tail;
};

/**
 * Output operator<< overload
 * Overloads the "<<" operator for use of any output function
 * call.
 * e.g.
 *      std::cout << <List object>
 * 
 * @param os Reference to the output stream variable
 *      such as cout or ofstream. This will be located
 *      to the left of the << operator.
 * @param L Reference to the List object that is being
 *      outputted. This will be located to the right of the 
 *      << operator.
 * 
 * Precondition: List is initialized.
 * Postcondition: Reference to the ostream parameter is passed, with
 *                objects sent to the ostream.
 * Exception: None.
 */
template <class S>
ostream& operator << (ostream& os, const List<S>& L) {
    os << "[";
    
    for(Iterator<S> __current = L.begin(); __current != L.end(); ++__current) {
        auto current = *__current;
        cout << current;
        if (__current.next() != L.end()) cout << ',';
    }

    os << "]";
    return os;
}

#endif // LIST_H