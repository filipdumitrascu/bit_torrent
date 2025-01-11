#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <string>
#include <vector>
#include <mpi.h>

#define DIE(assertion, call_description, ...)                   \
    do {                                                        \
        if (assertion) {                                        \
            std::cerr << "(" << __FILE__ << ", " << __LINE__    \
                      << "): " << call_description;             \
            if (errno) {                                        \
                std::cerr << ": " << std::strerror(errno);      \
            }                                                   \
            std::cerr << "\n";                                  \
            std::exit(errno);                                   \
        }                                                       \
    } while (0)

#define HASH_SIZE 32
#define MAX_FILENAME 15

#define MAX_FILES 10
#define MAX_CHUNKS 100

#define FIN '0'
#define ACK '1'

#define TRACKER_RANK 0

enum peertype {
    SEED,
    PEER,
    LEECHER
};

struct hashes {
    int hashesNo;
    std::vector<std::string> hashesCurr;        
};

struct hashrange {
    union {
        int start;  // Start index of the hash interval
        int first;  // Alias for start
    };
    union {
        int end;    // End index of the hash interval
        int last;   // Alias for end
    };
};

struct client {
    int id;             // Client ID
    peertype type;      // Type of client
    hashrange interval; // Interval index for segments owned
};

struct trackedfile {
    int segmentsNo;                    // Number of segments
    std::vector<char*> segments;       // All hashes needed
    std::vector<client> providers;     // Data hashes and client details
};


#endif /* UTILS_H_ */
