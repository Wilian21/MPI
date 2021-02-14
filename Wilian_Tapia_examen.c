#include <stdio.h>
#include <mpi.h>

#define n 2
#define m 3
/*
WILIAN TAPIA
ejercicio 24
*/
int main(void) {

    int rank,size;
    int a[n][m]={{1,1,1},{4,5,1}};
    int b[n][m]={{1,0,1},{3,2,1}};

    int c[m]={0,0,0};
    int matC[n][m]={{0,0,0},{0,0,0}};
    int send[m];
    int i,j;
/*
    if(n>20 || m>30){
        printf("No se permite esos valores\n");
        //exit(-1);
    }else{
        printf("\n");
    }
*/
    MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    MPI_Bcast(&a, n*m, MPI_INT, 0 , MPI_COMM_WORLD);
    //MPI_Bcast(&b, n, MPI_INT, 0 , MPI_COMM_WORLD);

    MPI_Scatter(&b,m, MPI_INT, &send, m, MPI_INT, 0, MPI_COMM_WORLD); //Filas

    printf("Suma de matrices en el proceso %d\n",rank);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            c[j] = send[j] + a[j][i];
    }

    MPI_Gather(&c,m,MPI_INT,&matC,m,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);

    if(rank==0){
        printf("Resultante \n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
                  printf("[%d]",matC[i][j]);
            printf("\n");
       }
    }

    MPI_Finalize();
}

