/*
KAMIL - Kamil
no tags 

Some kids cannot pronounce all letters, some of them they sometimes pronounce
correctly and sometimes incorrectly. Kamil sometimes says T instead of K, but
he never says K instead of T. Similarly he sometimes says D instead of G.
Instead of R he sometimes says L and sometimes F. Of course it happens that
he pronounces the letter correctly. Kamil's father always thinks how many words
can mean the word spoken by his son (it doesn't matter if they are real English
words).

Task

Write a program which

reads from standard input the words spoken by Kamil
counts how many different words can that mean
writes the outcome on standard output
 

Input

Ten test cases (given one under another, you have to process all!). Every test
case is a single line - a word spoken by Kamil. Only 26 capital leters are
used. The length of the word is at most 20.

Output

For every testcase write an integer in a single line with a single integer,
denoting the number of words which Kamil's word can mean.

Score

The score awarded to your program is the number of bytes the source code you
submit. The fewer points you score, the better. Submissions are not allowed to
exceed 256 bytes.

Remark. It may turn out impossible to solve this problem in some languages.

Example

Input:
FILIPEK
[and 9 test cases more]

Output:
4
[and 9 test cases more]
*/
#include <stdio.h>
int r,i,j;char s[21];int main(){for(i=0;i<10;i++){fgets(s,21,stdin);r=1;for(j=0;s[j]>32;j++)if(s[j]=='T'||s[j]=='D'||s[j]=='L'||s[j]=='F')r*=2;printf("%d\n",r);}return 0;}
