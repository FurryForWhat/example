#include <stdio.h>
#include <ctype.h>

int main() {
    // Declare variables
    char sentence[1000];
    int wordCount = 0;

    // Input a sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Count phrases, total words, and characters
    int charCount[256] = {0}; // Array to store character frequencies

    for (int i = 0; sentence[i] != '\0'; i++) {
        // Increment word count if a space or newline is found
        if (sentence[i] == ' ' || sentence[i] == '\n') {
            wordCount++;
        } else {
            // Increment character count only if it's not a space
            charCount[(unsigned char)sentence[i]]++;
        }
    }

    // Display the result
    printf("Total number of words: %d\n", wordCount);

    // Display character frequencies for characters present in the sentence
    for (int i = 0; i < 256; i++) {
        if (charCount[i] > 0 && i != ' ') {
            printf("%c : %d, ", i, charCount[i]);
        }
    }

    return 0; // Exit the program successfully
}
