#include <stdio.h>
#include <stdlib.h>
#define MAX 500  // Maximum digits for large factorials (e.g., 100!)
// Function prototypes
void input_values(int * destination, int size);
void multiply(int x, int res[], int *res_size);
void calculate_factorial(int n, char result[]);
void print_results(int * array, int size);
int main(void) {
    int test_cases;
    int * values;
    scanf("%d", &test_cases);
    // Allocate memory to store the input values
    values = (int *)malloc(test_cases * sizeof(int));
    // Check memory allocation
    if (values == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    // Store input values
    input_values(values, test_cases);
    printf("\n"); // Separate input from output
    // Print the results after all input is processed
    print_results(values, test_cases);
    free(values);
    return 0;
}
// Function to input all test case values
void input_values(int * destination, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &destination[i]);
    }
}
// Function to calculate factorial of a number and store it in result as a string
void calculate_factorial(int n, char result[]) {
    int res[MAX];
    res[0] = 1;
    int res_size = 1;
    for (int x = 2; x <= n; x++) {
        multiply(x, res, &res_size);
    }
    // Convert the result array (digits) into a string
    int index = 0;
    for (int i = res_size - 1; i >= 0; i--) {
        result[index++] = res[i] + '0';
    }
    result[index] = '\0';  // Null-terminate the string
}
// Function to multiply a large number by an integer x
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
// Function to print the factorial results
void print_results(int * array, int size) {
    char result[MAX];

    for (int i = 0; i < size; i++) {
        calculate_factorial(array[i], result);
        printf("%s\n", result);
    }
}
