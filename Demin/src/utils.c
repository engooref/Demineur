#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include <time.h>
#include <string.h>


/*******************************************************
* Affiche une table de nbRow x nbCol cellules
* en mode tabulaire sur le terminal
*
* INPUT : pScene : pointeur sur le tableau à afficher
*         nbRow : nombre de lignes
*         nbCol : nombre de colonnes
*         nbPercent : pourcentage de mines
*                     placées aléatoirement
*******************************************************/

void InitScene(int*pScene, int nbRow, int nbCol, int nbPercent){
	int k, m, nbMines, a, b;
	srand((unsigned int)time(NULL));
	memset(pScene, 0, nbRow * nbCol * sizeof(int));

	nbMines = (nbRow * nbCol * nbPercent) / 100;

	while(nbMines > 0){
		do{
			k = rand()%nbRow;
			m = rand()%nbCol;
		}while(*(pScene + k*nbCol + m) == MINE_VALUE);
		*(pScene + k*nbCol + m) = MINE_VALUE;

		for(a = k-1; a <= k+1; a++){
			if ((a < 0) || (a >= nbRow)) continue; //Passer à l'itération suivante
			for(b = m-1; b <= m+1; b++){
				if ((b < 0) || (b >= nbCol)) continue;
				if (*(pScene + a*nbCol + b) != MINE_VALUE) *(pScene + a*nbCol + b) += 1;
			}
		}



		nbMines -= 1;
	}


		for (k=0; k<nbRow; k++){
			for (m=0; m<nbCol; m++){
				mBitsSet(*(pScene + k*nbCol + m), CELL_MASKED_MASK);
			}
		}
}




/*******************************************************
* Affiche une table de nbRow x nbCol cellules
* en mode tabulaire sur le terminal
*
* INPUT : pTable : pointeur sur le tableau à afficher
*         nbRow : nombre de lignes
*         nbCol : nombre de colonnes
*******************************************************/

void PrintScene(int*pScene, int nbRow, int nbCol){

	int k, m;

	printf("\t");
        for (m = 0; m < nbCol; m++){
        	if (m % 10 == 0) printf("%d ", m / 10);
		else printf("  ");
        }
        printf("\n");



	printf("\t");
	for (m = 0; m < nbCol; m++){
		printf("%d ", m % 10);
	}
	printf("\n\n");

        printf("\t");
        for (m = 0; m < nbCol; m++){
                printf("_ ");
        }
	printf("\n");

	for(k = 0; k < nbRow; k++){
		printf("\n%2d  |\t", k);

		for (m = 0; m < nbCol; m++){
			if (mIsBitsSet(*(pScene + k*nbCol +m), CELL_MASKED_MASK)){
				printf(". ");
			}
			else {
				if (*(pScene + k*nbCol + m) == MINE_VALUE) {
					printf("%c ", MINE_CHAR);
				}
				else if (*(pScene + k*nbCol + m) == ZERO_VALUE) {
					printf("%c ", ZERO_CHAR);
				}
				else {
					printf("%d ", *(pScene + k*nbCol + m));
				}
			}


		}

		printf("  |\t%d", k);

	}

	printf("\n\t");

	for (m = 0; m < nbCol; m++){
                printf("_ ");
        }


	printf("\n\n\t");
        for (m = 0; m < nbCol; m++){
                if (m % 10 == 0) printf("%d ", m / 10);
                else printf("  ");
        }
        printf("\n");



        printf("\t");
        for (m = 0; m < nbCol; m++){
                printf("%d ", m % 10);
        }
        printf("\n");


}


int GetCoordinates(int *pX, int *pY, int nbRow, int nbCol) {

	char inputUtil[256], *caract = NULL;
	int nombreRetourner;

	do {
		printf("\nEntrer [M ? Q] x y: ");
		fgets(inputUtil, 255, stdin);


			caract = strtok(inputUtil, " ");

		if(caract != NULL) {
			switch(*caract)
			{

			case 'M':
			case 'm':

				nombreRetourner = 1;
				caract = strtok(NULL, " ");

				if(caract != NULL){

					*pX = atoi(caract);
				} else {
					nombreRetourner = -2;
				}

				caract = strtok(NULL, " ");

				if(caract != NULL) {

				*pY = atoi(caract);
				} else {
					nombreRetourner = -2;
				}
				break;

			case 'Q':
			case 'q':
				return -1;

			case '?':

				nombreRetourner = 2;
				caract = strtok(NULL, " ");

				if(caract != NULL){

					*pX = atoi(caract);
				} else {
					nombreRetourner = -2;
				}

				caract = strtok(NULL, " ");

				if(caract != NULL) {

				*pY = atoi(caract);
				} else {
					nombreRetourner = -2;
				}
				break;

			default:
				nombreRetourner = 0;

				if(caract != NULL){
					*pX = atoi(caract);
				} else {
					nombreRetourner = -2;
				}

				caract = strtok(NULL, " ");

				if(caract != NULL) {
					*pY = atoi(caract);
				} else {
					nombreRetourner = -2;
					}

				break;

			}

			printf("X = %d\n", *pX);
			printf("Y = %d\n", *pY);
		} else {
			nombreRetourner = -2;
		}


	}while(( ((*pX < 0) || (*pX > (nbCol - 1))) || ((*pY < 0) || (*pY > (nbRow - 1))) ) && (nombreRetourner == -2));

	return nombreRetourner;
}

int DiscoverCell(int *pScene, int x, int y, int nbRow, int nbCol) {

	//int value = -5;




	switch(mBitsMsk((*(pScene+y*nbCol+x)), CELL_VALUE_MASK))
	{
	case 9:
		for(y = 0; y < nbRow ; y++)
		{
			for(x = 0; x < nbCol ; x++)
			{
				mBitsClr((*(pScene+y*nbCol+x)), CELL_MASKED_MASK);
			}
		}
		PrintScene(pScene, nbRow, nbCol);
		return -1;
	default:
		mBitsClr((*(pScene+y*nbCol+x)), CELL_MASKED_MASK);
		PrintScene(pScene, nbRow, nbCol);

		return 0;
		break;
	}
}
