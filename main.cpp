#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <cmath>
#include <vector>
#include <fstream>
#include <mpi.h>

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    int size, rank;
    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0)
    {
        int nb_taches = 100;
        int condition = 1;
        while (nb_taches != 0)
        {
            int num_proc;
            
            nb_taches--;
        }
        condition = 0;

        for (size_t i = 0; i < size; i++)
        {
            MPI_Recv(&num_proc, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            MPI_Send(&condition, 1, MPI_INT, num_proc, MPI_ANY_TAG, MPI_COMM_WORLD);
        }
        
    }

    if (rank != 0)
    {
        int condition = 0;
        while (condition != 1)
        {
            std::cout << "je suis le processeur " << rank << " et je ne sais pas quoi faire" << std::endl;
            MPI_Send(&rank, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD);
            MPI_Recv(&condition, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        }
    }

    std::cout << rank << std::endl;
    MPI_Finalize();
    return 0;
}