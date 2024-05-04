#ifndef LIST_H
#define LIST_H

/**
 * @class List
 * @brief Represents a generic linked list data structure
 * @tparam T The type of elements stored in the list
 */
template<class T>
class List {
private:
    /**
     * @class Node
     * @brief Represents a node in the linked list
     */
    class Node {
    public:
        T* data;   // Pointer to the data stored in the node
        Node* next; // Pointer to the next node in the list
    };

public:
    /**
     * @brief Constructor to initialize an empty list
     */
    List();

    /**
     * @brief Destructor to clean up memory allocated for the list
     */
    ~List();

    /**
     * @brief Overloaded += operator to add an element to the list
     * @param element Pointer to the element to be added
     * @return Reference to the modified list
     */
    List& operator+=(T* element);

    /**
     * @brief Function to convert the list to an array
     * @param arr Pointer to an array to store the elements
     * @param size Reference to an integer to store the size of the array
     */
    void convertToArray(T* arr[], int& size);

private:
    Node* head; // Pointer to the first node in the list
    Node* tail; // Pointer to the last node in the list
};

template<class T>
List<T>::List() : head(nullptr), tail(nullptr) {}

template<class T>
List<T>::~List() {
    Node* currNode = head;
    Node* nextNode;

    while (currNode != nullptr) {
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}

template<class T>
List<T>& List<T>::operator+=(T* element) {
    Node* newNode = new Node();
    newNode->data = element;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    return *this;
}

template<class T>
void List<T>::convertToArray(T* arr[], int& size) {
    Node* curr = head;
    size = 0;
    while (curr != nullptr) {
        arr[size++] = curr->data;
        curr = curr->next;
    }
}

#endif
