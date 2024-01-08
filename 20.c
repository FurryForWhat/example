#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 31

void addLargeIntegers(char num1[], char num2[], char result[]) {
    int carry = 0;
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    int maxLength = (length1 > length2) ? length1 : length2;

    for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < length1) ? num1[length1 - 1 - i] - '0' : 0;
        int digit2 = (i < length2) ? num2[length2 - 1 - i] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        result[maxLength - i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry > 0) {
        result[0] = carry + '0';
        result[maxLength + 1] = '\0';
    } else {
        result[0] = '\0';
    }
}

int main() {
    char num1[MAX_DIGITS];
    char num2[MAX_DIGITS];
    char result[MAX_DIGITS + 1]; // +1 for the null terminator
    int calculationLimit;
    int calculationCount = 0;

    printf("Enter the calculation limit: ");
    scanf("%d", &calculationLimit);

    printf("Enter the first large integer (not exceeding 30 digits): ");
    scanf("%s", num1);

    printf("Enter the second large integer (not exceeding 30 digits): ");
    scanf("%s", num2);

    while ((num1[0] != '0' || num2[0] != '0') && calculationCount < calculationLimit) {
        addLargeIntegers(num1, num2, result);
        calculationCount++;

        printf("Calculation %d: %s + %s = %s\n", calculationCount, num1, num2, result);

        // Copy the result back to num1 for the next iteration
        strcpy(num1, result);

        // Get the next input for num2
        printf("Enter the next large integer (enter '0' to stop): ");
        scanf("%s", num2);
    }

    printf("Total number of calculations: %d\n", calculationCount);

    return 0;
}
