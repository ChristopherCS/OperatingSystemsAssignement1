#include "persons.h"

person **createPersonsArray(void){
  person **people = malloc(200*sizeof(person));
  return(people);
}

person *createPerson(char *names){
  person *p = malloc(sizeof(person));
  link *l = NULL;
  char *token = strtok(names, ",");
  int i = 0;

  for(i; i<4; i++){
    switch(i){
      case 0:
        *p->last =  token;
        token = strtok(NULL, ",");
        break;
      case 1:
        *p->middle = token;
        token = strtok(NULL, ",");
        break;
      case 2:
        *p->first = token;
        token = strtok(NULL, ",");
        break;
      case 3:
        *p->nick = token;
        token = strtok(NULL, ",");
        break;
    }
  }

  p->phones = l;

  return(p);
}

void addPhoneToPerson(char *phoneNumber, person *p){
  link * l = p->phones;
  link *new = malloc(sizeof(link));
  new->data = phoneNumber;
  new->next = NULL;

  while(l->next !=NULL){
    l = l->next;
  }
  l->next = new;
}

void printPerson(person *p){
  char *printString = malloc(512*sizeof(char));
  int phones = 0;
  link *traverser = malloc(sizeof(link));
  traverser = p->phones;
  int i=0;
  while(traverser != NULL){
    phones++;
    traverser = traverser->next;
  }

  sprintf(printString, "First Name: %s, Middle Name: %s, Last Name: %s\n", p->first, p->middle, p->last);
  printf(printString);
  traverser = p->phones;
  for(i; i<phones; i++){
    printf("\t%s\n", traverser->data);
    traverser = traverser->next;
  }
}