/*******FILE : utils.h*************************/


#define MINE_VALUE 	9
#define MINE_CHAR 	'*'

#define ZERO_VALUE	0
#define ZERO_CHAR	' '

#define CELL_MASKED_MASK        0x00000100
#define CELL_VALUE_MASK		0x0000000F


#define mBitsSet(f,m)   ((f) |= (m))
#define mBitsClr(f,m)   ((f) &= (~(m)))
#define mBitsTgl(f,m)   ((f) ^= (m))

#define mIsBitsSet(f,m) (((f) & (m)) == (m))
#define mIsBitsClr(f,m) (((~(f)) & (m)) == (m))
#define mBitsMsk(f,m)   ((f)&(m))



/*******************************************************
* Affiche une table de nbRow x nbCol cellules
* en mode tabulaire sur le terminal
*
* INPUT : pScene : pointeur sur le tableau à afficher
*	  nbRow : nombre de lignes
*	  nbCol : nombre de colonnes
*	  nbPercent : pourcentage de mines
*		      placées aléatoirement
*******************************************************/

void InitScene(int*pScene, int nbRow, int nbCol, int nbPercent);


/*******************************************************
* Affiche une table de nbRow x nbCol cellules
* en mode tabulaire sur le terminal
*
* INPUT : pTable : pointeur sur le tableau à afficher
*         nbRow : nombre de lignes
*         nbCol : nombre de colonnes
*******************************************************/

void PrintScene(int*pScene, int nbRow, int nbCol);


int GetCoordinates(int *pX, int *pY, int nbRow, int nbCol);

int DiscoverCell(int *pScene, int x, int y, int nbRow, int nbCol);
