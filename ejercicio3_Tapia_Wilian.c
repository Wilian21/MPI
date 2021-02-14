#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

/*
WILIAN TAPIA

*/
int main(void) {

    MPI_Init(NULL,NULL);
    int n=5,i,j;
    int id,tam;

    MPI_Comm_rank(MPI_COMM_WORLD,&id);
    MPI_Comm_size(MPI_COMM_WORLD, &tam);

    if (tam< 2) {
        printf("El tamaño mundial debe ser mayor que %d\n", tam);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    int num;
    if(id == 0){
        //printf("Ingrese un numero:");
        //scanf("%d",&n);
        MPI_Send(&n,1,MPI_INT,1,0,MPI_COMM_WORLD);
        MPI_Send(&n,1,MPI_INT,2,0,MPI_COMM_WORLD);
        //printf("El proceso %d\n",id)
    }
    if(id == 1){
        MPI_Recv(&num,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        if(num>=1 && num<=20){
        printf(" ");
        }else{
        printf("numero invalido\n");
        exit(-1);
      }
    }
    if(id == 2){
        MPI_Recv(&num,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        int m[num][num];
        for(i=1;i<=num;i++){
           for(j=1;j<=num;j++){
              if(i==j)
                printf("-\t");
              else if(i>j)
                 printf("*\t");
              else
                 printf("+\t");
           }
          printf("\n");
       }
      }
      MPI_Finalize();
    }

