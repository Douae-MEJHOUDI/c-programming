#include <stdio.h>
#include <stdlib.h>


////////PROTOTYPES :
int*** tab_piece(int nb);
int nbpiece(FILE* f);
void remplissage_piece(FILE* f,int*** T);
int** mapp (unsigned n);
void affichage_map(int** carte, int dimap);
int test_place (int** piece, int **maps, int n, int x, int y);
void placer (int** piece, int **maps, int x, int y);
void annuler (int** piece, int **maps, int x, int y);
int jeu(int*** T,int** carte,int nbp,int dimap,int p);
int alpha[10]={'a','b','c','d','e','f','g','h','i','j'};

////////MAIN :

int main()
{
    FILE *f;
    char c;
    int dimap=5;
    int nb=nbpiece(f);;
    int*** T= tab_piece(nb);
    f=fopen ("piece.txt", "rt");
    remplissage_piece(f,T);
    int **carte = mapp (dimap);

    int p=0;

    affichage_map(carte,dimap);
    printf("%d \n",jeu(T,carte,nb,dimap,p));
    affichage_map(carte,dimap);
    return 0;
}

////////FUNCTIONS :

int nbpiece(FILE* f)
{
    int nb=0;
    char c;
    f=fopen ("piece.txt", "rt");
    while(!feof(f))
    {
        c=fgetc(f);
        if (c == '\n')
            nb++;
    }
    return (nb+1)/4;
}

void remplissage_piece(FILE* f,int*** T)
{
    char c;
    int i=0, j=0 , k=0;
    while((c=fgetc(f))!=EOF)
    {
        if(c!='*' && c!='.')
            continue;
        if (c=='*')
            T[i][j][k]=alpha[i];
        if (c=='.')
            T[i][j][k]=0;
        //printf("k=%d j=%d i=%d \n",k,j,i);
        if(k==2)
        {
            if(j==2)
            {
                i++;
                j=0;
                k=0;
                continue;
            }
            j++;
            k=0;
            continue;
        }
        k++;
    }
    return;
}

int*** tab_piece(int nb)
{
    int*** T=(int***)malloc(nb*sizeof(int**));
    for (int i=0;i<nb;i++)
    {
        T[i]=(int**)malloc(3*sizeof(int*));
        for (int j=0;j<3;j++)
        {
            T[i][j]=(int*)malloc(3*sizeof(int));
            for(int k=0;k<3;k++)
                T[i][j][k]=1;
        }
    }
    return T;
}

int** mapp (unsigned n)
{
  int **T = malloc (n * sizeof (int *));
  int i = 0;
  while (i < n)
    {
      int *A = malloc (n * sizeof (int));
      T[i] = A;
      i++;
    }
  for (i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
	{
	  T[i][j] = 0;
	}
    }
  return T;
}

int test_place (int** piece, int **maps, int n, int x, int y)
{
    int i = 0,  xx= x, yy=y ;
    while (i < 3 && xx < n)
    {
        int j = 0;
        yy=y;
        while (j < 3 && yy < n)
	    {
	        if (piece[i][j] != 0 && maps[xx][yy] != 0)
	        {
	            return 0;
	        }
	        yy++;
	        j++;
	    }
	    if(j<3 && yy==n)
	    {
	       while(j<3)
	       {
	           if (piece[i][j]!=0)
	                return 0;
	           j++;
	       }
	       
	    }
        i++;
        xx++;
    }
    if(i<3 && xx==n)
    {
        while(i<3)
        {
            int j=0;
            while (j<3)
            {
                if(piece[i][j]!=0)
                {
                    return 0;
                }
                j++;
            }
            i++;
        }
    }
    return 1;
}

void affichage_map(int** carte, int dimap)
{
    for (int i=0;i<dimap;i++)
    {
        for (int j=0;j<dimap;j++)
        {
            if(carte[i][j] == 0)
            {
                printf("%d ",carte[i][j]);
                continue;
            }
            printf("%c ",carte[i][j]);
        }
        printf("\n");
    }
    return ;
}

void placer (int** piece, int **maps, int x, int y)
{
    int yy=y, xx=x;
    for (int i = 0; i < 3; i++)
    {
        yy=y;
        for (int j = 0; j < 3; j++)
	    {
	     if (piece[i][j] != 0)
	         maps[xx][yy] = piece[i][j];
	      yy++;
	 }
        xx++;
    }
    return ;
}

void annuler (int** piece, int **maps, int x, int y)
{
    int yy=y, xx=x;
    for (int i = 0; i < 3; i++)
    {
        yy=y;
        for (int j = 0; j < 3; j++)
	    {
	        if (piece[i][j] != 0)
	            maps[xx][yy] = 0;
	        yy++;
	    }
        xx++;
    }
    return ;
}

int jeu(int*** T,int** carte,int nbp,int dimap,int p)
{
    int i=0,j=0;
    while(i<dimap)
    {
        j=0;
        while(j<dimap)
        {
            if (test_place(T[p],carte,dimap,i,j))
            {
                placer(T[p],carte,i,j);
                if(p+1==nbp)
                    return 1;
                
                p++;
                
                if(jeu(T,carte,nbp,dimap,p))
                    return 1;
                p--;
                annuler(T[p],carte,i,j);
            }
            j++;
        }
        i++;
    }
    
    return 0;
}

