#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isOnlyVowels(char* string) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; string[i] != '\0'; i++) {
        char character = tolower(string[i]);
        int isVowel = 0;
        for (int j = 0; j < 5; j++) {
            if (character == vowels[j]) {
                isVowel = 1;
                break;
            }
        }
        if (!isVowel) {
            return 0; 
        }
    }
    return 1; 
}


int isOnlyConsonants(char* string) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; string[i] != '\0'; i++) {
        char character = tolower(string[i]);
        if (character < 'a' || character > 'z') {
            return 0; 
        }
        for (int j = 0; j < 5; j++) {
            if (character == vowels[j]) {
                return 0; 
            }
        }
    }
    return 1; 
}


int isInteger(char* string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] < '0' || string[i] > '9') {
            return 0; 
        }
    }
    return 1; 
}


int isFloat(char* string) {
    int hasFraction = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] < '0' || string[i] > '9') {
            if (!hasFraction && (string[i] == '.' || string[i] == ',')) {
                hasFraction = 1;
            } else {
                return 0; 
            }
        }
    }
    return 1; 
}


int isEOF(char* line) {
    return strcmp(line, "FIM") == 0;
}

int main() {
    char input[1000]; 

    while (fgets(input, sizeof(input), stdin) != NULL) {
        
        input[strcspn(input, "\n")] = '\0';

        if (isEOF(input)) {
            break;
        }

        printf("%s %s %s %s\n",
            isOnlyVowels(input) ? "SIM" : "NAO",
            isOnlyConsonants(input) ? "SIM" : "NAO",
            isInteger(input) ? "SIM" : "NAO",
            isFloat(input) ? "SIM" : "NAO"
        );
    }

    return 0;
}