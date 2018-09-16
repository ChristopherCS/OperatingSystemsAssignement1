#include "OperatingSystemsA1.h"


#define LOG_FILE_NAME "A1.log" // Yeah well, I need a global log file... So Shoot Me.

int main(int argc, char **argv){
  FILE *dataFP;
  char *fileName = argv[1];
  int result = 1;

  initLogfile("Logfile Opened.");
  dataFP = openDataFile(fileName);
  parseDataFile(dataFP);

  closeDataFile(dataFP);
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

void closeDataFile(FILE *fp){
  appendToLogfile("Closing Data File.");
  fclose(fp);
}

void parseDataFile(FILE *dataFile){
  char buffer[2048];
  const char delimA[10] = "/"; 
  const char delimB[9] = "\n";
  const char delimC[2] = ",";
  const char delimD[3] = "\n";
  const char arrow = "<";
  size_t bytesRead;
  char  *tokenA;
  char *tokenACounter;
  char *subToken;
  char *subTokenCounter;
  char *logMessage = calloc(4096, sizeof(char));
  char *buffCopy = calloc(2048, sizeof(char));
  char *tokenACopy = calloc(64, sizeof(char));

  appendToLogfile("About to start Parsing File.");
  // While more bytes have been read from the file. (There is data in the buffer.)
  bytesRead = fread(buffer, sizeof(char), sizeof(buffer), dataFile);
  
  while(bytesRead >0){
    sprintf(logMessage, "Read %d bytes from data file.", bytesRead);
    appendToLogfile(logMessage);
    buffCopy = strdup(buffer);

    tokenA = strtok_r(buffCopy, delimA, &tokenACounter);
    while(tokenA != NULL){
      tokenACopy = strdup(tokenA);

      subToken = strtok_r(tokenACopy, delimB, &subTokenCounter);

        while(subToken != NULL){
          if((strpbrk(subToken, arrow)) != NULL){
            appendToLogfile("Found a \">\"");
          }else{
          appendToLogfile(subToken);
        }
          subToken = strtok_r(NULL, delimB, &subTokenCounter);
        }

      
      tokenA = strtok_r(NULL, delimA, &tokenACounter);
    }
  
    bytesRead = fread(buffer,sizeof(char), sizeof(buffer), dataFile);
  }








  free(buffCopy);
  free(logMessage);
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

// This method of timestamping the Log File was inspired by the code located at
// stack overflow here: https://stackoverflow.com/questions/7411301/how-to-introduce-date-and-time-in-log-file
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