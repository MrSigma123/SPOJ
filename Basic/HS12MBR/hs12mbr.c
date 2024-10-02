/*
HS12MBR - Minimum Bounding Rectangle
#plane-geometry #basics

Compute the Minimum Bounding Rectangle (MBR) that surrounds the given set of
2D objects, i.e., the axis-aligned rectangle, which contains all of the
specified objects and is the one with minimum area among all rectangles
with this property.

Input

First, you are given t (t<100) - the number of test cases.

Each of the test cases starts with one integer n (n < 100) - the number
of objects in the set. In the successive n lines, the descriptions of the
objects follow.

Each object is described by one character and some parameters:

a point: p x y, where x and y are point coordinates.
a circle: c x y r, where x and y are the center coordinates and r is the
radius of the circle.
a line segment: l x1 y1 x2 y2, where xi, yi are the coordinates of the
endpoints of the line.
Successive test cases are separated by an empty line.

Output

For each of the test cases output four numbers - the coordinates of the
two points that correspond to the lower left and the upper right corner
of the MBR, in the following order: first the x-coordinate of the lower
left corner, then the y-coordinate of the lower left corner,
the x-coordinate of the upper right corner and the y-coordinate of
upper right corner.

You can assume that all object parameters are integers and that
-1000 -1000 1000 1000 is a bounding rectangle for all of them.

Example

Input:
3
1
p 3 3 

2
c 10 10 20
c 20 20 10

1
l 0 0 100 20

Output:
3 3 3 3 
-10 -10 30 30
0 0 100 20
Test case description

test 1: points only    (2 pts)
test 2: circles only   (2 pts) 
test 3: lines only     (2 pts)
test 4: mixed          (2 pts)
test 5: mixed          (2 pts)
*/

#include <stdio.h>
int main(void)
{
  int test_cases;
  scanf("%d", &test_cases);


  return 0;
}
