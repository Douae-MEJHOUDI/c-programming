#include <stdio.h>
#include <string.h>

////////Prototypes:

//Q1
int al_strlen (char string[]);
void al_strcpy(char destination[], char source[]);
void al_strcat(char destination[], char source[]);
//Q2
void str_reverse(char string[]);

////Main
int main()
{
    
    return 0;
}

////////Functions

////Q1:
int al_strlen (char* string)
{
    int nbcaract=0;
    char actuelcaract = 0;
    do
    {
        actuelcaract=string[nbcaract];
        nbcaract++;
    }while(actuelcaract != '\0');
    nbcaract--;
    return nbcaract;
}
void al_strcpy(char destination[], char source[])
{
    int nb = strlen(destination); //we can use al_strlen defined above
    for(int i = 0; i < nb; i++) 
        destination[i] = source[i];
    return;
}

void al_strcat(char destination[], char source[])
{
    int n1 = strlen(destination);
    int n2 = strlen(source);
    int i =0;
    for(i = 0; i < n2; i++)
        destination[i+n1] = source[i];
    destination[i] = source[n2];
}

////Q2: 
void str_reverse(char string[])  
{  
    int i=0;
    int n=0;
    char temp;  
    while(string[n] != '\0')
        n++;
    for (i = 0; i < n/2; i++)  
    {  
        temp = string[i];  
        string[i] = string[n-i-1];  
        string[n-i-1] = temp;  
    } 
    return;
}  


