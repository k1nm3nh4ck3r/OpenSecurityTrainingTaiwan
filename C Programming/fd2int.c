#include <stdio.h>
#include <stdlib.h>

int main(){
   double dpi = 3.1415926535897932384626L;
   printf("(double) PI=%.30lf\n", dpi);

   float fpi = (float)dpi;
   printf("(double to float) PI=%.30f\n", fpi);
   
   int num = 0;
   num = (int)dpi;
   printf("(double to int) num = %d\n", num);
   num = (int)fpi;
   printf("(float to int) num = %d\n", num);
}
