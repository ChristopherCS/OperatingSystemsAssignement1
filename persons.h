#ifndef PERSONS_HEADER
#define PERSONS_HEADER
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct PERSON_STRUCT {
  char first[50];
  char middle[50];
  char last[50];
  char nick[50];

  link *phones; //linked list of phone numbers.
} person;

person **createPersonsArray(void);
person *createPerson(char *names);
void addPhoneToPerson(char *phoneNumber, person *p);
void printPerson(person *p);



#endif