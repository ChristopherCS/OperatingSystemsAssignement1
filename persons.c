#include "persons.h"

person **createPersonsArray(void){
  person **people = malloc(200*sizeof(person));
  return(people);
}

person *createPerson(char *names){
  person *p = malloc(sizeof(person));
  *p->first = malloc(25*sizeof(char));
  *p->last = malloc(25*sizeof(char));
  *p->middle = malloc(25*sizeof(char));
  *p->nick = malloc(25*sizeof(char));
  link *l = NULL;
  char *duplicate = calloc(1, 200);
  char *savePtr;
  char *token; 
  int i = 0;
  //printf("Here is the originial names passed: %s\n", names);
  
  strncpy(duplicate, names, 200);
  //printf("Here is the duplicate: %s\n", duplicate); 

  token = strtok_r(duplicate, ",", &savePtr);
  for(i; i<4; i++){
    switch(i){
      case 0:
        
        //printf("Last Name: %s\n", token);
        strcpy(p->last, cleanString(token));
        token = strtok_r(NULL, ",", &savePtr);
        break;
      case 1:
        
        //printf("Middle Name: %s\n", token);
        strcpy(p->middle, cleanString(token));
        token = strtok_r(NULL, ",", &savePtr);
        break;
      case 2:
        
        strcpy(p->first, cleanString(token));
       // printf("First Name: %s\n", token);
        token = strtok_r(NULL, ",", &savePtr);
        break;
      case 3:
        
       // printf("Nick name: %s\n", token);
        strcpy(p->nick, cleanString(token));
        token = strtok_r(NULL, ",", &savePtr);
        break;
    }
  }
  free(duplicate);
  p->phones = l;
  return(p);
}

void addPhoneToPerson(char *phoneNumber, person *p){
  link *new = malloc(sizeof(link));
  phoneNumber = cleanString(phoneNumber);
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
  
  sprintf(printString, "First Name: %s, Middle Name: %s, Last Name: %s, Nick: %s \n", p->first, p->middle,p->last,p->nick );
  printf(printString);
  traverser = p->phones;
  for(i; i<=phones && traverser !=NULL; i++){
    printf("\tPhone: %s\n", traverser->data);
    traverser = traverser->next;
  }

  free(printString);
  free(traverser);
}

void searchNamesFirstLast(person **namesArray, int arraySize, char *first, char* last){
  person * p = NULL;
  person *match = NULL;
  int found = 0;
  int i = 0;
  int firstsMatch;
  int lastsMatch;
  for(i; i<arraySize && !found; i++){
    p = namesArray[i];
    
    firstsMatch = personCompare(first, p->first);
    if(firstsMatch){
      found = 1;
      match = p;
    }
    lastsMatch = personCompare(last, p->last);
    if(lastsMatch){
      found = 1;
      match = p;
    }
  }
  if(found){
    printf("Found %s, %s\n\n", last, first);
    printPerson(match);
  }else{
    printf("Unable to find %s, %s. \n\n", last, first);
  }

}

void searchNamesNick(person **namesArray, int arraySize, char *nick){
  person *p = NULL;
  int i = 0;
  int found = 0;

  for(i; i<arraySize && !found; i++){
    p = namesArray[i];
    if(personCompare(p->nick, nick)){
      found = 1;
    }
  }

  if(found){
    printPerson(p);
  }else{
    printf("Sorry, no record for \"%s\" found.\n", nick);
  }


}

//Returns 1 for match, or 0 for no match
int personCompare(char *a, char *b){
  int ret = 1; // a match
  int sizea, i=0;

  sizea = sizeof(a);

  for(i; i<sizea; i++){
    if(a[i] != b[i]) ret=0;
  }
  

  return(ret);
}

void cleanUpPersons(person **namesArray, int arraySize){
  int i = 0;
  person *p;
  for(i; i<arraySize; i++){
    p = namesArray[i];
    cleanUpLinks(p->phones);
    free(p->first);
    free(p->last);
    free(p->middle);
    free(p->nick);
    free(p);
  }
  free(namesArray);
}

char *cleanString(char *toBeCleaned){
  char *clean = calloc(sizeof(char), strlen(toBeCleaned)+1);
  int i = 0, j=0;
  for(i; i<strlen(toBeCleaned); i++){
    clean[j]=toBeCleaned[i];
    if(!isspace(clean[j])){
      j++;
    }
  }

  return(clean);
}

void printAllPersons(person **personsArray, int personsArraySize){
  int i= 0;
  for( i; i<personsArraySize; i++){
    printPerson(personsArray[i]);
  }
}