#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//max size of input
#define SIZE 2000

int main(int argc, char *argv[]){
  //location to store the search term
  char *searchterm;
  //location to store the file if any
  char *filename;
  FILE *fptr;
  char buffer[SIZE];
  //if passed no command line args
  if(argc < 2){
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  }

  //program is always passed search term but not file
  //so argument count will always be 1 or more
  //if no file is entered
  else if(argc == 2){
    //argc ranges from argv[0] to argv[argc-1], strlen function to get the length
    searchterm = (char *)(malloc(strlen(argv[argc-1]))+1);
    if(searchterm == NULL){
      printf("Sufficient memory could not be allocated.");
    }
    //put the input in place of the searchterm
    strcpy(searchterm, argv[argc-1]);
    //if searchterm but no file is specified, read from input
    printf("Enter strings to scan through and enter quit to exit.\n");
    if(strcmp(searchterm, "") != 0){
      while(fgets(buffer, SIZE, stdin)){
        buffer[strlen(buffer)-1] ='\0';
        //compare the string with the searchterm
        if(strstr(buffer, searchterm)){
          printf("%s\n", buffer);
        }
        //to exit the loop
        if(!strcmp(buffer, "quit")){
          break;
        }
      }
    }
    exit(0);
  }//end else if
  //else if there is an entered filename and argc>3
  else{
    int i;
  for(i=2; i<argc; i++){
    filename = (char *)(malloc(strlen(argv[i]))+1);
    //place the input in filename storage
    strcpy(filename, argv[i]);
    //then update the searchterm to match new postion
    searchterm = (char *)(malloc(strlen(argv[1]))+1);
    strcpy(searchterm, argv[1]);
  //open the file
    fptr = fopen(filename, "r");
  if(fptr == NULL){
      printf("wgrep: cannot open file\n");
      exit(1);
    }
    //after reading from the file, compare the strings
    //check if passed empty string as a search term
    if(strcmp(searchterm, "") != 0){
      while(fgets(buffer, SIZE, fptr)){
        buffer[strlen(buffer)-1]= '\0';//terminate string
        //compare the string with the searchterm
        if(strstr(buffer, searchterm)){
          printf("%s\n", buffer);
        }
      }//end while
    }
  }//end for
  }//end else
  exit(0);
}//end main
