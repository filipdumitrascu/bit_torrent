#include "../headers/utils.h"
#include "../headers/peer.h"

void *download_thread_func(void *arg)
{
    int rank = *(int *)arg;

    return NULL;
}

void *upload_thread_func(void *arg)
{
    int rank = *(int *)arg;

    return NULL;
}

void peer(int numtasks, int rank)
{
    pthread_t download_thread;
    pthread_t upload_thread;
    void *status;

    int r = pthread_create(&download_thread, NULL, download_thread_func, (void *)&rank);
    DIE(r, "Eroare la crearea thread-ului de download\n");

    r = pthread_create(&upload_thread, NULL, upload_thread_func, (void *)&rank);
    DIE(r, "Eroare la crearea thread-ului de upload\n");

    r = pthread_join(download_thread, &status);
    DIE(r, "Eroare la asteptarea thread-ului de download\n");

    r = pthread_join(upload_thread, &status);
    DIE(r, "Eroare la asteptarea thread-ului de upload\n");
}