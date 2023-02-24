#ifndef NETCALC_KILO_OUTPUT_H
#define NETCALC_KILO_OUTPUT_H

#include <stdbool.h>

void editorDrawRows();
void editorRefreshScreen();

bool output_write(char *s);

#endif //NETCALC_KILO_OUTPUT_H