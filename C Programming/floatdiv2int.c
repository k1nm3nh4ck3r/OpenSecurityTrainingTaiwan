#include <stdio.h>
#include <stdlib.h>

int main(){
   int a = 3.0/1.5;
   printf("(decl int)(3.0/1.5) = %d\n", a);
   printf("(int)(3.0/1.5) = %d\n", (int)(3.0/1.5));
   int b = ((int)3.0)/1.5;
   printf("(decl int)(((int)3.0)/1.5) = %d\n", b);
   printf("(int)(3.0/1.5) = %d\n", (int)(((int)3.0)/1.5));
   int c = 3.0/((int)1.5);
   printf("(decl int)(3.0/((int)1.5)) = %d\n", c);
   printf("(int)(3.0/((int)1.5)) = %d\n", (int)(3.0/((int)1.5)));
   int d = 3/1.5;
   printf("(decl int)(3/1.5) = %d\n", d);
   printf("(int)(3/1.5) = %d\n", (int)(3/1.5));
   
   printf("\n");
   
   float e = 3.0/1.5;
   printf("(decl float)(3.0/1.5) = %f\n", e);
   printf("(float)(3.0/1.5) = %f\n", (float)(3.0/1.5));
   float f = ((float)3)/1.5;
   printf("(decl float)(((float)3)/1.5) = %f\n", f);
   printf("(float)(((float)3)/1.5) = %f\n", (float)(((float)3)/1.5));
   float g = 3/((float)1.5);
   printf("(decl float)(3/((float)1.5)) = %f\n", g);
   printf("(float)(3/((float)1.5)) = %f\n", (float)(3/((float)1.5)));
   float h = 3/1.5;
   printf("(decl float)(3/1.5) = %f\n", h);
   printf("(float)(3/1.5) = %f\n", (float)(3/1.5));
   return 0;
}
   
