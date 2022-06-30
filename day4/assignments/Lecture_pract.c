#include<stdio.h>
#include<string.h>

//Prototypes:
char* al_gets(char string[]);
char* al_puts(char string[]);
void function9();

int main ()
{
    //Q1
    char s1[]="Hello" ;
    printf("q1:%s \n",s1);
    //Q2
    char s2[10];
    strcpy(s2,"World");
    printf("q2:%s \n",s2);
    //Q3
    
    char s3[30];
    
    int i=0 , j=0;
    
    while (s1[i] != '\0')
    {
        s3[i]=s1[i];
        i++;
    }
    s3[i]=' ';
    i++;
    
    while (s2[j] != '\0')
    {
        s3[i+j]=s2[j];
        j++;
    }
    s3[i+j]='\0';
    printf("q3:%s\n",s3);
    //Q4
    char s4[10];
    strcat(s4,s1);
    strcat(s4," ");
    strcat(s4,s2);
    printf("q4:%s \n",s4);
    
    //Q5
    char s5[20]; 
    strcpy(s5, s1);
    strcpy(s5+5," ");
    strcpy(s5+6, s2);
    printf("q5:%s \n",s5);
    
    //Q6

    /*
    char s1[ ] = "Hello";
    char s2[ ] = "hello";
    char s3[ ] = {'h', 'e', 'l' , 'l', '\0'}
    strcmp(s1, s2); => s1 < s2 car H<h donc le resultat sera : une valeur negative (FALSE)
    strcmp(s2, s1); => h>H, le resultat sera : 1 (ou une valeur positive: TRUE)
    strcmp(s1, s3); => H<h, le resultat sera : une valeur negative 
    strcmp(s2, s3); => la chaine s3 se termine avant la chaine s2, donc s2>s3 d'où le resultat sera une valeur positive
    */
    
    //Q7
    char string[5];
    al_gets(string);
    printf("q7:%s \n\n",string);
    //Q8
     printf("q8:\n");
    al_puts(string);
    
    return 0;
}

//Q7

char* al_gets(char string[])
{
    int i = 0;
    int c = getchar();
    while(c != '\n')
    {
        string[i] = (char)c;
        c = getchar();
        i++;
    }
    string[i] ='\0';
    return string;
}

//Q8

char* al_puts(char string[])
{
    int i = 0;
    while(string[i] != '\0')
    {
        putchar(string[i]);
        i++;
    }
}

//Q9
void function9()
{
    char A[10];
    char B[] = "Khaoula";
    gets(A);
    strcmp(A,B) == 0 ? puts("success") : puts("failed");
}