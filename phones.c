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