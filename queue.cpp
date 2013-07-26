#include "helpers.cpp"
#include "node.cpp"

#include <iostream>
#include <fstream>

#include <stdlib.h>     /* atol */

namespace ego {
  class Queue {
    Node *head;

    public:
    Queue () {
      head = new Node("H", 0, 0, 0);
    }
    
    Queue (std::string filename) {
      /* Open 'filename' and add the trace elements to the list. */
      Helpers h;
      std::string line;
      std::ifstream f(filename.c_str());
      if (f.is_open()) {
        while (getline(f, line)) {
          std::istringstream iss(line);
          line = "";
          std::string s;
          while(iss >> s){
               if (!line.empty()) line += " " + s;
               else line = s;
          }
          std::vector<std::string> x = h.separate(line, ' ');
          Node *n = new Node(x[0], atol(x[1].c_str()), atol(x[2].c_str()), atol(x[3].c_str()));
          push(n);
        }
        f.close();
      }
      else std::cout << "Unable to open file\n";
    }
    bool hasHead() {
      std::cout << "head: " << head << std::endl;
      return head != NULL;
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
    Node* pop() {
      Node *tail = head;
      if(tail->next == NULL) {
        head = NULL;
        return tail;
      }
      tail = tail->next;
      Node *newtail = head;
      while(tail) {
        if(tail->next == NULL) {
          newtail->next = NULL;
          return tail;
        }
        tail = tail->next;
        newtail = newtail->next;
      }
      std::cerr << "Never found a node in queue." << std::endl;
      Node *err = new Node("error", 0, 0, 0);
      return err;
    }
    void addToFront(Node * n) {
      n->next = head;
      head = n;
    }
    Node getHead() {
      return *head;
    } 
    Node* findByName(std::string n) {
      std::cout << "Haven't slept in a year." << n << std::endl;
      Node *current = new Node("F", 0, 0, 0);
      if (hasHead()) {
        std::cout << "Target acquired.\n";
        *current = getHead();
      }
      std::cout << "Have you ever eaten a snowcone?" << head->getName() << std::endl;      
      std::cout << "Have you ever eaten a snowcone?" << current->getName() << std::endl;
//      while(current) {
//        if(current.getName() == n) return current;
//        if(current.next == NULL) return new Node("error", 0, 0, 0);
//        current = current.next;
//      }
      return current;
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
