#ifndef UTILS_H_
#define UTILS_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define TRACKER_RANK 0
#define MAX_FILES 10
#define MAX_FILENAME 15
#define HASH_SIZE 32
#define MAX_CHUNKS 100

#define DIE(assertion, call_description, ...)                  \
    do {                                                       \
        if (assertion) {                                       \
            fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__); \
            fprintf(stderr, call_description, ##__VA_ARGS__);  \
            perror("");                                        \
            exit(errno);                                       \
        }                                                      \
    } while (0)

#endif /* UTILS_H_ */
