#include "OperatingSystemsA1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv){

  int result = 1;
  
  result = userInteraction();
  return result;
}



void searchByName(char *last, char *first){
  printf("Not Implemented Yet");
}


void searchByNick(char *nick){
  printf("Not Implemented Yet");
}

void searchByNumber(char *number){
  printf("Not Implemented Yet");
}

int loadUserData(char *fileName){
  printf("Not Implemented yet");
  return(0);
}

int userInteraction(){
  int loop = 0;

  while(loop != 3){
     menu();
     loop = getchar();
  }

}

void menu(void){
  printf("Enter \"1\" to search by name.");
  printf("Enter \"2\" to search by number.");
  printf("Enter \"3\" to quit.");
}