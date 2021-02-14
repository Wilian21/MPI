#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

/*
WILIAN TAPIA

*/
int main(void) {

    MPI_Init(NULL,NULL);
    int id,tam;
    int n=5,i,j;
    int a[n];


    MPI_Comm_rank(MPI_COMM_WORLD,&id);
    MPI_Comm_size(MPI_COMM_WORLD, &tam);

    if (tam< 5) {
        printf("El tamaño mundial debe ser mayor que %d\n", tam);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int m[n];
    if(id == 0){
        for(i=0; i<n; i++){
           a[i]=rand()%99;
           MPI_Send(&a[i],1,MPI_INT,1,0,MPI_COMM_WORLD);
           MPI_Send(&a[i],1,MPI_INT,2,0,MPI_COMM_WORLD);
           MPI_Send(&a[i],1,MPI_INT,3,0,MPI_COMM_WORLD);
           MPI_Send(&a[i],1,MPI_INT,4,0,MPI_COMM_WORLD);
           printf("%d.- %d\n",i+1,a[i]);
        }
    }
    if(id == 1){
        printf("El proceso %d recibio los numeros del proceso 0 \n",id);
        //Edad media
        int suma=0,s;
        for(i=0;i<n;i++){
            MPI_Recv(&m[i],1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
          suma += m[i];
          //printf("La media es:%d\n",suma);
          s= suma/n;
        }
        printf("La media es:%d\n",s);
    }
    if(id==2){
        printf("El proceso %d recibio los numeros del proceso 0 \n",id);
         //Edad maxima y edad minima
          int mayor=0, menor=99;
          for(i=0;i<n;i++){
             MPI_Recv(&m[i],1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            if(m[i]>mayor){
              mayor=m[i];
            }if(m[i]<menor){
               menor=m[i];
            }
          }
          printf("La edad maxima es: %d\n",mayor);
          printf("La edad menor es: %d\n",menor);
          menor=99;
    }
    if(id==3){
        printf("El proceso %d recibio los numeros del proceso 0 \n",id);
        //Num personas jubiladas
          int jub=0;
          for(i=0; i<n;i++){
            MPI_Recv(&m[i],1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            if(m[i]>=60)
              jub++;
          }

          printf("Personas Jubiladas: %d\n",jub);
    }
    if(id==4){
        printf("El proceso %d recibio los numeros del proceso 0 \n",id);
        //Menores de edad
          int m_ed=0;
          for(i=0; i<n; i++){
             MPI_Recv(&m[i],1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            if(m[i]<18)
              m_ed++;
          }
          printf("Menores de edad: %d\n",m_ed);
    }


    MPI_Finalize();

}
