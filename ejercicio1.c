#include <mpi.h>
#include <stdio.h>
int main(int argc, char *argv[])

{

  int n, myid, numprocs,x, pi;

  MPI_Init(&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);

  printf("\nProceso %d de %d", myid, numprocs);

  if (myid==0)

        n=2;

      MPI_Scatter(&n, 1, MPI_INT,0 , MPI_COMM_WORLD);

      MPI_Reduce (&n, &pi, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);

      if (myid==0)

              printf("\n Respuestas %d", pi);

    MPI_Finalize();

return 0;

}
