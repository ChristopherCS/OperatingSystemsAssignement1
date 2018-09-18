#include "phones.h"


phone **createPhonesArray(void){
  phone **phoneNumbers = malloc(200*sizeof(phone));

  return(phoneNumbers);
}


phone *createPhone(char *phoneNum, char *name){
  phone * entry = malloc(sizeof(phone));
  link *l = malloc(sizeof(link));
  entry->number=phoneNum;

  l->data=name;
  l->next=NULL;
  entry->people_list_beginning = l;

  return(entry);
}

char *cleanPhone(char* givenNumber){
  char *clean = calloc(sizeof(char), strlen(givenNumber)+1);
  int i = 0, j=0;
  for(i; i<strlen(givenNumber); i++){
    clean[j]=givenNumber[i];
    if(isdigit(clean[j])){
      j++;
    }
  }
  clean[j] = '\0';

  return(clean);

}

void printPhone(phone *number){
  char *printString = malloc(256*sizeof(char));
  int names = 0;
  link *traverser = malloc(sizeof(link));
  traverser = number->people_list_beginning;
  int i=0;
  while(traverser != NULL){
    names++;
    traverser = traverser->next;
  }
  
  sprintf(printString, "Phone Number is: %s\n",number->number );
  printf(printString);
  traverser = number->people_list_beginning;
  for(i; i<=names && traverser !=NULL; i++){
    printf("\tName: %s\n", traverser->data);
    traverser = traverser->next;
  }

  free(printString);
  free(traverser);
}

// Returns the length of the phones array.
int addPhoneToArray(phone **phonesArray, int phonesArrayCount, char *phoneNumber, char *name){
  //For this function we first have to search for the phone number. If the phone number exists, then 
  // we simply add the name to the linked list. Otherwise we create a new phone entry and add it to the array.
  int match = searchPhone(phonesArray, phonesArrayCount, phoneNumber);
  phone *newEntry = NULL;
  if(match +1){
    add_link(phonesArray[match]->people_list_beginning, name);
  }else{
    newEntry = createPhone(phoneNumber, name);
    phonesArray[phonesArrayCount] = newEntry;
  }
  return(phonesArrayCount +1);
}

//Returns -1 for no match,or the index of the match in the array.
int searchPhone(phone **phonesArray, int phonesArrayCount, char *phoneNumber){
  char *valA, *valB;
  int i=0, match=0, ret = -1;
  valB = cleanPhone(phoneNumber);
 // printf("Searching by Number for: %s,\n(which has been cleaned to: %s).\n", phoneNumber, valB);
  

  for(i; i<phonesArrayCount && !match; i++){
    valA = cleanPhone(phonesArray[i]->number);
    match = phoneCompare(valA, valB);

    if(match){
      printPhone(phonesArray[i]);
      ret = i;
    }
  }
  return(ret);
}

int phoneCompare(char *a, char *b){
  int count = strlen(a);
  int i =0;
  int match = 1; //it's a match!

  for(i; i<count; i++){
    if(a[i] != b[i]){
      match = 0;
    }
  }
  return(match);
}

void printPhonesArray(phone **phonesArray, int phonesArrayCount){
  int i=0;

  for(i; i<phonesArrayCount; i++){
    printPhone(phonesArray[i]);
  }
}