#include "MyList.h"

void prepare(MyList *list) { 
  list->head = NULL; 
}

void add(MyList *list, const char *text) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  Node *last = list->head;

  newNode->data = (char *)malloc(100 * sizeof(char));
  strcpy((char *)newNode->data, text);
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
  } else {
    while (last->next != NULL) {
      last = last->next;
    }
    last->next = newNode;
  }
  // newNode->next=list->head;
}

bool empty(const MyList *list) {
  if (list->head == NULL) {
    return 1;
  } else {
    return 0;
  }
}

void dump(const MyList *list) {
  Node *current = list->head;
  while (current != NULL) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << "\n";
}

void clear(MyList *list) {
  if (list->head != NULL) {
    Node *current = list->head;
    Node *next;
    while (current->next != NULL) {
      next = current;
      current = current->next;
      free(next->data);
      free(next);
    }
    free(current->data);
    free(current);
    list->head = NULL;
  }
}