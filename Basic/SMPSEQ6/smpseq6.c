/*
SMPSEQ6 - Fun with Sequences (Act 4)
#simple-math #basics

You are given S - a sequence of n integers S = s1, s2 ... sn, Q - a sequence
of n integers Q = q1, q2 ... qn and a nonnegative parameter x.

Please print in ascending order all such i, that si = qi+y, where -x <= y <= x.

Input data specification

In the first line you are given two integers 2 <= n <= 100, 0 <= x < n and in
the following two lines n integers in each of the line:
-100 <= si, qi <= 100

Output data specification

The sequence of requested integers separated by spaces.

Example 1

Input:
5 2
-1 2 -1 1 -1
3 -2 -1 1 2

Output:
1 3 4 5
Example 2

Input:
6 4
-1 2 2 2 2 -2
3 -2 3 3 3 -1

Output:
6
Example 3

Input:
6 0
-1 2 10 12 6 -2
2 -2 10 21 6 -1
 
Output:
3 5
*/
