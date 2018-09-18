#ifndef PHONES_HEADER
#define PHONES_HEADER
#include "linkedList.h"
#include "persons.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PHONE {
  char *number;
  link *people_list_beginning;
} phone;

phone **createPhonesArray(void);
phone *createPhone(char *phoneNum, char *name);
int addPhoneToArray(phone **phonesArray, int phonesArrayCount, char* phoneNumber, char *name);
char *cleanPhone(char* givenNumber);
int searchPhone(phone **phonesArray, int phonesArrayCount, char *phoneNumber);
int phoneCompare(char *a, char *b);
void printPhone(phone *number);
void printPhonesArray(phone **phonesArray, int phonesArrayCount);
#endif