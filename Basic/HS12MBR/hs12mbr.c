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
#include <stdlib.h>
#include <limits.h> // For INT_MAX and INT_MIN

int main(void)
{
  int test_cases;
  int ***cases; // approach with jagged arrays
  int *subcases_arr; // Array to store number of subcases for each test case
  int i, j, obj_type;

  // Read the number of test cases
  scanf("%d", &test_cases);

  // Allocate memory for storing the MBR results (min_x, min_y, max_x, max_y for each test case)
  int **mbr_results = (int **)malloc(test_cases * sizeof(int *));
  for (i = 0; i < test_cases; i++) {
    mbr_results[i] = (int *)malloc(4 * sizeof(int)); // 4 values: min_x, min_y, max_x, max_y
  }

  // Allocate memory for test cases (for the input data)
  cases = (int ***)malloc(test_cases * sizeof(int **));
  subcases_arr = (int *)malloc(test_cases * sizeof(int)); // To store the number of subcases for each test case

  if (cases == NULL || subcases_arr == NULL) // Check for allocation failure
  {
    printf("Memory allocation failed!\n");
    return 1;
  }

  // For specific subcases
  for (i = 0; i < test_cases; i++)
  {
    scanf("%d", &subcases_arr[i]); // Store the number of subcases for each test case
    // Allocate the memory for subcases
    cases[i] = (int **)malloc(subcases_arr[i] * sizeof(int *));

    if (cases[i] == NULL) // Check for allocation failure
    {
      printf("Memory allocation failed!\n");
      return 1;
    }

    // Initialize MBR bounds for each test case
    int min_x = INT_MAX, min_y = INT_MAX;
    int max_x = INT_MIN, max_y = INT_MIN;

    for (j = 0; j < subcases_arr[i]; j++)
    {
      scanf(" %c", (char *)&obj_type); // Read obj_type as a character

      // Handle points
      if (obj_type == 'p') // for points, 'p' is 112
      {
        cases[i][j] = (int *)malloc(3 * sizeof(int)); // x, y for point
        // Store the data directly in the array
        cases[i][j][0] = obj_type; // Store the type ('p')
        scanf("%d%d", &cases[i][j][1], &cases[i][j][2]); // Read x, y for point

        int x = cases[i][j][1];
        int y = cases[i][j][2];

        // Update MBR for point
        if (x < min_x) min_x = x;
        if (y < min_y) min_y = y;
        if (x > max_x) max_x = x;
        if (y > max_y) max_y = y;
      }
      // Handle circles
      else if (obj_type == 'c') // for circles, 'c' is 99
      {
        cases[i][j] = (int *)malloc(4 * sizeof(int)); // x, y, r for circle
        cases[i][j][0] = obj_type; // Store the type ('c')
        // Store x, y, r directly in the array
        scanf("%d%d%d", &cases[i][j][1], &cases[i][j][2], &cases[i][j][3]);

        int x = cases[i][j][1];
        int y = cases[i][j][2];
        int r = cases[i][j][3];

        // Update MBR for circle
        if (x - r < min_x) min_x = x - r;
        if (y - r < min_y) min_y = y - r;
        if (x + r > max_x) max_x = x + r;
        if (y + r > max_y) max_y = y + r;
      }
      // Handle lines
      else if (obj_type == 'l') // for lines, 'l' is 108
      {
        cases[i][j] = (int *)malloc(5 * sizeof(int)); // x1, y1, x2, y2 for line
        cases[i][j][0] = obj_type; // Store the type ('l')
        // Store x1, y1, x2, y2 directly in the array
        scanf("%d%d%d%d", &cases[i][j][1], &cases[i][j][2], &cases[i][j][3], &cases[i][j][4]);

        int x1 = cases[i][j][1];
        int y1 = cases[i][j][2];
        int x2 = cases[i][j][3];
        int y2 = cases[i][j][4];

        // Update MBR for line
        if (x1 < min_x) min_x = x1;
        if (y1 < min_y) min_y = y1;
        if (x2 < min_x) min_x = x2;
        if (y2 < min_y) min_y = y2;
        if (x1 > max_x) max_x = x1;
        if (y1 > max_y) max_y = y1;
        if (x2 > max_x) max_x = x2;
        if (y2 > max_y) max_y = y2;
      }
    }

    // Store the MBR results for this test case
    mbr_results[i][0] = min_x;
    mbr_results[i][1] = min_y;
    mbr_results[i][2] = max_x;
    mbr_results[i][3] = max_y;

    printf("\n");
  }

  // After all input has been processed, output the results for each test case
  for (i = 0; i < test_cases; i++) {
    printf("%d %d %d %d\n", mbr_results[i][0], mbr_results[i][1], mbr_results[i][2], mbr_results[i][3]);
  }

  // Free the memory for the MBR results
  for (i = 0; i < test_cases; i++) {
    free(mbr_results[i]);
  }
  free(mbr_results);

  // Free the memory for test cases
  for (i = 0; i < test_cases; i++) {
    for (j = 0; j < subcases_arr[i]; j++) { // Use subcases_arr[i] to free correctly
      free(cases[i][j]);
    }
    free(cases[i]);
  }
  free(cases);
  free(subcases_arr); // Free the subcases array

  return 0;
}

