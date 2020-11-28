#include"lab05.h"
void prepare(OneWayList* list){
list->head=NULL;
}

void add(OneWayList* list, const char* text){
  Node* newNode = (Node*)malloc(sizeof(Node));
  if(newNode == NULL) exit(1);

  newNode->data = (char*)malloc(sizeof(char)*500);
  if(newNode->data == NULL) exit(1);

  strcpy(newNode->data,text);
  newNode->next = NULL;
  if(list->head == NULL){
    list->head = newNode; //ustawiam pierwszy element listy jako newNode
  }
  else{
    Node* last = list->head;
    while(last->next != NULL){
      last = last->next;
    }
    last->next = newNode; //przechodze po calej liscie do momentu jej konca, a nastepnie dodaje wezel newNode na koniec listy
  }
}

bool empty(const OneWayList* list){
if(list->head == NULL) return 1;
else return 0;
}

void dump(const OneWayList* list){
  Node* current = list->head;
  while(current != NULL){
    std::cout<<current->data<<" ";
    current = current->next;
  }

}

void clear(OneWayList* list){
  if(list->head != NULL){
  Node* current = list->head;
  Node*next;
  while(current != NULL){
    next = current->next;
    free(current->data);
    free(current);
    current = next;
  }
  list->head = NULL;

  }
}