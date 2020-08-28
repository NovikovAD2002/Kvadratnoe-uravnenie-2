#include <stdio.h>
#include <math.h>


//---------------------------------------------------------
//!Reshenie kvadratnogo uravneniya vida ax^2+bx+c=0
//!
//!@param [in]  a a-coefficient
//!@param [in]  b b-coefficient
//!@param [in]  c c-coefficient
//!@param [out] x1 x1-perviy otvet
//!@param [out] x2 x2-vtoroy otvet
//!
//!@return      Otvety
//!
//!@note        Pri besconechnom kolicestve variantov
//!             resheniya, programma vosvrashaet 3
//---------------------------------------------------------

float Scet(float a, float b, float c, float* x1, float* x2)
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

  else    //a!=0
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


//---------------------------------------------------------
//!Test dlya proverki situazii 0 0 0
//!
//!@param [in]  a a-coefficient
//!@param [in]  b b-coefficient
//!@param [in]  c c-coefficient
//!
//!@return      Nomer testa
//!
//---------------------------------------------------------

float test_1(float a, float b, float c)
{
  float x1, x2;
  if(((b==0)&&(c==0)&&(a==0)&&(Scet(a,b,c,&x1,&x2)==3))||((b!=0)||(c!=0)||(a!=0)))
    printf("test_1 complete\n");
  else
    printf("error\n");
  return 1;
}

//---------------------------------------------------------
//!Test dlya proverki situazii 0 ? ?
//!
//!@param [in]  a a-coefficient
//!@param [in]  b b-coefficient
//!@param [in]  c c-coefficient
//!
//!@return      Nomer testa
//!
//---------------------------------------------------------

float test_2(float a,float b,float c)
{
  float x1, x2;
  if(((b!=0)&&(a==0)&&(Scet(a,b,c,&x1,&x2)==1))||(a!=0)||(b==0))
    printf("test_2 complete\n");
  else
    printf("error\n");
  return 2;
}

//---------------------------------------------------------
//!Test dlya proverki situazii 0 0 ?
//!
//!@param [in]  a a-coefficient
//!@param [in]  b b-coefficient
//!@param [in]  c c-coefficient
//!
//!@return      Nomer testa
//!
//---------------------------------------------------------

float test_3(float a,float b, float c)
{
  float x1, x2;
  if(((b==0)&&(c!=0)&&(a==0)&&(Scet(a,b,c,&x1,&x2)==0))||(b!=0)||(c==0)||(a!=0))
    printf("test_3 complete\n");
  else
    printf("error\n");
  return 3;
}

//---------------------------------------------------------
//!Test dlya proverki situazii, kogda dis < 0
//!
//!@param [in]  a a-coefficient
//!@param [in]  b b-coefficient
//!@param [in]  c c-coefficient
//!
//!@return      Nomer testa
//!
//---------------------------------------------------------

float test_4(float a,float b, float c)
{
  float x1, x2;
  if(((b*b-4*a*c<0)&&(Scet(a,b,c,&x1,&x2)==0))||(b*b-4*a*c>=0))
    printf("test_4 complete\n");
  else
    printf("error\n");
  return 4;
}

//---------------------------------------------------------
//!Test dlya proverki situazii, kogda dis = 0
//!
//!@param [in]  a a-coefficient
//!@param [in]  b b-coefficient
//!@param [in]  c c-coefficient
//!
//!@return      Nomer testa
//!
//---------------------------------------------------------

float test_5(float a,float b, float c)
{
  float x1, x2;
  if(((b*b-4*a*c==0)&&(Scet(a,b,c,&x1,&x2)==1))||(b*b-4*a*c!=0))
    printf("test_5 complete\n");
  else
    printf("error\n");
  return 5;
}

//---------------------------------------------------------
//!Test dlya proverki situazii, kogda dis > 0
//!
//!@param [in]  a a-coefficient
//!@param [in]  b b-coefficient
//!@param [in]  c c-coefficient
//!
//!@return      Nomer testa
//!
//---------------------------------------------------------

float test_6(float a,float b, float c)
{
  float x1, x2;
  if(((b*b-4*a*c>0)&&(Scet(a,b,c,&x1,&x2)==2))||(b*b-4*a*c<=0))
    printf("test_6 complete\n");
  else
    printf("error\n");
  return 6;
}


int main()
{
  float a,b,c,x1,x2;
  int k;
  printf("Please, enter coefficients"
         "of the equation.");
  int scanf_return = scanf("%f%f%f",&a,&b,&c);

  if(scanf_return!=3)
  {
    printf("error");
    return 0;
  }

  k=Scet(a,b,c,&x1,&x2);

  switch( k )
  {
    case 0: printf("Korney net\n\n");
    break;
    case 1: printf("Odin koren = %f\n\n",x1);
    break;
    case 2: printf("Dva kornya = %f and %f\n\n",x1,x2);
    break;
    case 3: printf("Korney besconecno mnogo\n\n");
    break;
  }
  #ifdef TEST
    k=test_1(a,b,c);
    k=test_2(a,b,c);
    k=test_3(a,b,c);
    k=test_4(a,b,c);
    k=test_5(a,b,c);
    k=test_6(a,b,c);
  #endif // TEST
  return 0;
}
