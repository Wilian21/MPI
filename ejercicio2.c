#include <math.h>
#include <stdio.h>
#include <mpi.h>
int main()
{

    int i, n=2;//iNICIALIZACION DE VARIABLES

//iNICIALIZACION DE MPI
    MPI_Init(NULL,NULL);
    //iNICIALIZACION DE LAS VARIABLES A UTILIZAR EN MPI
    int rank,size;
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

//vARIABLE QUE UTILIZAREMOS EN LA RECEPCION
    int m;

    //UTILIZAREMOS SOLO 2 PROCESOS EL PROCESO 0 QUE SERA EL ENVIO DE NUESTRO DATO
    //PROCESO 1 QUE SERA LA RECEPCION DE NUESTRO DATO Y PROCESARLO A LA RESPUESTA
    if (size < 2) {
        printf("El tamaño mundial debe ser mayor que %d\n", size);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

//pROCESO 0 DONDE TENDREMOS EL ENVIO DEL MENSAJE DE LA VARIABLE N
    if(rank==0){
            //SENTENCIA DEL ENVIO DE LA VARIABLE N AL PROCESO 1 DEL PROCESO 0
            MPI_Send(&n,1,MPI_INT,1,0,MPI_COMM_WORLD);
            printf("Hilo 0");

    }
    if(rank == 1){
        //SENTENCIA DE RECEPCION CON LA VARIABLE M DONDE RECIBE DEL PROCESO 0
        MPI_Recv(&m,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        //VARIABLES PARA EL PROCESO DE LA SERIE
        double  total = 1.0;
        //RECORRER M
        for (i = 1; i <=m; i++){
             total = total + (pow(m, i));//SERIE DONDE M YA TIENE SU VALOR INICIALIZADO
        }
        //IMPRESION DEL PROCESO Y DEL RESULTADO DE LA SERIE
        printf("%Proceso %d: %.2f\n",rank,total);

    }
    //FIN DEL MPI
    MPI_Finalize();
}

