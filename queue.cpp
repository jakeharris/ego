namespace ego {
  class Queue {
    Node *head;

    public:
    Queue (string filename) {
      /* Open 'filename' and add the trace elements to the list. */ 
    }

    void push(Node *n){
      Node *current = head;
      while(current) {
        if (current->next == NULL) {
          current->next = n;
          return;
        }
        current = current->next;
      }
    }

    void addToFront(Node *n) {
      n->next = head;
      head = n;
    } 
  };
}
