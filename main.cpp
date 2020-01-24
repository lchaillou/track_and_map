# include <iostream>
# include <cstdlib>
# include <string>
# include <chrono>
# include <cmath>
# include <vector>
# include <fstream>
#include <mpi.h>

int main(int argc, char *argv[] ){
    MPI_Init(&argc, &argv);
    int size, rank;
    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    std::cout<<rank<<std::endl;
    MPI_Finalize();
    return 0;
}