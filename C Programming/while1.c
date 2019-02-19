#include <stdio.h>
#include <stdlib.h>

int main(){
   int a = 0;
   int tmp;
   int max = 1;
   while(a<1000){
      if(a != 0){
         tmp = a;
         while(tmp){
            max *= 10;
            tmp/=10;
         }
         tmp = a;
         while(max != 1){
            max /= 10;
            putchar('0'+tmp/max);
            tmp = tmp - (tmp / max)*max;
         }
      }else{
         putchar('0');
      }
      putchar(',');
      a++;
   }
   return 0;
}
