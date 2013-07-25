#include "queue.cpp"
#include <iostream>

using namespace ego;

int main() {
  Queue *q = new Queue();

  Node *n = new Node("berp", 1000, 1000, 1000);
  Node *m = new Node("derp", 1, 23, 456);
  Node *p = new Node("abra kadabra", 7, 8, 910);
 
  q->push(n);
  q->toString();
  std::cout << std::endl << std::endl;
  q->push(m);
  q->toString();
  std::cout << std::endl << std::endl;
  q->push(p);
  q->toString();
  std::cout << std::endl << std::endl;
  std::cout << q->pop().getName() << std::endl;
  std::cout << std::endl << std::endl;
  q->toString();
}
