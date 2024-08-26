/*
EXPECT - Life, the Universe, and Everything (Interactive)
no tags 

Note for Interactive problem setters: if you are stucked on how to
write a interactive problem judge, you may send a mail to "blue.mary.me@qq.com".
It will send you the custom judge of this problem.
Your program is to use the brute-force approach in order to find the Answer to
Life, the Universe, and Everything. More precisely... rewrite small numbers from
input to output. Stop processing input after reading in the number 42.
All numbers at input are integers of one or two digits.

Interactive Protocol

You should communicate with Judge using standard input and output.

Attention: the program should clear the output buffer after printing each line.

It can be done using fflush(stdout) command or by setting the proper type of
buffering at the beginning of the execution - setlinebuf(stdout).
Each time the judge will give you a number. You should rewrite this number to
standard output. If this number equals 42, after rewriting your program should
terminate immediately.

Example

The example of communication.

Input:
3
15
42

Output:
3
15
42
Attention: the program should clear the output buffer after printing each line.

Reference

Please pay attention that: your program should NOT output any extra characters
like "J","P" or “:". Follow the interactive protocol strictly. A sample program
(in C++) that can get Accepted is as the following:

#include <stdio.h>
int main(){
  int n;
  while(true){
    scanf("%d", &n);
    printf("%d\n", n);
    fflush(stdout);
    if(n == 42)break;
  }
  return 0;
}

*/
#include <stdio.h>
int main(void)
{
  int input;
  while(1)
  {
    scanf("%d", &input);
    printf("%d\n", input);
    fflush(stdout);
    if(input == 42)
      break;
  }
  printf("\n");
  return 0;
}
