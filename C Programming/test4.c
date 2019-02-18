#include <stdio.h>
#include <stdlib.h>

#define print2(a)              \
if((a >= 0) && (a<10)) {       \
     putchar('0');             \
     putchar('0'+a);           \
}else{                         \
     putchar('0'+a/10);        \
     putchar('0'+a%10);        \
}


int main(){
   int a = 0;

   printf("a = %d = ", a = 0);print2(a);printf("\n");
   printf("a = %d = ", a = 9);print2(a);printf("\n");
   printf("a = %d = ", a = 10);print2(a);printf("\n");
   printf("a = %d = ", a = 99);print2(a);printf("\n");
   return 0;
}
