#include <stdio.h>

int main() {
    int num, sum = 0, count = 0;

    printf("Enter the integer sequence (separated by spaces): ");

    // Keep reading integers until a newline character is encountered
    while (scanf("%d", &num) == 1) {
        sum += num;  // Accumulate the sum of integers
        count++;     // Increment the count of integers
    }

    // Check if at least one integer was entered
    if (count > 0) {
        double average = (double)sum / count;  // Calculate the average

        // Display the results
        printf("Size: %d\n", count);
        printf("Average: %.3f\n", average);
    } else {
        printf("No integers entered.\n");
    }

    return 0;
}
