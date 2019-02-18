#include <stdio.h>
#include <stdlib.h>

int main(){
   int a = 0;
   int tmp;
   int max = 1;
   for(a=0;a<1000;a++){
      if(a != 0){
         for(tmp=a;tmp;tmp/=10)
            max *= 10;
         for(tmp=a;max != 1;tmp = tmp - (tmp / max)*max){
            max /= 10;
            putchar('0'+tmp/max);
         }
      }else{
         putchar('0');
      }
      putchar(',');
   }
   return 0;
}
