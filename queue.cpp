#include "helpers.h"
#include "node.cpp"

#include <iostream>
#include <fstream>

#include <stdlib.h>     /* atol */

namespace ego {
  class Queue {
    Node *head;

    public:
    Queue () {
      
    }
    
    Queue (std::string filename) {
      /* Open 'filename' and add the trace elements to the list. */
      std::string line;
      std::ifstream f (filename);
      if (f.is_open()) {
        while (f.good()) {
          getline(f, line);
          std::istringstream iss(line);
          line = "";
          std::string s;
          while(iss >> s){
               if (!line.empty()) line += " " + s;
               else line = s;
          }
          std::vector<std::string> x = split(line, ' ');
          Node *n = new Node(x[0], atol(x[1].c_str()), atol(x[2].c_str()), atol(x[3].c_str()));
          push(n);
        }
        f.close();
      }
      else std::cout << "Unable to open file\n";
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
    void addToFront(Node n) {
      n.next = head;
      head = &n;
    }
    Node getHead() {
      return *head;
    } 
    Node findByName(std::string n) {
      Node *current = head;
      while(current) {
        if(current->getName() == n) return *current;
        if(current->next == NULL) return *(new Node("error", 0, 0, 0));
        current = current->next;
      }
      return *head; // FIXME
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
