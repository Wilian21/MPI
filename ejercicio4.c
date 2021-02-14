#include <stdio.h>
#include <mpi.h>


int main(void) {
//m filas
//n columnas
int m=3,n=3;
    int a[3][3]={{5,4,3},{10,1,9},{11,8,5}};
    int a_recv[3][3];
    int a_recv2[3][3];
    int i,j,rank, size;

    MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    MPI_Gather(&a, m*n, MPI_INT, &a_recv,n*m, MPI_INT, 0, MPI_COMM_WORLD);
    //MPI_Bcast(&a, m*m , MPI_INT, 0, MPI_COMM_WORLD);


        for(i=0; i<m; i++){
            for(j=0;j<m;j++){
                a_recv2[j][i]=a_recv[i][j];
                //printf("[%d] ",a[i][rank]);
                }
           }
       MPI_Barrier(MPI_COMM_WORLD);


         if(rank ==0){

                for(i=0;i<m;i++)
               {
                   for(j=0;j<m;j++){
                    printf("[%d] ",a[i][j]);
                   }
                    printf("\n");
               }

 printf("\n");
  printf("\n");
   printf("\n");


     for(i=0;i<m;i++)

               {
                   for(j=0;j<m;j++){
                    printf("[%d] ",a_recv2[i][j]);
                   }
                    printf("\n");
               }
   printf("Hola\n");



           }




    MPI_Finalize();

}

    //MPI_Bcast(&a, m*n, MPI_INT, 0 , MPI_COMM_WORLD);
    /*
    for(i=0;i<rank;i++){
        for(j=0;j<rank;j++)
            matriz[i]= a_recv[j];
            printf("%d ",matriz[i]);
            printf("\n");
    }
    */
   // MPI_Gather(&m1,m,MPI_INT,&m1,m,MPI_INT,0,MPI_COMM_WORLD);
/*
        printf("MATRIZ TRANSPUESTA\n");
        printf("hilo %d\n",rank);
         for(i=0;i<m;i++){
            for(j=0;j<n;j++)
                printf("[%d]",a[j][i]);
                printf("\n");
         }
*/
/*
     printf("MATRIZ GENERADA DE 3*3\n");
     for(i=0; i<m; i++){
        for(j=0; j<n; j++)
        printf("[%d]",a[i][j]);
        printf("\n");
     }
*/




