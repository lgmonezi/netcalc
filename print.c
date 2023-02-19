#include <stdio.h>
#include <string.h>
#include "print.h"

static int findDoubleStrLen(double value) {
    char strval[30];
    sprintf(strval, "%0.2f", value);
    return (int) strlen(strval);
}

static void getHeaderFormat(int max, char buff[]) {
    sprintf(buff, "%%%ds   %%%ds   %%%ds\n", max, max, max);
}

static void getLineFormat(int max, char buff[]) {
    sprintf(buff, "%%%d.2f   %%%d.2f   %%%d.2f\n", max, max, max);
}

static void printSeparator(int size, int times) {
    for(int i = 0; i < times; i++) {
        if(i != 0) {
            printf("   ");
        }
        for(int j = 0; j < size; j++) {
            printf("=");
        }
    }
    putchar('\n');
}

void printIncomes(IncomeValues *incomes) {
    if(!incomes) {
        return;
    }
    Income total = {0};
    for(int i = 0; i < incomes->count; i++) {
        Income income = incomes->values[i];
        total.gross += income.gross;
        total.net += income.net;
        total.taxes += income.taxes;
    }
    char headerFormat[50];
    char lineFormat[50];
    int maxlength = findDoubleStrLen(total.gross);
    getHeaderFormat(maxlength, headerFormat);
    getLineFormat(maxlength, lineFormat);
    printf(headerFormat, "Gross", "Net", "Taxes");
    printSeparator(maxlength, 3);
    for(int i = 0; i < incomes->count; i++) {
        double gross = incomes->values[i].gross;
        double net = incomes->values[i].net;
        double tax = incomes->values[i].taxes;
        printf(lineFormat, gross, net, tax);
    }
    printSeparator(maxlength, 3);
    puts("\nTOTAL:");
    printf(lineFormat, total.gross, total.net, total.taxes);
}