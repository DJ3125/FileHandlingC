#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
  FILE *file = fopen("reallyLongFile.txt", "r");
  if(file == NULL){
    perror("Error opening file");
    return 1;
  }
  int isGoing = 1;
  int lineNum = 1;
  const int BUFFER_LENGTH = 1000;
  char buffer[BUFFER_LENGTH];
  while(isGoing){
    if(fgets(buffer, BUFFER_LENGTH, file) == NULL){
      fprintf(stdout, "End of File");
      isGoing = 0;
      continue;
    }
    fprintf(stdout, "Do you want to read more?\n");
    const int RESPONSE_BUFFER_LENGTH = 10;
    char input[RESPONSE_BUFFER_LENGTH];
    fgets(input, RESPONSE_BUFFER_LENGTH, stdin);
    if(input[0] != 'y' && input[0] != 'Y'){
      isGoing = 0;
      continue;
    }
    fprintf(stdout, "\nLine %d: %s\n", lineNum++, buffer);
    
  }
  fclose(file);
  return 0;
}