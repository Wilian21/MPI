#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

/*
WILIAN TAPIA

*/
int main(void) {

    MPI_Init(NULL,NULL);
    int id,tam;
    int a=5,b=3;


    MPI_Comm_rank(MPI_COMM_WORLD,&id);
    MPI_Comm_size(MPI_COMM_WORLD, &tam);

    if (tam< 2) {
        printf("El tamaño mundial debe ser mayor que %d\n", tam);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int num1,num2;
    if(id == 0){
           //Para multiplicacion
           MPI_Send(&a,1,MPI_INT,1,0,MPI_COMM_WORLD);
           MPI_Send(&b,1,MPI_INT,1,0,MPI_COMM_WORLD);
           //Para potenciacion
           MPI_Send(&a,1,MPI_INT,2,0,MPI_COMM_WORLD);
           MPI_Send(&b,1,MPI_INT,2,0,MPI_COMM_WORLD);
           //Para division y resto
           MPI_Send(&a,1,MPI_INT,3,0,MPI_COMM_WORLD);
           MPI_Send(&b,1,MPI_INT,3,0,MPI_COMM_WORLD);
    }
    if(id == 1){
        printf("El proceso %d recibio los numeros del proceso 0 \n",id);
        MPI_Recv(&num1,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        MPI_Recv(&num2,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
         int mul=0;
          printf("----------Con sumas Sucesivas----------\n");
          for(int i=0; i<num2;i++){
             mul+=num1;
             printf("%d ",mul);
          }
          printf("\nEl resultado de la multiplicacion es %d * %d =%d\n",num1,num2,mul);
    }
    if(id==2){
       printf("El proceso %d recibio los numeros del proceso 0 \n",id);
        MPI_Recv(&num1,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        MPI_Recv(&num2,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
       int pot=1;
       printf("------------Con multiplicaciones Sucesivas----------\n");
      for(int i=0;i<num2;i++){
         pot*=num1;
         printf("%d ",pot);
      }
     printf("\nEl resultado de la potenciacion es %d ^ %d =%d\n",num1,num2,pot);
    }
    if(id==3){
      printf("El proceso %d recibio los numeros del proceso 0 \n",id);
        MPI_Recv(&num1,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        MPI_Recv(&num2,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      int div=0,resto=num1;
      printf("----------Con restas Sucesivas----------\n");
      while(resto>=num2){
        resto-=num2;
        div++;
        printf("%d ",div);
      }
       printf("\nEl resultado de la division es %d / %d =%d\n",num1,num2,div);
       printf("El resto de la division es: %d\n",resto);
    }

    MPI_Finalize();
}
