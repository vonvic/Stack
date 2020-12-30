#ifndef ITER_H
#define ITER_H

#include <iostream>
#include "node.h"
using namespace std;
/**
 * @brief Implementation of a forward iterator. The iterator
 * class is dependent on the Node struct, where it requires
 * the Node to be at least singly.
 * 
 * @param T The data type that the Node object will hold.
 */
template <class T>
class Iterator {
    public:
        /**
         * Default constructor
         * Initializes the data. This should never be called.
         * 
         * @param none
         * 
         * Precondition: None
         * Postcondition: data Node pointer object is initialized
         * Exception: None
         */
        Iterator() {
            data = new Node<T>();
        }

        /**
         * Parameterized constructor
         * Initializes the data by setting it equal to parameter
         * "item".
         * 
         * @param item Node pointer object of type T. "item" will
         *      be the value set for this->data.
         * 
         * Precondition: "item" is initialized.
         * Postcondition: "data" is assigned with "item".
         * Exception: None
         */
        Iterator(Node<T> *item) {
            data = item;
        }

        /**
         * next method
         * Returns a new Iterator object.
         * 
         * @param none
         * 
         * @returns Iterator
         *      New iterator 
         * 
         * Precondition: data is NOT nullptr.
         * Postcondition: New iterator constructed with "data->next"
         *      is returned.
         * Exception: Throw runtime_error if "data" is nullptr.
         */
        Iterator next() {
            if (!data)
                throw runtime_error("Iterator has reached the end");
            return Iterator<T>(data->next);
        }

        /**
         * Prefix ++ operator overload
         * Overload of prefix ++ operator. Call of this operator will
         * update "data" by assigning it to the next Node in "data", then 
         * returning an Iterator of the updated "data".
         * 
         * @param none
         * 
         * @returns Iterator
         * 
         * Precondition: this->data is not nullptr.
         * Postcondition: this->data assigned to this->data->next.
         *      Iterator of updated this->data is returned.
         * Exception: Throw runtime_error if data is nullptr.
         */
        Iterator operator++() {
            if (!data)
                throw runtime_error("List has reached the end.");

            data = data->next;
            return Iterator<T>(data);
        }

        /**
         * Postfix ++ operator overload
         * Overload of postfix ++ operator. Call of this operator would
         * return this->data, then update this->data to be
         * assigned to this->data->next;
         * 
         * @param none
         * 
         * @returns Iterator
         * 
         * Precondition: this->data is not nullptr.
         * Postcondition: this->data assigned to this->data->next.
         *      Updated this->data is returned.
         * Exception: Throw runtime_error if data is nullptr.
         */
        Iterator operator++(int) {
            if (!data)
                throw runtime_error("List has reached the end.");

            Node<T> *temp = data;
            data = data->next;
            return Iterator<T>(temp);
            
        }

        /**
         * != operator overload
         * Overload of the != operator. Call of this function
         * would return true if instance this->data does not
         * equal parameter iter.data.
         * 
         * @param iter Constant reference to an Iterator object.
         *      This would be located on the right hand side of the
         *      != operator function call.
         * 
         * @returns bool
         * 
         * Precondition: this->data and iter.data are initialized.
         * Postcondition: A boolean is returned.
         * Exception: None.
         */
        bool operator!=(const Iterator<T>& iter) const {
            return (data != iter.data);
        }

        /**
         * == operator overload
         * Overload of the != operator. Call of this function
         * would return true if instance this->data equals parameter 
         * iter.data.
         * 
         * @param iter Constant reference to an Iterator object.
         *      This would be located on the right hand side of the
         *      == operator function call.
         * 
         * @returns bool
         * 
         * Precondition: this->data and iter.data are initialized.
         * Postcondition: A boolean is returned.
         * Exception: None.
         */
        bool operator==(const Iterator<T>& iter) const {
            return (data == iter.data);
        }

        /**
         * Dereference * operator overload
         * Overload of the * dereference operator. Call of the
         * dereference operator returns the value of the current
         * node in this->data.
         */
        T& operator*() {
            return this->data->value;
        }
    private:
        Node<T> *data; /**< The pointer to the current Node holding the data.*/
};

#endif // ITER_H