#ifndef NETCALC_UTILS_H
#define NETCALC_UTILS_H

void *mallocOrExitOnError(size_t size);

void *callocOrExitOnError(size_t nmemb, size_t size);

void *reallocarrayOrExitOnError(void *ptr, size_t nmemb, size_t size);

#endif //NETCALC_UTILS_H

