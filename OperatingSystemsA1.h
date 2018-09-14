#ifndef OPERATING_SYSTEMS_A1_HEADER
#define OPERATING_SYSTEMS_A1_HEADER

#include "persons.h"
#include "phones.h"

void searchByName();
void searchByNick();
void searchByNumber();
int loadUserData(char *fileName);
int userInteraction(void);
void menu(void);
void userSearchMenu(void);
void invalidEntry(int);


#endif