#include <stdio.h>
#include <math.h>


float Scet(float a, float b, float c,
           float* x1, float* x2)
{
  float d;
  d=b*b-4*a*c;

  if(a==0)
  {
    if(b==0)
      return (c==0)? 3 : 0;
    else  //b!=0
    {
      *x1=-c/b;
      return 1;
    }
  }

  else  //a!=0
  {
    if(d<0)
      return 0;
    else if(d==0)
    {
      *x1=-b/(2*a);
      return 1;
    }
    else  //d>0
    {
      *x1=(-b+sqrt(d))/(2*a);
      *x2=(-b-sqrt(d))/(2*a);
      return 2;
    }
  }
}


int main()
{
  float a,b,c,x1,x2;
  int k;
  printf("Please, enter coefficients"
         "of the equation.");
  scanf("%f%f%f",&a,&b,&c);

  k=Scet(a,b,c,&x1,&x2);

  switch( k )
  {
    case 0: printf("Korney net");
      break;
    case 1: printf("Odin koren = %f",x1);
      break;
    case 2: printf("Dva kornya = %f and %f",x1,x2);
      break;
    case 3: printf("Korney besconecno mnogo");
      break;
  }
}
