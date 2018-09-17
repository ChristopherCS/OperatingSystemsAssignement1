#include "OperatingSystemsA1.h"


#define LOG_FILE_NAME "A1.log" // Yeah well, I need a global log file... So Shoot Me.

int main(int argc, char **argv){
  FILE *dataFP;
  char *fileName = argv[1];
  int result = 1;
  int nPersons;
  person **personsArray = createPersonsArray();

  initLogfile("Logfile Opened.");
  dataFP = openDataFile(fileName);

  // Parsing the Data File returns the number of people entered.
  // This value is required during clean up and search.
  nPersons = parseDataFile(dataFP, personsArray);


  cleanUpPersons(personsArray, nPersons);
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

//Returns the number of records created.
int parseDataFile(FILE *dataFile, person **personsArray){
  char buffer[2048];
  const char delimA[10] = "/"; 
  const char delimB[9] = "\n";
  int bytesRead, personsCount = 0;
  person *temp;
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
          switch(checkInputType(subToken)){
            case 0: //a name
            sprintf(logMessage, "About to Try to Parse the Name: %s.", subToken);
            appendToLogfile(logMessage);
            temp = createPerson(subToken);
            appendToLogfile("Created Person. About to Print Person Data.");
            printPerson(temp);
            personsArray[personsCount++] = temp;
            
            break;
            case 1: // an arrow (<person> or </person>)
             
             
              // sprintf(logMessage, "Discarded Line: %s.", subToken);
              // appendToLogfile(logMessage);
            break;

            case 2: // an open parenthesis, phone number
              addPhoneToPerson(subToken, personsArray[personsCount-1]);
              
              
              // sprintf(logMessage, "Found a phone number in: %s.", subToken);
              // appendToLogfile(logMessage);
            break;
          }

        
          subToken = strtok_r(NULL, delimB, &subTokenCounter);
        }

      
      tokenA = strtok_r(NULL, delimA, &tokenACounter);
    }
  
    bytesRead = fread(buffer,sizeof(char), sizeof(buffer), dataFile);
  }








  free(buffCopy);
  free(logMessage);
  return(personsCount);
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

int checkInputType(char *inputLine){
  char *logMessage = malloc(128*sizeof(char));
  int ret = 0;
  size_t length = strlen(inputLine);
  int i = 0;
  sprintf(logMessage, "Checking Input Type for String: %s.", inputLine);


  for(i ; i<length; i++){
    if(inputLine[i] == '>' || inputLine[i]=='<'){
      ret = 1;
     // appendToLogfile("Found an Arrow.");
    }
    if(inputLine[i] == '('){
       ret = 2;
      // appendToLogfile("Found an Open Parentheses.");
    }
  }

  free(logMessage);
  return(ret);
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