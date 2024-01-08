#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100

int main() {
    // Declare variables
    char sentence[1000];
    char words[MAX_WORDS][50]; // Array to store encountered words
    int wordCount = 0;

    // Input a sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Output sentence with repeated words removed
    printf("Output: ");

    char *token = strtok(sentence, " \n");
    
    while (token != NULL) {
        int isRepeated = 0;

        // Convert the word to lowercase for case-insensitivity
        for (int i = 0; token[i] != '\0'; i++) {
            token[i] = tolower(token[i]);
        }

        // Check if the lowercase word has been encountered before
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                isRepeated = 1;
                break;
            }
        }

        // If the word is not repeated, print it and store it
        if (!isRepeated) {
            printf("%s ", token);
            strcpy(words[wordCount], token);
            wordCount++;

            // Ensure we don't exceed the maximum number of words
            if (wordCount >= MAX_WORDS) {
                break;
            }
        }

        token = strtok(NULL, " \n");
    }

    printf("\n");

    return 0; // Exit the program successfully
}
