#ifndef OPERATING_SYSTEMS_A1_HEADER
#define OPERATING_SYSTEMS_A1_HEADER

#include "persons.h"
#include "phones.h"

void searchByName(char *last, char *first);
void searchByNick(char *nick);
void searchByNumber(char *number);
int loadUserData(char *fileName);
int userIntaraction(void);
void menu(void);


#endif