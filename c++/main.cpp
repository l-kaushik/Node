#include "Node.h"
#include <string>

int main()
{
    Node<std::string> b("my",new Node<std::string>("Name", new Node<std::string>("Pika")));
    Node<std::string> a ("hello", new Node<std::string>("world"));
    b = std::move(a);
    b.display();
    b.getNextNode()->display();
}