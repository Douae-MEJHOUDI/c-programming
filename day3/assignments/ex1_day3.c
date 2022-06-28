#include <stdio.h>
#include <stdlib.h>

typedef struct complex complex;
struct complex
{
  float x , y;  
};

/////Prototypes :
complex add (complex a, complex b);
complex sub (complex a,complex b);
complex mulByCom(complex a , complex b );
complex mulBySca (complex a, float k);
complex conjj (complex a);
complex divv (complex a , complex b );
void print (complex a);

/////Main :
int main()
{
    complex a ={5,0}, b={1,1};
    print(a);
    print(b);
    print(add(a,b));
    print(sub(a,b));
    print(mulByCom(a,b));
    print(divv(a,b));
    

    return 0;
}


///// Function :

complex add (complex a, complex b)
{
    complex s ={a.x + b.x , a.y + b.y };
    return s;
}

complex sub (complex a,complex b)
{
    complex d={a.x - b.x , a.y - b.y};
    return d;
}

///multipy by complex:
complex mulByCom(complex a , complex b )
{
    complex m ={ a.x * b.x - a.y * b.y , a.x * b.y + a.y * b.x};
    return m;
}

///multipy by scalair:
complex mulBySca (complex a, float k)
{
	complex sc ={a.x * k, a.y *k};
	return sc;
}

///conjuguee:
complex conjj (complex a)
{
	complex c= {a.x , -a.y};
	 return c;
}

///division by complex:
complex divv (complex a , complex b )
{
    if (b.x == 0 && b.y ==0)
    {
        printf("impossible");
        exit(EXIT_FAILURE);
    }
	complex conb= conjj(b);
	complex a_b = mulByCom (a, conb);
	complex b_b= mulByCom (b,conb); 
	complex di = mulBySca(a_b , 1/b_b.x);
	return di;
}


void print (complex a)
{
    printf("%f +i %f \n",a.x,a.y);
    return ;
}

