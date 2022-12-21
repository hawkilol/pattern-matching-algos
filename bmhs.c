# BMHS - C
%%writefile bmhs.c
#include <stdio.h>
#include <string.h>
#include <time.h>

void bmhs(char* text, int textLength, char* pattern, int patternLength) {
  int maxChar = 256;
  int displacement[maxChar];
  // Assign default value to all letters
  for (int j = 0 ; j < maxChar; j++) {
    displacement[j] = patternLength + 1;
  }
  // Pattern letters shift value
  // Since the index starts at 0, it is not necessary to add 1
  for (int letterIndex = 0; letterIndex < patternLength; letterIndex++) {
    displacement[pattern[letterIndex]] =  patternLength - letterIndex;
  }

  // Adjust index to avoid out of bound error
  int i = patternLength - 1;
  
  while (i < textLength) {
    int textLetterIndex = i; 
    int patternLetterIndex = patternLength - 1;

    // Compare from right to left
    while ((patternLetterIndex >= 0) && (text[textLetterIndex] == pattern[patternLetterIndex])) { 
      patternLetterIndex--;
      textLetterIndex--;
    }
    
    // Match found in all pattern letters 
    if (patternLetterIndex < 0) {
      printf("Match from position %d to position %d", textLetterIndex + 1, textLetterIndex + patternLength); 
    }
    // Shift the text pattern 
    i = i + displacement[text[textLetterIndex+1]]; 
  }
}
