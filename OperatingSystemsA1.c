#include "OperatingSystemsA1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char **argv){

  int result = 1;
  
  result = userInteraction();
  return result;
}



void searchByName(){
  printf("searchByName: Not Implemented Yet\n");
}


void searchByNick(){
  printf("searchByNick: Not Implemented Yet\n");
}

void searchByNumber(){
  printf("SearchByNumber: Not Implemented Yet\n");
}

int loadUserData(char *fileName){
  printf("loadUserData: Not Implemented yet\n");
  return(0);
}

int userInteraction(void){
  int loop = 0;
  int getby = 0;

  while(loop != 3){
    menu();
    scanf("%d", &loop);
    if(loop == 1){
      while(getby != 1 && getby != 2){
        userSearchMenu();
        scanf("%d", &getby);

        if(getby == 1) searchByName();
        if(getby == 2) searchByNick();        
       
        if(getby != 1 && getby != 2) invalidEntry(getby);
    
      }
      getby = 0;
    }

    else if(loop == 2){
      searchByNumber();
    }

    else if(loop != 3){
      invalidEntry(loop);
    }

  }

  return(0);

}

void menu(void){
  printf("Enter \"1\" to search by name.\n");
  printf("Enter \"2\" to search by number.\n");
  printf("Enter \"3\" to quit.\n");
}

void userSearchMenu(void){
  printf("Enter 1 to search by \"last,first\".\n");
  printf("Enter 2 to search by \"nickname\".\n");
}

void invalidEntry(int input){
  printf("\n\t**|%d| is not a valid entry.\n", input);
}