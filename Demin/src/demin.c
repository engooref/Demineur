#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "utils.h"

#define NB_ROW_MIN      10
#define NB_COL_MIN      10


#define NB_ROW_MAX	20
#define NB_COL_MAX	20

#define NB_PERCENT_MIN	5
#define NB_PERCENT_MAX	50


int main(int argc, char*argv[]){

	int nbCol, nbRow,nbPercent, k, m;
	int * pScene = NULL; //Aire de jeu




        printf("===================DEMINEUR==================\n");

/*
	printf("Taille char : %d\n", sizeof(char));
	printf("Taille int : %d\n", sizeof(int));
	printf("Taille float : %d\n", sizeof(float));
	printf("Taille double : %d\n", sizeof(double));
	printf("Taille short : %d\n", sizeof(short));
	printf("Taille long : %d\n", sizeof(long));
	printf("Taille long long : %d\n", sizeof(long long));


        printf("Taille int8 : %d\n", sizeof(int8_t));
        printf("Taille unint8 : %d\n", sizeof(int));
        printf("Taille int16 : %d\n", sizeof(int));
        printf("Taille unint16 : %d\n", sizeof(int));
        printf("Taille int32 : %d\n", sizeof(int));
        printf("Taille unint32 : %d\n", sizeof(int));
        printf("Taille int64 : %d\n", sizeof(int));
        printf("Taille unint64 : %d\n", sizeof(int));
*/


/*
	do{
		printf("Entrer nbRow [%d:%d]", NB_ROW_MIN, NB_ROW_MAX);
		scanf("%d", &nbRow);

	}while((nbRow < NB_ROW_MIN) || (nbRow > NB_ROW_MAX));

        do{
                printf("Entrer nbCol [%d:%d]", NB_COL_MIN, NB_COL_MAX);
                scanf("%d", &nbCol);

        }while((nbCol < NB_COL_MIN) || (nbRow > NB_COL_MAX));


        do{
                printf("Entrer %%mines [%d:%d]", NB_PERCENT_MIN, NB_PERCENT_MAX);
                scanf("%d", &nbPercent);

        }while((nbPercent < NB_PERCENT_MIN) || (nbPercent > NB_PERCENT_MAX));
*/

	nbRow = 20;
	nbCol = 20;
	nbPercent = 30;

	printf("nbRow : %d, nbCol : %d, nbPercent ; %d\n\n",nbRow ,nbCol ,nbPercent);



	//ALLOCATION DYNAMIQUE  DU TABLEAU REPRESENTANT LE DEMINEUR

	pScene = (int*)malloc(nbRow * nbCol * sizeof(int));

	InitScene(pScene, nbRow, nbCol, nbPercent);

	PrintScene(pScene, nbRow, nbCol);

		switch (GetCoordinates(&m, &k, nbRow, nbCol))
		{
		case 0:
			DiscoverCell(pScene, m, k, nbRow, nbCol);
			PrintScene(pScene, nbRow, nbCol);
			break;
		case 1:
			break;
		case 2:
			break;
		case -1:

			free(pScene);
			pScene = NULL;
			printf("\/+n===================GOOD BYE===================\n");
			return EXIT_SUCCESS;

			break;
		}

	//RESTITUTION DYNAMIQUE DE LA ZONE MEMOIRE ALOUEE DYNAMIQUEMENT
	free(pScene);
	pScene = NULL;


        printf("\n===================GOOD BYE===================\n");



        return EXIT_SUCCESS;

}

