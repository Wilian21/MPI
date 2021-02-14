#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int rank,size,num,num2,inv=0;
    int n =5 ,v[]={0,0,0,0,0};
    char str[5];
    MPI_Init(NULL,NULL);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if (size>=6)
    {
        if (rank==0)
        {
            for (int i = 0; i < n; i++)
            {
                while (1)
                {
                    num=rand () %  180000 + -90000;
                    if (num>10000|| num<-10000)
                    {
                        break;
                    }
                }
                v[i]=num;
            }
            printf("hilo 0 vector: ");
            for (int  i = 0; i < n; i++)
            {
                printf("%i ",v[i]);
            }
            printf("\n");

        }
        MPI_Bcast(&v,n, MPI_INT, 0, MPI_COMM_WORLD);
        if (rank!=0)
        {
            num2=v[rank-1];
            while (num2 != 0)
            {
                inv = inv * 10;
                inv = inv + num2%10;
                num2 = num2/10;
            }
            printf("hilo:%i\tnum:%i\tinverso:%i\n",rank,v[rank-1],inv);
        }
    }else{
        printf("Se necesitan minimo 6 hilos\n");
        MPI_Abort(MPI_COMM_WORLD,1);
    }


    MPI_Finalize();


    return 0;
}
