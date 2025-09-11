#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isOnlyVowelsRec(char* string, int i) {
    if (string[i] == '\0') {
        return 1;
    }
    
    char character = tolower(string[i]);
    int isVowel = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for (int j = 0; j < 5; j++) {
        if (character == vowels[j]) {
            isVowel = 1;
            break;
        }
    }

    if (!isVowel) {
        return 0;
    }
    
    return isOnlyVowelsRec(string, i + 1);
}

int isOnlyVowels(char* string) {
    return isOnlyVowelsRec(string, 0);
}

int isOnlyConsonantsRec(char* string, int i) {
    if (string[i] == '\0') {
        return 1;
    }

    char character = tolower(string[i]);
    if (character < 'a' || character > 'z') {
        return 0;
    }

    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for (int j = 0; j < 5; j++) {
        if (character == vowels[j]) {
            return 0;
        }
    }
    
    return isOnlyConsonantsRec(string, i + 1);
}

int isOnlyConsonants(char* string) {
    return isOnlyConsonantsRec(string, 0);
}

int isIntegerRec(char* string, int i) {
    if (string[i] == '\0') {
        return 1;
    }
    
    if (string[i] < '0' || string[i] > '9') {
        return 0;
    }
    
    return isIntegerRec(string, i + 1);
}

int isInteger(char* string) {
    return isIntegerRec(string, 0);
}

int isFloatRec(char* string, int i, int hasFraction) {
    if (string[i] == '\0') {
        return 1;
    }

    if (string[i] < '0' || string[i] > '9') {
        if (!hasFraction && (string[i] == '.' || string[i] == ',')) {
            return isFloatRec(string, i + 1, 1);
        } else {
            return 0;
        }
    } else {
        return isFloatRec(string, i + 1, hasFraction);
    }
}

int isFloat(char* string) {
    return isFloatRec(string, 0, 0);
}

int isEOF(char* line) {
    return strcmp(line, "FIM") == 0;
}

void solve() {
    char input[1000];
    
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return;
    }
    
    input[strcspn(input, "\n")] = '\0';

    if (isEOF(input)) {
        return;
    }

    printf("%s %s %s %s\n",
           isOnlyVowels(input) ? "SIM" : "NAO",
           isOnlyConsonants(input) ? "SIM" : "NAO",
           isInteger(input) ? "SIM" : "NAO",
           isFloat(input) ? "SIM" : "NAO"
    );
    
    solve();
}

int main() {
    solve();
    return 0;
}