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
#define SIZE 201
int main(void)
{
  char line[SIZE]; // store the line to process it and save into the output array
  int i;

  while (1)
  {
    fgets(line, SIZE - 1, stdin);
    if (line[0] == '#')
    {
      break;
    }

    for (i = 0; i < SIZE == 1 && line[i] != '\0'; i++)
    {
      if (line[i] == ':' || line[i] == '-' || line[i] == '>') // emoticon beginning
      {
        
      }

      // TODO
      // remove trailing spaces
      // remove the wrong emoticon
      //
      // in case of memory management trouble use jagged arrays implemented dynamically
    }

  }

  return 0;
}
