#include<stdio.h>
#include<stdlib.h>

//////Prototypes:

void* al_memchr(int* Mem, char c, unsigned int n);
void al_memset( int* Mem, int value, unsigned int n );
void  al_memcpy( int* copie, int * origine, unsigned int n );    
void al_memmove( void * destination, void * source, unsigned int n );

//////Functions :

//Memchr
void* al_memchr(int* Mem, int c, unsigned int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if(Mem[i] == c)
			return Mem+i;
	}
	return NULL;
}

//Memset 
void al_memset( int* Mem, int value, unsigned int n )
{
	int i = 0;
	for(i=0;i<n;i++)
		Mem[i]= value;
	return;
}

//Memcpy
void  al_memcpy( int* copie, int * origine, unsigned int n )
{
	int i=0;
	for(i=0;i<n;i++)
		copie[i]=origine[i];
	return;
}

//Memmove
void al_memmove( void * destination, void * source, unsigned int n )
{
	int* temp=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		temp[i]=source[i];
	}
	for(int i=0;i<n;i++)
	{
		destination[i]=temp[i];
	}
	return;
}


//////Main:
int main()
{
    int T[] = { 10, 'b', 30, 40, 'c', 60, 70, 80, 90, 100 };
	///TEST : Memchr
    void* ad = NULL;
    ad = al_memchr(T,97,10);
    if (ad != NULL)
        printf("il existe dans le bloc d'adresse N: %p\n",ad);
    else
        printf("il n'existe pas\n");
	///TEST : Memset
    al_memset(T,0,10);
    for(int i=0;i<10;i++)
        printf("%d  ",T[i]);

    T[] = { 10, 'b', 30, 40, 'c', 60, 70, 80, 90, 100 };

    return 0;

}

