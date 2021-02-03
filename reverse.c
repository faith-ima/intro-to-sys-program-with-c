#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//reverse function to reverse a string which takes in a line of string as input
char *reverseString(char *line){
  int lastCharIndex = strlen(line)-1;
  int reverseIndex=0;
  //store the string
  char *reverseString = (char *)(malloc(sizeof(char *)));
  //if malloc fails to allocate memory
  if(reverseString == NULL){
    fprintf(stderr, "malloc failed");
    exit(1);
  }
  //move the cursor al the way to the last character (length-1)
  for(int i=strlen(line)-1; i>= 0; i--){
    //if the next character is a space, then it is a new word
    if(line[i] == ' '){
      //move rightward to the last character index of the current word
      for(int j=i+1; j<=lastCharIndex; j++){
        //reverseIndex should represent the current location which will get added to the array
        reverseString[reverseIndex] = line[j];
        //iterate over
        reverseIndex++;
      }//end for j
      //strcat(reverseString++, " ");
      reverseString[reverseIndex++] = ' ';
      //update the new lastCharIndex
      lastCharIndex = i-1;
    }//end if
  }//end for
  //add each word in sequence
  for(int k=0; k<=lastCharIndex; k++){
    reverseString[reverseIndex] = line[k];
    reverseIndex++;
  }//end for
  reverseString[reverseIndex] = '\0';//terminate string
  return reverseString;
}//end reverse


int main(int argc, char *argv[]){
  //when invoked without argument, read from input and print to screen
  if(argc == 1){
    fprintf(stdout, "Enter string to reverse:\n");
    //store user input
    char *input = (char *)(malloc(sizeof(char *)));
    //if malloc fails to allocate memory
    if(input == NULL){
      fprintf(stderr, "malloc failed");
      exit(1);
    }
    gets(input);
    //call reverse function to print out in reverse to screen
    fprintf(stdout, "%s\n", reverseString(input));
  }//end if argc ==1

  //When invoked with just one command-line argument, the user supplies the input file
  else if(argc == 2){
    //open the file for reading
    FILE *inputFile = fopen(argv[1], "r");
    //check if the file was properly opened
    if(inputFile == NULL){
      fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
      exit(1);
    }
    //if opened, get the line
    char *buffer = NULL;
    size_t bufsize;
    size_t linesRead;
    //if error occurs getLine returns -1
    while((linesRead= getline(&buffer, &bufsize, inputFile))!= -1){
      buffer[linesRead-1] = '\0';//terminate string
      //print to screen the output
      fprintf(stdout, "%s\n", reverseString(buffer));
    }
  }//end else if argc ==2


  //when invoked with two command-line arguments, it also writes to file
  else if(argc == 3){
    //If the input file and output file are the same file
    if(strcmp(argv[1], argv[2])== 0){
      fprintf(stderr, "Input and output file must differ\n");
      exit(1);
    }
    //open the file for reading
    FILE *inputFile = fopen(argv[1], "r");
    //check if the file was properly opened
    if(inputFile == NULL){
      fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
      exit(1);
    }
    //initialize the output file
    FILE *outputFile = fopen(argv[2], "w");
    //check if file was properly opened
    if(outputFile == NULL){
      fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
      exit(1);
    }
    //if opened, get the lines
    char *buffer = NULL;
    size_t bufsize;
    size_t linesRead;
    //if error occurs getLine returns -1]
    while((linesRead = getline(&buffer, &bufsize, inputFile))!= -1){
      buffer[linesRead-1] = '\0';
      //print to output file provided
      fprintf(outputFile, "%s\n", reverseString(buffer));
      }
      fclose(outputFile);
    }//end if argc ==3

  //if too many arguments are passsed
  else if (argc > 3){
      fprintf(stdout, "usage: reverse <input> <output>\n");
      exit(1);
  }//end else if too argc >3

  return 0;
}//end main
