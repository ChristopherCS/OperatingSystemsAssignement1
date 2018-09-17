#ifndef OPERATING_SYSTEMS_A1_HEADER
#define OPERATING_SYSTEMS_A1_HEADER
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
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
void initLogfile(char *message);
FILE *openDataFile(char *fileName);
void appendToLogfile(char *message);
void parseDataFile(FILE *dataFile);
void closeDataFile(FILE* fp);
int checkInputType(char *inputLine);

#endif