#include <stdio.h>
#include <mpi.h>

#define m 5
/*
WILIAN TAPIA
ejercicio 5
*/
int main(void) {

    int rank,size;
    float pesos[m]={20.0,100.0,40.0,50.00,10.00};
    int edades[m]={12,15,10,35,60};
    //ninos
    int ninos;
    float sum_ni=0,p_ni=0;
    //jovenes
    int jovenes;
    float  sum_jov=0,p_jo=0;
    //adultos
    int adultos;
    float  sum_adu=0,p_adu=0;
    //viejos
    int viejos;
    float  sum_vie=0,p_vie=0;

    int i;

    MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
 /*
    for(rank == 0){
        printf("EDADES\n");
       for(i=0;i<m;i++){
          edades[i]=rand()%99;
          printf(" %d ",edades[i]);
       }

       printf("PESOS\n");
       for(i=0;i<m;i++){
          pesos[i]=rand()%99;
          printf(" %d ",pesos[i]);
       }
        }
    }
*/

    MPI_Bcast(&edades, m, MPI_INT, 0 , MPI_COMM_WORLD);
    MPI_Bcast(&pesos, m, MPI_INT, 0 , MPI_COMM_WORLD);

   if(rank==1){
        printf("CATEGORIA Edad\tPromedio Peso\t Promedio Edad\n");
        for(i=0;i<m;i++){

           if(edades[i] <=12){
               ninos++;
               sum_ni+=edades[i];
               //sum_ni/=ninos;
               p_ni+=pesos[i];
               //p_ni/=ninos;
            }
    }
    printf("0-12\t\t %f\t %f\n",p_ni,sum_ni);
   }

    if(rank==2){
       for(i=0;i<m;i++){
            if(edades[i]>=13 && edades[i]<=29){
                    jovenes++;
                    sum_jov+=edades[i];
                    //sum_jov/=jovenes;
                    p_jo+=pesos[i];
                    //p_jo/=jovenes;
                }
       }
       printf("13-29\t\t %f\t %f\n",p_jo,sum_jov);
    }

    if(rank ==3){
       for(i=0;i<m;i++){
            if(edades[i]>=30 && edades[i]<=59){
                    adultos++;
                    sum_adu+=edades[i];
                    //sum_adu/=adultos;
                    p_adu+=pesos[i];
                    //p_adu/=adultos;
            }
        }
        printf("30-59\t\t %f\t %f\n",p_adu,sum_adu);
   }

   if(rank==4){
        for(i=0;i<m;i++){
            if(edades[i]>=60){
                viejos++;
                sum_vie+=edades[i];
                //sum_vie/=viejos;
                p_vie+=pesos[i];
                //p_vie/=viejos;
            }
        }
       printf("60-adelante\t %f\t %f\n",p_vie,sum_vie);
    }


    MPI_Finalize();
}
