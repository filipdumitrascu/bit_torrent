#include "headers/utils.h"
#include "headers/peer.h"
#include "headers/tracker.h"

int main(int argc, char *argv[])
{
    int provided;
    MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
    DIE(provided < MPI_THREAD_MULTIPLE, "MPI doesn't support multi-threading\n");

    int numtasks, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == TRACKER_RANK) {
        tracker(numtasks, rank);
    
    } else {
        peer(numtasks, rank);
    }

    MPI_Finalize();
}
