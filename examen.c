#include <stdio.h>
#include <mpi.h>
#include <string.h>
#include <stdlib.h>
// Wilian Tapia

/*
Escriba un solo program que lea una matriz nxm y desarolle instrucciones
que sucesivamente permitan determinar:

a)La suma de los elementos con valor impar de cada columna
b)El valor promedio de los elementos de cada fila
c)El mayor valor y su posicion en cada fila de la matriz
d)La cantidad de elementos en cada fila que son mayores al promedio
de la fila.
e)El producto de los elementos de la diagonal
f)Sustituya cada elemento impar de la matriz con un num. aleatorio
de una cifra.
g)La sum de los elementos de la matriz que no pertenecen a la triangular
superior

*/

#define n 3
#define m 3
int main(){
    int b[n][m]={{3,21,50},{3,10,2},{1,4,5}};
    int i, j;
    int v[n],h[m];
    int suma=0, max=-999,total=0,rank, size;

    MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if(rank == 0){
        printf("HILO 0\n");
        printf("MATRIZ GENERADA DE 3*3\n");
        for(i=0; i<n; i++){
            for(j=0; j<m; j++)
            printf("[%d]",b[i][j]);
            printf("\n");
         }
    }

    MPI_Bcast(&b,n*m, MPI_INT, 0 , MPI_COMM_WORLD);
   // MPI_Barrier(MPI_COMM_WORLD);

    switch (rank)
        {
        case 1:
            for(j=0; j<m; j++){
                 suma=0;
               for(i=0; i<n; i++){
                   if(b[i][j]%2==0){
                   }else{
                       suma+=b[i][j];
                 }}
            h[j]=suma;
            printf("Promedio de la columna %d: %d\n",j,h[j]);
         }
         printf(" hilo %d",rank);
         break;
        case 2:
            for(i=0; i<n; i++){
                suma=0;
                for(j=0; j<m; j++){
                    suma+=b[i][j];
                }
                v[i]=suma;
            }
            for(int k=0; k<n; k++){
                printf("Promedio de la fila %d :%d\n",k,v[k]);
            }
          printf(" hilo %d",rank);
          break;
        case 3:
            for(i=0; i<n; i++){
                 suma=0;
                 for(j=0; j<m; j++){
                    suma+=b[i][j];
                }
                v[i]=suma;
                if(b[i][j]>v[i]){
                    total++;
                }
             }
                for(int k=0; k<n; k++){

                printf("Elementos mayores al promedio de la fila %d: %d\n",k,total);
             }
          printf(" hilo %d",rank);
          break;

        case 4:
            for(i=0; i<n;i++){
                for(j=0; j<m; j++){
                    if(i == j)
                    printf("Diagonal: %d     \n",b[i][j]);
                }
              }
            printf(" hilo %d",rank);
          break;
        case 5:
          for(i=0; i<n;i++){
              suma=0;
              for(j=0;j<m;j++){
                  if(i>j){
                  }else{
                    suma+=b[i][j];
                 }
                }
             printf("Valores del que no son triangulo superior: %d\n",suma);
            }
          printf(" hilo %d",rank);
          break;

        case 6:
            for(j=0; j<m; j++){
                for(i=0; i<n; i++){
                    //temp=rand()%9;
                    if(b[i][j]%2==0){
                    }else{
                      b[i][j]=rand()%9;
                    }
                }
            }
             printf("MATRIZ GENERADA DE 3*3 LOS NUMEROS IMPARES ALEATORIOS\n");
             for(i=0; i<n; i++){
                for(j=0; j<m; j++)
                printf("[%d]",b[i][j]);
                printf("\n");
             }
          printf(" hilo %d",rank);
          break;
}
  MPI_Finalize();
}

