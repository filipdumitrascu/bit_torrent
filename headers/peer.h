#ifndef PEER_H
#define PEER_H

void *download_thread_func(void *arg);

void *upload_thread_func(void *arg);

void peer(int numtasks, int rank);

#endif /* PEER_H */