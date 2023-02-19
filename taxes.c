#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "taxes.h"
#include "utils.h"

IncomeValues *loadIncomes(int argc, char const *argv[]) {
    IncomeValues *incomes = mallocOrExitOnError(sizeof(IncomeValues));
    int cap = 5;
    incomes->count = 0;
    incomes->values = callocOrExitOnError(cap, sizeof(Income));
    for(int i = 1; i < argc; i++) {
        double value = strtod(argv[i], NULL);
        if(value > 0) {
            if(incomes->count == cap) {
                cap *= 2;
                incomes->values = reallocarrayOrExitOnError(incomes->values, cap, sizeof(Income));
            }
            Income *income = mallocOrExitOnError(sizeof(Income));
            income->gross = value;
            income->net = calcNet(income->gross);
            income->taxes = income->gross - income->net;
            incomes->values[incomes->count++] = *income;
        } else {
            fprintf(stderr, "Warning: %s is not a valid income.\n", argv[i]);
        }
    }
    if(!incomes->count) {
        free(incomes);
        return NULL;
    }
    return incomes;
}

void freeIncomes(IncomeValues *incomes) {
    free(incomes->values);
    free(incomes);
}

double calcNet(double gross) {
    double taxFree = gross * 0.27;
    double taxes = ((gross-taxFree) * 0.26) + ((gross-taxFree) * 0.05);
    return gross - taxes;
}