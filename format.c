#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>
#include "format.h"

static bool isDigit(char character) {
    return character >= '0' && character <= '9';
}

static void appendChar(int *index, char *str, char character) {
    str[*index] = character;
    *index++;
}

void formatCurrency(double value, char *dest) {
    int index = 0;
    char strval[30];
    sprintf(strval, "%0.2f", value);
    short currentDecimal = 0;
    for(int i = 0; i < strlen(strval); i++) {
        char current = strval[i];
        if(isDigit(current)) {
            if(currentDecimal == 3) {
                appendChar(&index, dest, '.');
                currentDecimal = 0;
            }
            appendChar(&index, dest, current);
            currentDecimal++;
        }


    }

}