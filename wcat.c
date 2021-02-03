#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000 //set buffer size to be max of 1000 characters

//rep the argument count and the argument vector
int main(int argc, char *argv[]){
  //loop through the entire filepath entered
  for(int i=1; i<argc; i++){
    //store the file in a location for reading
    FILE *fptr = fopen(argv[i], "r");
    //message to be printed if the file cannot be accessed exit with status code 1
    if(fptr == NULL){
      printf("wcat:cannot open file.\n");
      exit(1);
    }//end if
    else{
      //storage for
      char buffer[SIZE];
      //while loop to print the contents to screen
      //where the file is stored, the maximum size, and the location they are read from
      while(fgets(buffer, SIZE, fptr))  {
      printf("%s", buffer);
    }
printf("\n");
      }//end else
      //close the file after printing and exit main with status code 0
      fclose(fptr);
  }
  exit(0);
}//end main
