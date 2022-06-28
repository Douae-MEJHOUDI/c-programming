#include <stdio.h>


////Struct:
typedef struct inst inst;
struct inst {
  int a;
  char str[100];
};

/////Prototypes :
void swap(inst* f, inst* s);
void print(inst s);



////Main :
int main()
{
    inst b={5,"abc"};
    inst c={8,"def"};
    print(b);
    print(c);
    swap(&b,&c);
    printf("after sawp\n");
    print(b);
    print(c);
    return 0;
}

////Functions :
void swap(inst* f, inst* s)
{
    inst z= *f;
    *f=*s,
    *s=z;
    return ;
}

void print(inst s)
{
    printf("int = %d and string = %s \n",s.a , s.str );
    return;
}
