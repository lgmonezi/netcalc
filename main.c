#include <stdio.h>
#include <stdlib.h>
#include "print.h"
#include "taxes.h"

int main(int argc, const char *argv[]) {
    IncomeValues *incomes = loadIncomes(argc, argv);
    if(!incomes->count) {
        fprintf(stderr, "Error: No valid incomes were provided in the arguments\n");
        exit(EXIT_FAILURE);
    }
    printIncomes(incomes);
    freeIncomes(incomes);
    return EXIT_SUCCESS;
}

