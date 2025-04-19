#include <stdio.h>
#include <string.h>


int main(){
  FILE* file = fopen("hello.txt", "w");
  if(file == NULL){
    perror("File not found!!!");
    return 1;
  }
  const char* string = "Hello World!";
  fwrite(string, strlen(string), 1, file);
  fclose(file);
  return 0;
}