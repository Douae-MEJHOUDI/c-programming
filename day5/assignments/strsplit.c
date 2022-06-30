#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **al_strsplit(char *str, char delim);
int c_w(char* str, char delim);
int c_caract(char* str, char delim, unsigned i);


int main()
{
    char* str="khaoula: mejhoudi jan";
    int n= c_w(str, ' ');
    printf("%d\n",n);
    n=c_caract(str, ' ',0);
    printf("%d\n",n);
    char** T=al_strsplit(str, ' ');
    for (int i=0;i<8;i++)
    {
        printf("%c",T[0][i]);
    }
    

    return 0;
}

//number of caracters
int c_caract(char* str, char delim, unsigned i)
{
    int j=0, nb=0, n=strlen(str);
    if (str[i]==delim)
        return 0;
    while (i+j<n && str[i+j]!=delim)
    {
        nb++;
        j++;
    }
    return nb;
}

//number of words
int c_w(char* str, char delim)
{
    int i=0, nb=0, n= strlen(str);
    while (i<n)
    {
        if (str[i] == delim)
        {
            i++;
            continue;
        }
        while (str[i]!=delim)
            i++;
        nb++;
        i++;
    }
    return nb;
}


char **al_strsplit(char *str, char delim)
{
    int n=strlen(str) , i=0 ;
    int nb=c_w(str,delim);
    char** T=(char**)malloc(nb*sizeof(char*));
    int j=0;
    while (i<n)
    {
        int c=c_caract(str, delim, i);
        if(c==0)
        {
            i++;
            continue;
        }
        T[j]=(char*)malloc(c*sizeof(char));
        for (int a=i; a<c; a++)
        {
            T[j][a]=str[a];
        }
        j++;
        i+=c;
    }
    return T;
}

