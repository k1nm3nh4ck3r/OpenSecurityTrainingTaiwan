#include <stdio.h>
#include <stdlib.h>

#define print3(a)               \
if((a >= 0) && (a<10)) {        \
   putchar('0');                \
   putchar('0');                \
   putchar('0'+a);              \
}else{                          \
   if((a >= 10) && (a<100)) {   \
      putchar('0');             \
      putchar('0'+a/10);        \
      putchar('0'+a%10);        \
   } else {                     \
      putchar('0'+a/100);       \
      putchar('0'+(a%100)/10);  \
      putchar('0'+a%10);        \
   }                            \
}


int main(){
   int a = 0;

   printf("a = %d = ", a = 0);print3(a);printf("\n");
   printf("a = %d = ", a = 9);print3(a);printf("\n");
   printf("a = %d = ", a = 10);print3(a);printf("\n");
   printf("a = %d = ", a = 99);print3(a);printf("\n");
   printf("a = %d = ", a = 100);print3(a);printf("\n");
   printf("a = %d = ", a = 999);print3(a);printf("\n");
   return 0;
}
