#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <cmath>
#include <unistd.h>
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
        int num_proc;
        while (nb_taches != 0)
        {

            MPI_Recv(&num_proc, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
            MPI_Send(&condition, 1, MPI_INT, num_proc, 0, MPI_COMM_WORLD);
            nb_taches--;
        }
        condition = 0;

            for (size_t i = 1; i < size; i++)
        {
            MPI_Recv(&num_proc, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
            MPI_Send(&condition, 1, MPI_INT, num_proc, 0, MPI_COMM_WORLD);
        }
        for (size_t i = 1; i < size; i++)
        {
            MPI_Recv(&num_proc, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
        }
        std::cout<<"fin"<<std::endl;
    }

    if (rank != 0)
    {
        int condition = 1;
        while (condition != 0)
        {
            std::cout << "je suis le processeur " << rank << " et je ne sais pas quoi faire" << std::endl;
            MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
            MPI_Recv(&condition, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        }
        std::cout<<"le processus "<<rank<<" a terminé"<<std::endl;

    }

    std::cout << rank << std::endl;
    MPI_Finalize();
    return 0;
}