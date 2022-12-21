#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 5000

// Preprocess the pattern string to create a bit mask
void preprocess_pattern(char *pattern, unsigned long long *mask)
{
  int i;
  int pattern_len = strlen(pattern);

  for (i = 0; i < pattern_len; i++)
  {
    mask[pattern[i]] |= 1ull << i;
  }
}

// Perform the Shift-And algorithm on the text string
void shift_and(char *text, char *pattern, int *occurrences, int *count)
{
  int i;
  int text_len = strlen(text);
  int pattern_len = strlen(pattern);
  unsigned long long mask[256];
  unsigned long long D = 0;

  // Initialize the bit mask
  for (i = 0; i < 256; i++)
  {
    mask[i] = 0;
  }

  // Preprocess the pattern string
  preprocess_pattern(pattern, mask);

  // Perform the Shift-And algorithm
  for (i = 0; i < text_len; i++)
  {
    D = (D << 1 | 1) & mask[text[i]];
    if (D & (1ull << (pattern_len - 1)))
    {
      occurrences[*count] = i - pattern_len + 1;
      (*count)++;
    }
  }
}
