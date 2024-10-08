/*
SAMER08F - Feynman
no tags 

Richard Phillips Feynman was a well known American physicist and a recipient
of the Nobel Prize in Physics. He worked in theoretical physics and also
pioneered the field of quantum computing. He visited South America for ten
months, giving lectures and enjoying life in the tropics. He is also known
for his books "Surely You're Joking, Mr. Feynman!" and "What Do You Care
What Other People Think?", which include some of his adventures below the
equator.

His life-long addiction was solving and making puzzles, locks, and cyphers.
Recently, an old farmer in South America, who was a host to the young
physicist in 1949, found some papers and notes that is believed to have
belonged to Feynman. Among notes about mesons and electromagnetism, there
was a napkin where he wrote a simple puzzle: "how many different squares
are there in a grid of N ×N squares?".

In the same napkin there was a drawing which is reproduced below, showing
that, for N=2, the answer is 5.

subir imagenes

Input

The input contains several test cases. Each test case is composed of a
single line, containing only one integer N, representing the number of
squares in each side of the grid (1 ≤ N ≤ 100).

The end of input is indicated by a line containing only one zero.

Output

For each test case in the input, your program must print a single line,
containing the number of different squares for the corresponding input.

Example

Input:
2
1
8
0

Output:
5
1
204
*/

#include <stdio.h>
#include <stdlib.h>

int allocate_memory(int ** in, int ** out, int size);
int scan_input(int ** array, int size);
void calculate_output(int * input, int * output, int size);
void display_output(int * output, int size);

int main(void)
{
  int test_cases = 10;
  int * input;
  int * output;
  
  // allocate the memory
  if (1 == allocate_memory(&input, &output, test_cases))
  {
    return 1;
  }

  // store the input values
  test_cases = scan_input(&input, test_cases);

  // calculate the output
  calculate_output(input, output, test_cases);
   
  // display the output
  display_output(output, test_cases);

  // free allocated memory
  free(input);
  free(output);

  return 0;
}

int allocate_memory(int ** in, int ** out, int size)
{
  *in = (int *)malloc(size * sizeof(int));
  *out = (int *)malloc(size * sizeof(int));
  if (*in != NULL && *out != NULL)
  {
    return 0;
  }
  else
  {
    printf("Memory allocation failed!\n");
    return 1;
  }
}

int scan_input(int ** array, int size)
{
  int i = 0;
  int current_size = size;
  int * temp;

  while (1)
  {
    // check if the size is exceeded
    if (i >= current_size)
    {
      current_size += size; // increase the size
      temp = realloc(*array, current_size * sizeof(int));
      if (temp == NULL)
      {
        printf("Memory allocation failed!\n");
        return i; // returns number of the elements read so far
      }
      *array = temp; // update the array with the reallocated memory
    }

    scanf("%d", &(*array)[i]);
    if ((*array)[i] == 0)
    {
      break;
    }
    i++; // move to the next index 
  }
  return i; // array size
}

void calculate_output(int * input, int * output, int size)
{
  int i, j;
  for (i = 0; i < size; i++)
  {
    output[i] = 0;
    for (j = 1; j <= input[i]; j++)
    {
      output[i] += j*j;
    }
  }
}

void display_output(int * output, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%d\n", output[i]);
  }
}
