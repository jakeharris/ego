#include "node.cpp"

namespace ego {
  class Queue {
    Node *head;

    public:
    Queue () {
      
    }
    Queue (std::string filename) {
      /* Open 'filename' and add the trace elements to the list. */ 
    }

    void push(Node *n) {
      if(head == NULL) {
        head = n;
        return;
      }
      Node *current = head;
      while(current) {
        if (current->next == NULL) {
          current->next = n;
          return;
        }
        current = current->next;
      }
    }
    void push(std::string cmd) {
      Node *n = new Node(cmd, 0, 0, 0);
      push(n);
    }
    Node pop() {
      Node *tail = head;
      if(tail->next == NULL) {
        head = NULL;
        return *tail;
      }
      tail = tail->next;
      Node *newtail = head;
      while(tail) {
        if(tail->next == NULL) {
          newtail->next = NULL;
          return *tail;
        }
        tail = tail->next;
        newtail = newtail->next;
      }
      std::cerr << "Never found a node in queue." << std::endl;
      Node *err = new Node("error", 0, 0, 0);
      return *err;
    }
    void addToFront(Node *n) {
      n->next = head;
      head = n;
    }
    Node getHead() {
      return *head;
    } 
    void toString() {
      Node *current = head;
      std::cout << "QUEUE CONTENTS:" << std::endl;
      std::cout << "===============" << std::endl;
      if(current == NULL) std::cout << "The queue is empty." << std::endl;
      while(current) {
        current->toString();
        if (current->next == NULL) return;
        current = current->next;
      }
    }
  };
}
