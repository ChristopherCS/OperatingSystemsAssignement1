#ifndef OPERATING_SYSTEMS_A1_HEADER
#define OPERATING_SYSTEMS_A1_HEADER
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "persons.h"
#include "phones.h"
#include "linkedList.h"

void searchByName(person **personsArray, int arraySize);
void searchByNick(person **personsArray, int arraySize);
void searchByNumber(phone **phonesArray, int arraySize);
int loadUserData(char *fileName);
int userInteraction(person **personsArray, int personsArraySize, phone **phonesArray, int phonesArraySize);
void menu(void);
void userSearchMenu(void);
void invalidEntry(int);
void initLogfile(char *message);
FILE *openDataFile(char *fileName);
void appendToLogfile(char *message);
int parseDataFile(FILE *dataFile, person **personsArray);
void closeDataFile(FILE* fp);
int checkInputType(char *inputLine);
int populatePhonesArray(person **personsArray, int personsArrayCount, phone **phonesArray);

#endif