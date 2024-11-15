/*
COMMEDIA - Commedia dell Arte
no tags 

So called commedia dell' arte is a theater genre first played in Italy at
the beginning of the sixteenth century. It was inspired with the Roman Theater.
The play had no fixed script and the actors (also called performers) had to
improvise a lot. There were only a simple directions by the author like "enter
the stage and make something funny" or "everyone comes on stage and everything
is resolved happily". You can see it might be very interesting to play the
commedia dell' arte. Therefore the ACM want to put a new play on a stage,
which was completely unknown before. The main hero has a puzzle that takes
a very important role in the play and gives an opportunity of many
improvisations. The puzzle is the worldwide known Lloyd's Fifteen Puzzle.
ACM wants to make the play more interesting so they want to replace the
"standard" puzzle with a three-dimensional one. The puzzle consists of a
cube containing M3 slots. Each slot except one contains a cubic tile
(one position is free). The tiles are numbered from 1 to M3-1. The goal of
the puzzle is to get the original ordering of the tiles after they have been
randomly reshuffled. The only allowed moves are sliding a neighbouring tile
into the free position along one of the three principal directions. Original
configuration is when slot with coordinates (x,y,z) from {0,...,M-1}3
contains tile number z.M2+y.M+x+1 and slot (M-1,M-1,M-1) is free.

You are to write a program to determine whether it is possible to solve the
puzzle or not.

Input

The input consists of N cases. The first line of the input contains only
positive integer N. Then follow the cases. The first line of each case
contains only one integer M, 1 <= M <= 100. It is the size of 3D puzzle
cube. Then follow M lines, each contains exactly M2 numbers on the tiles
for one layer. First is the layer on the top of the cube and the last one
on the bottom. In each layer numbers are arranged from the left top corner
linewise to the right bottom corner of the layer. In other words, slot with
coordinates (x,y,z) is described by the (x+M.y+1)-th number on the (z+1)-th
line. Numbers are separated by space. Number 0 means free position.

Output

For each case, print exactly one line. If the original configuration can be
reached by sliding the tiles, print the sentence 'Puzzle can be solved.'.
Otherwise, print the sentence 'Puzzle is unsolvable.'.

Example

Sample input:
2
2
1 2 3 4
5 7 6 0
2
2 1 3 5
4 6 0 7

Sample output:
Puzzle is unsolvable.
Puzzle can be solved.
Warning: large Input/Output data, be careful with certain languages
*/
