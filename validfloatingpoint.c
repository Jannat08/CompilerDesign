#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isValidFloatingPoint(const char* lexeme) {
    int len = strlen(lexeme);
    int dotCount = 0;
    int eCount = 0;
    int i = 0;

    // Check for an optional sign (+ or -) at the beginning
    if (lexeme[i] == '+' || lexeme[i] == '-')
        i++;

    // Process digits before the decimal point
    while (i < len && isdigit(lexeme[i]))
        i++;

    // Check for a decimal point
    if (i < len && lexeme[i] == '.') {
        i++;
        dotCount++;
    }

    // Process digits after the decimal point
    while (i < len && isdigit(lexeme[i]))
        i++;

    // Check for the exponent part (e or E)
    if (i < len && (lexeme[i] == 'e' || lexeme[i] == 'E')) {
        i++;
        eCount++;

        // Check for an optional sign in the exponent
        if (lexeme[i] == '+' || lexeme[i] == '-')
            i++;

        // Process digits in the exponent
        while (i < len && isdigit(lexeme[i]))
            i++;
    }

    // If the entire string is processed and we encountered at most one dot and one 'e' or 'E',
    // then it's a valid floating-point number.
    return i == len && dotCount <= 1 && eCount <= 1;
}

int main() {
    char lexeme[100];
    printf("Enter a lexeme: ");
    scanf("%s", lexeme);

    if (isValidFloatingPoint(lexeme)) {
        printf("Valid Floating-Point Number\n");
    } else {
        printf("Invalid Floating-Point Number\n");
    }

    return 0;
}
