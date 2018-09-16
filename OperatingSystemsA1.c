#include "OperatingSystemsA1.h"


#define LOG_FILE_NAME "A1.log"

int main(int argc, char **argv){
  FILE *dataFP;
  char *fileName = argv[0];
  int result = 1;

  initLogfile("Logfile Opened.");
  dataFP = openDataFile(fileName);

  result = userInteraction();
  appendToLogfile("Program Ending. Closing Log File Now. Goodbye.");
  return result;
}

FILE *openDataFile(char *fileName){
  FILE *fp;
  char *logString = (char *)malloc(75*sizeof(char));
  sprintf(logString, "Opening Data File with Name: %s.", fileName);
  appendToLogfile(logString);
  fp = fopen(fileName, "r");
  free(logString);
  return(fp);
}


void initLogfile(char *message){
  FILE *logFile = fopen(LOG_FILE_NAME, "w+" );
  char timeStamp[20];
  struct tm *timeStruct;
  time_t now = time(0);
  timeStruct = gmtime(&now);
  strftime(timeStamp, sizeof(timeStamp), "%Y-%m-%d %H:%M:%S", timeStruct);

  fprintf(logFile, "%s: %s\n", timeStamp, message);

  fclose(logFile);
}

void appendToLogfile(char *message){
  FILE *logFile = fopen(LOG_FILE_NAME, "a");
  char timeStamp[20];
  struct tm *timeStruct;
  time_t now = time(0);
  timeStruct = gmtime(&now);
  strftime(timeStamp, sizeof(timeStamp), "%Y-%m-%d %H:%M:%S", timeStruct);

  fprintf(logFile, "%s: %s\n", timeStamp, message);
  fclose(logFile);
}


void searchByName(){
  appendToLogfile("Search By Name Initiated");
  printf("searchByName: Not Implemented Yet\n");
}


void searchByNick(){
  appendToLogfile("Search By Nick Initiated");
  printf("searchByNick: Not Implemented Yet\n");
}

void searchByNumber(){
  appendToLogfile("Search by Number Initiated");
  printf("SearchByNumber: Not Implemented Yet\n");
}

int loadUserData(char *fileName){
  appendToLogfile("Loading User Data Now.");
  printf("loadUserData: Not Implemented yet\n");
  return(0);
}

int userInteraction(void){
  appendToLogfile("Beginning User Interaction.");
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
  appendToLogfile("Printed the User Menu to Terminal.");
  printf("Enter \"1\" to search by name.\n");
  printf("Enter \"2\" to search by number.\n");
  printf("Enter \"3\" to quit.\n");
}

void userSearchMenu(void){
  appendToLogfile("Printed the User Search Menu to Terminal.");
  printf("Enter 1 to search by \"last,first\".\n");
  printf("Enter 2 to search by \"nickname\".\n");
}

void invalidEntry(int input){
  appendToLogfile("User entered an invalid entry.");
  printf("\n\t**|%d| is not a valid entry.\n", input);
}