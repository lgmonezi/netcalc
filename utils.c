#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

static void exitWithOutOfMemory() {
    fprintf(stderr, "Error: OutOfMemory\n");
    exit(EXIT_FAILURE);
}

void *mallocOrExitOnError(size_t size) {
    void *ptr = malloc(size);
    if(!ptr) {
        exitWithOutOfMemory();
    }
    return ptr;
}

void *callocOrExitOnError(size_t nmemb, size_t size) {
    void *ptr = calloc(nmemb, size);
    if(!ptr) {
        exitWithOutOfMemory();
    }
    return ptr;
}

void *reallocarrayOrExitOnError(void *ptr, size_t nmemb, size_t size) {
    ptr = reallocarray(ptr, nmemb, size);
    if(!ptr) {
        exitWithOutOfMemory();
    }
    return ptr;
}

