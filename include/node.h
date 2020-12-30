#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

/**
 * @brief Holds a value of template class type T, and points to
 * other nodes.
 */
template <class T>
struct Node{
    T value;    /**< The value of the node of template type T*/
    Node* prev; /**< A pointer to the previous Node*/
    Node* next; /**< A pointer to the next Node */

    /**
     * Overloads the output operator "<<" for use of any output
     * function call.
     * e.g
     *      std::cout << <Node object>
     * 
     * @param os Reference to the output stream variable
     *      such as cout or ofstream. This will be located
     *      to the left of the << operator.
     * @param node Reference to the node object that is 
     *      being outputted. This will be located to the right
     *      of the << operator.
     * 
     * Precondition: Node is initialized
     * Postcondition: Node is sent to the output variable.
     */
    template <class U>
    friend ostream& operator<<(ostream& os, const Node& node);
};
/**
 * Overloads the output operator "<<" for use of any output
 * function call.
 * e.g
 *      std::cout << <Node object>
 * 
 * @param os Reference to the output stream variable
 *      such as cout or ofstream. This will be located
 *      to the left of the << operator.
 * @param node Reference to the node object that is 
 *      being outputted. This will be located to the right
 *      of the << operator.
 * 
 * Precondition: Node is initialized
 * Postcondition: Node is sent to the output variable.
*/
template <class U>
ostream& operator<<(ostream& os, const Node<U>& node) {
    os << node.value;
    return os;
}

#endif // NODE_H