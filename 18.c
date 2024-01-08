#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];

    // Input a string
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Shift each letter to the next letter in the alphabet
    for (int i = 0; input[i] != '\0'; i++) {
        char currentChar = input[i];

        // Check if the character is an alphabetical letter
        if (isalpha(currentChar)) {
            // Shift the letter to the next letter in the alphabet
            char shiftedChar = (currentChar == 'a' || currentChar == 'A') ? currentChar + 25 : currentChar - 1;
            printf("%c", shiftedChar);
        } else {
            // Print non-alphabetic characters as they are
            printf("%c", currentChar);
        }
    }

    printf("\n");

    return 0;
}
