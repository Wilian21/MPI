#include <stdio.h>
#include <mpi.h>

int main(void) {

    /***START MPI DECLARATION***/
    MPI_Init(NULL,NULL);
    int proceso;

    MPI_Comm_rank(MPI_COMM_WORLD,&proceso);
    int tam;
    MPI_Comm_size(MPI_COMM_WORLD, &tam);

    //FINISH DECLARATION//
    int n=5;
    int n_env;
    int a_recv,b_recv;
    int contador=0;

    if(proceso==0){
        for(int p=1;p<tam;p++){
            MPI_Send(&contador,1,MPI_INT,p,0,MPI_COMM_WORLD);
            MPI_Send(&n,1,MPI_INT,p,0,MPI_COMM_WORLD);
            n--;
            contador++;
            printf("El proceso 0 enviando datos al proceso %d\n",p);
        }
    }else if(proceso > 0){
        MPI_Recv(&a_recv,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        MPI_Recv(&b_recv,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("%Proceso %d: %d y %d\n",proceso,a_recv,b_recv);

    }
    MPI_Finalize();
}
