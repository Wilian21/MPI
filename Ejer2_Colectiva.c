#include <mpi.h>
#include <math.h>
#include <stdio.h>
#define n 3
int main(int argc, char* argv[])
{

    int Vsend[n]={3};
    int drecv;
    int myid, size, i;
    int total=0;
    long resp;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    /*if (myid == 0) {
        for (i = 0; i < n; i++)
            Vsend[i] = i;
            //printf("%d",Vsend[i]);
    }*/

    printf("\n \n");
    MPI_Scatter(&Vsend, 1, MPI_INT, &drecv, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("\n##### proceso = %d: dato recibido = %d", myid, drecv);
   // if(myid==2){
        printf("\n rank: %d y valor %d\n",myid,drecv);
        //int resp;
        for(int i=1;i<=drecv;i++){
            resp=0;
            long r;
            //printf("\n %d",i);
            int acum=1;
            while(i>=acum){//se eleva el valor al factorial tantas veces el numero real sea
                int facto=1;
                //printf("\n  valor i: %d acum: %d \n",i,acum);
                for(int j=1;j<=acum;j++){//obtener el valor del factorial
                    facto=facto*j;
                }
                printf(" ( %d^%d )+ \t ",drecv,facto);
                r=pow(drecv,facto); //elevar el factorial al valor real
                resp=r+resp;
                //printf("\n R -------------%d",r);
                acum=acum+1; //acumulador salir del while cuando ya se repita el numero tantas veces es.
            }
           // printf("\n \n ####RESPUESTA: \t %d",resp);
            printf("\n ---");

        }
        total=resp+total;


    //}

MPI_Finalize();

        printf("\n ____________________________RESPUESTA :\t \t %d",total);
return 0;
}
