#include <stdio.h>

int main() {
    // Declare variables
    int N, sum = 0;

    // Input a positive integer N
    printf("Enter a positive integer N: ");
    scanf("%d", &N);

    // Check if N is positive
    if (N <= 0) {
        printf("Please enter a positive integer.\n");
        return 1; // Exit the program with an error code
    }

    // Calculate the sum of values between 1 and N that are divisible by 3
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0) {
            sum += i;
        }
    }

    // Display the result
    printf("The sum of values between 1 and %d that are divisible by 3 is: %d\n", N, sum);

    return 0; // Exit the program successfully
}
