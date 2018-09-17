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
  link *new = malloc(sizeof(link));
  new->data = phoneNumber;
  new->next = p->phones;
  p->phones = new;

}

void printPerson(person *p){
  char *printString = malloc(256*sizeof(char));
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
  for(i; i<=phones; i++){
    printf("\t%s\n", traverser->data);
    traverser = traverser->next;
  }

  free(printString);
  free(traverser);
}

person *searchNamesFirstLast(person **namesArray, int arraySize, char *first, char* last){
  person * p = NULL;
  person *ret = NULL;
  int found = 0;
  int i = 0;
  for(i; i<arraySize && !found; i++){
    p = namesArray[i];
    if(compare(p->first, first)){
      if(compare(p->last, last)){
        ret = p;
        found = 1;
      }
    }

  }
  return(ret);

}

person *searchNamesNick(person **namesArray, int arraySize, char *nick){
  person *p = NULL;
  person *ret = NULL;
  int i = 0;
  int found = 0;

  for(i; i<arraySize && !found; i++){
    p = namesArray[i];
    if(compare(p->nick, nick)){
      ret = p;
      found = 1;
    }
  }

  return(ret);
}

//Returns 1, match or 0, not match
int compare(char *a, char *b){
  int ret = 1; // a match
  int sizea, sizeb, i=0;

  sizea = sizeof(a);
  sizeb = sizeof(b);
  if(sizea = sizeb){
    for(i; i<sizea; i++){
      if(a[i] != b[i]) ret=0;
    }
  }else ret = 0; //not a match

  return(ret);
}

void cleanUpPersons(person **namesArray, int arraySize){
  int i = 0;
  person *p;
  for(i; i<arraySize; i++){
    p = namesArray[i];
    cleanUpLinks(p->phones);
    free(p);
  }
  free(namesArray);
}