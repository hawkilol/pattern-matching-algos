/* BMH*/
//#include "bmh.h"

#include <string.h>
#include <stdio.h>

#include <limits.h>

# define N_CHARS 256


int max (int a, int b) {
  if(a > b){return a;}
  else{return b;}
}

void badCharHeuristic( char *str, int size,
						int badchar[N_CHARS])
{
	int i;

	for (i = 0; i < N_CHARS; i++)
		badchar[i] = -1;

	for (i = 0; i < size; i++)
		badchar[(int) str[i]] = i;
}

void bmh(char* txt, int txtLen, char* pattern, int patternLen)
{
	int m = strlen(pattern);
	int n = strlen(txt);

	int badchar[N_CHARS];

	badCharHeuristic(pattern, m, badchar);

	int s = 0; 
				
	while(s <= (n - m)){
		int j = m-1;

		while(j >= 0 && pattern[j] == txt[s+j])
			j--;

		if (j < 0){
			printf("\n pattern found at shift i = %d", s);

			if(s+m < n){
				s += m-badchar[txt[s+m]];
			}
			else{
				s++;
			}
		}

		else
			s += max(1, j - badchar[txt[s+j]]);
	}
}

