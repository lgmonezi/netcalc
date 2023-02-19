#ifndef NETCALC_TAXES_H
#define NETCALC_TAXES_H

typedef struct {
    double gross;
    double net;
    double taxes;
} Income;

typedef struct {
    int count;
    Income *values;
} IncomeValues;

IncomeValues *loadIncomes(int argc, char const *argv[]);

void freeIncomes(IncomeValues*);

double calcNet(double gross);

#endif //NETCALC_TAXES_H
