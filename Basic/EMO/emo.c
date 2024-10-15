/*
EMO - Emoticons
no tags 

Who doesn't use emoticons while chatting and of course who doesn't make
mistakes! For example, we often type
:o or :[ instead of :p
-_ or -__ instead of -_-
:* instead of :( (Beware sometimes these can be fatal :P)

Now it's up to computer scientists to do something to avoid such problems.
Good news is that Voogle have managed to detect what should be the correct
emo for any sentence! All that left is to replace the faulty emoticons with
the correct ones. As a computer programmer, you are given the job. Can you
do it?

Input

Input data consists of several lines containing emoticons at places. Each
line ends with a full stop. End of input is indicated by “#” without quote,
which should not be processed. Emoticons start with some special characters
(see below) and is at least 2 characters long. They come in pairs, first
one is the expected one and the second one is typed.

It is guaranteed that there is a space before and after every emoticon.
2 ≤ length of each emo ≤ 5
Each line contains at least one emoticon.
Any emo start with one of these characters: {:, -, >}
Number of total characters doesn’t exceed 106

Output

Corrected text after replacing all the emoticons pairs with the correct ones.
There should be exactly one space before and another one after each emo.
A single space is used to separate two adjacent words in a sentence. See
sample for details.
Input might have unnecessary spaces, discard them.

Example

Input:
Always remember: “For every problem there is a fast, easy and wrong solution” :P :[ . 
Sometimes a line :O :T may contain only emoticons like the next  one.
 -_- -__ .
 And can be of different lengths too -_- -_ .
Even if both emoticons in a pair are correct, only one remains, Consider this case: :/ :) .
#



Output:
Always remember: "For every problem there is a fast, easy and wrong solution" :P .
Sometimes a line :O may contain only emoticons like the next one.
 -_- .
And can be of different lengths too -_- .
Even if both emoticons in a pair are correct, only one remains, Consider this case: :/ .

Note: In the third line of both the input and output, there is a space before the emo.

Special Thanks to Sakibul Mowla.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 201 // for storing long input line
int main(void)
{
  int size = 10; // starting value
  int new_size;
  int i;
  char ** strings_input;
  char ** strings_output; // TODO: implement...

  // allocate memory for an array of char pointers
  // (each pointer will point to a string)
  strings_input = (char **)malloc(size * sizeof(char *));
  if (strings_input == NULL)
  {
    printf("Memory allocation failed!\n");
    return 1;
  }

  // Loop to input strings and dynamically increase the size when needed
  while (1)
  {
    if (i >= size)
    {
      // Double the size when i exceeds the current allocated size
      new_size = size * 2;
      strings_input = (char **)realloc(strings_input, new_size * sizeof(char *));
      if (strings_input == NULL)
      {
        printf("Memory reallocation failed!\n");
        return 1;
      }
      size = new_size;
    }

    // Allocate memory for each string (assuming max 100 characters per string)
    strings_input[i] = (char *)malloc(100 * sizeof(char));
    if (strings_input[i] == NULL)
    {
      printf("Memory allocation failed for string %d!\n", i);
      return 1;
    }

    printf("Enter string %d (or type 'exit' to stop): ", i + 1);
    fgets(strings_input[i], 100, stdin);  // Read string from user
    strings_input[i][strcspn(strings_input[i], "\n")] = '\0';  // Remove newline character

    // Exit the loop if the user types "exit"
    if (strcmp(strings_input[i], "exit") == 0)
    {
      free(strings_input[i]);  // Free memory for the "exit" string
      break;
    }

    i++;
  }

  // Print the stored strings
  printf("\nYou entered the following strings:\n");
  for (int j = 0; j < i; j++) {
    printf("String %d: %s\n", j + 1, strings_input[j]);
  }

  // Free allocated memory
  for (int j = 0; j < i; j++)
  {
    free(strings_input[j]);  // Free each individual string
  }
  free(strings_input);  // Free the array of pointers

  return 0;
}
