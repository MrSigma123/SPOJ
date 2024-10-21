/*
SMPSEQ8 - Fun with Sequences (Act 6)
#simple-math #basics

You are given a sequence of n integers S = s1, s2 ... sn and a sequence of
m integers Q = q1, q2 ... qm. If q1 + q2 + ... + qm < s1 + s2 + ... + sn
please print the sequence S and otherwise please print the sequence Q.

Input data specification

In the first line you are given one integer 2 <= n <= 100, and in the
following line n integers:
-100 <= si <= 100.

In the third line you are given one integer 2 <= m <= 100, and in the
following line m integers:
-100 <= qi <= 100.

Output data specification

The sequence of requested integers separated by spaces.

Example 1

Input:
5
-2 -1 0 1 4
6
-3 -2 -1 1 2 3

Output:
-2 -1 0 1 4
Example 2

Input:
5
-2 -1 0 1 2
6
-3 -2 -1 1 2 3

Output:
-3 -2 -1 1 2 3
*/
