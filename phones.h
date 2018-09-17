#ifndef PHONES_HEADER
#define PHONES_HEADER
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PHONE {
  char *number;
  link *people_list_beginning;
} phone;

phone **createPhonesArray(void);
phone *createPhone(char *phoneNum, char *name);

#endif