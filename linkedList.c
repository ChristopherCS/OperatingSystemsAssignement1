#include "linkedList.h"


link *create_link(char *data, link *next){

  link* new_link = (link *)malloc(sizeof(link));
  if(new_link == NULL){ 
    printf("Error Creating Link, Memory Not Allocated. Exiting.");
    exit(1);
  }

  new_link->data = data;
  new_link->next = next;

  return new_link;
}

link *add_link(link *beginning, char *data){
  link *new_link = create_link(data, beginning);
  return(new_link);
}

void print_data(link *beginning){
  while(beginning != NULL){
    printf("%s\n", beginning->data);
    beginning = beginning->next;
  } 
}

void cleanUpLinks(link * l){
  link *temp = malloc(sizeof(link));

  while(l->next != NULL){
    temp = l->next;
    free(l);
    l = temp;
  }
}
