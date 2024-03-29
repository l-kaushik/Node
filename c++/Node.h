#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node
{
private:
    T m_value{};
    Node<T> *m_next{nullptr};

public:
    // constructors
    Node();
    Node(T value);
    Node(Node<T> *next);
    Node(T value, Node<T> *next);

    // copy contructor, copy assignment operator
    Node(const Node<T> &other);
    Node<T> &operator=(const Node<T> &other);

    //move constructor, move assignment operator
    Node(Node<T> &&other);
    Node<T> &operator=(Node<T> &&other);

    //destructor
    ~Node();

    // Getters
    T getValue() const;
    Node<T> *getNextNode() const;

    // Setters
    void setValue(T value);
    void setNextNode(Node<T> *next);

    // Functions
    void display() const;
};

//<--------- METHOD DEFINITIONS --------->

// constructors
template <typename T>
Node<T>::Node() : m_value(), m_next(nullptr) {}

template <typename T>
Node<T>::Node(T value) : m_value(value) {}

template <typename T>
Node<T>::Node(Node<T> *next) : m_next(next) {}

template <typename T>
Node<T>::Node(T value, Node<T> *next)
    : m_value(value), m_next(next) {}

// copy contructor 
template <typename T>
Node<T>::Node(const Node<T> &other)
{
    *this = other;
}

//copy assignment operator
template <typename T>
Node<T>& Node<T>::operator=(const Node<T> &other)
{
    if(this == &other)
        return *this;

    this->m_value = other.m_value;
    delete m_next;
    m_next = nullptr;
    if(other.m_next)
        this->m_next = new Node<T>(*other.m_next);

    return *this;
}

//move constructor
template <typename T>
Node<T>::Node(Node<T> &&other)
{
    *this = std::move(other);
}

//move assignment operator
template <typename T>
Node<T>& Node<T>::operator=(Node<T> &&other)
{
    if(this == &other)
        return *this;
    
    m_value = std::move(other.m_value);

    delete m_next;
    m_next = nullptr;
    m_next = std::move(other.m_next);

    //resetting temporary object
    other.m_value = T{};
    other.m_next = nullptr;
    
    return *this;
}

//destructor
template <typename T>
Node<T>::~Node()
{
    delete m_next;
    m_next = nullptr;
}

// Getters
template <typename T>
T Node<T>::getValue() const
{
    return m_value;
}
template <typename T>
Node<T> *Node<T>::getNextNode() const
{
    return m_next;
}

// Setters
template <typename T>
void Node<T>::setValue(T value)
{
    m_value = value;
}

template <typename T>
void Node<T>::setNextNode(Node<T> *next)
{
    m_next = next;
}

// Functions
template <typename T>
void Node<T>::display() const
{
    std::cout << "Value: " << m_value << '\n';
}

#endif