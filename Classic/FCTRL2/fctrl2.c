/*
FCTRL2 - Small factorials
#math #big-numbers

You are asked to calculate factorials of some small positive integers.

Input

An integer t, 1 ≤ t ≤ 100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1 ≤ n ≤ 100.

Output

For each integer n given at input, display a line with the value of n!

Example

Input:
4
1
2
5
3

Output:
1
2
120
6
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 500
void input_values(int * destination, int size);
void multiply(int x, int res[], int *res_size);
void calculate_factorial(int n, char result[]);
void print_results(int * array, int size);
int main(void) {
    int test_cases;
    int * values;
    scanf("%d", &test_cases);
    values = (int *)malloc(test_cases * sizeof(int));
    if (values == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    input_values(values, test_cases);
    printf("\n");
    print_results(values, test_cases);
    free(values);
    return 0;
}
void input_values(int * destination, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &destination[i]);
    }
}
void calculate_factorial(int n, char result[]) {
    int res[MAX];
    res[0] = 1;
    int res_size = 1;
    for (int x = 2; x <= n; x++) {
        multiply(x, res, &res_size);
    }
    int index = 0;
    for (int i = res_size - 1; i >= 0; i--) {
        result[index++] = res[i] + '0';
    }
    result[index] = '\0';
}
void multiply(int x, int res[], int *res_size) {
    int carry = 0;
    for (int i = 0; i < *res_size; i++) {
        int product = res[i] * x + carry;
        res[i] = product % 10;
        carry = product / 10;
    }
    while (carry) {
        res[(*res_size)++] = carry % 10;
        carry /= 10;
    }
}
void print_results(int * array, int size) {
    char result[MAX];
    for (int i = 0; i < size; i++) {
        calculate_factorial(array[i], result);
        printf("%s\n", result);
    }
}
