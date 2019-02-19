#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned long long UNumber;
typedef long long SNumber;

int print_unum(UNumber num) {
   UNumber tmp, max = 1;
   int count = 0,i;
   tmp = num;
   while(tmp){
      //max *= 10;
      tmp/=10;
      count++;
   }
   for(i=1;i<count;i++)
      max *= 10;
   tmp = num;
   do{
      putchar('0'+tmp/max);
      tmp = tmp - (tmp / max)*max;
      max /= 10;
   }while(max > 0);
   return count;
}

int print_snum(SNumber num) {
   UNumber tmp, max = 1, unum = 0;
   int count = 0,i;
   if(num < 0){
     unum = -1 * num;
     putchar('-');
   }else{
     unum = num;
   }
   tmp = unum;
   while(tmp){
      //max *= 10;
      tmp/=10;
      count++;
   }
   for(i=1;i<count;i++)
      max *= 10;
   tmp = unum;
   do{
      putchar('0'+tmp/max);
      tmp = tmp - (tmp / max)*max;
      max /= 10;
   }while(max > 0);
   return count;
}

int main(){
   printf("print signed long long of LLONG_MIN: ");print_snum(LLONG_MIN);printf("\n");
   printf("print signed long long of LLONG_MAX: ");print_snum(LLONG_MAX);printf("\n");
   printf("print signed long long of ULLONG_MAX: ");print_snum(ULLONG_MAX);printf("\n");
   printf("print unsigned long long of LLONG_MIN: ");print_unum(LLONG_MIN);printf("\n");
   printf("print unsigned long long of LLONG_MAX: ");print_unum(LLONG_MAX);printf("\n");
   printf("print unsigned long long of ULLONG_MAX: ");print_unum(ULLONG_MAX);printf("\n");
   return 0;
}

