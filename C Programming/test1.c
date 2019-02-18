#include <stdio.h>
#include <stdlib.h>

int main(){
   // 1. 整數
   // 1-1. 基本型態
   int a = 1;
   int*pa = &a;
   int arra[3] = {4,5,6};
   int parra = arra;

   // 1-2. print
   printf("a = %d\n", a);
   printf("pa = %p, *pa = %d\n", pa, *pa);
   printf("arra = {%d, %d, %d}\n", arra[0], arra[1], arra[2]);
   printf("(當指標)arra = {%d, %d, %d}\n", *((int*)arra), *((int*)arra+1), *((int*)arra+2));
   printf("parra = %p = 指標:{%p, %p, %p}, 值:{%d, %d, %d}\n", 
           parra, 
           parra, parra+1, parra+2, 
           *(parra), *(parra+1), *(parra+2));
   printf("(當陣列指標)parra = %p = 指標:{%p, %p, %p}, 值:{%d, %d, %d}\n", 
           parra, 
           &parra[0], &parra[1], &parra[2], 
           parra[0], parra[1], parra[2]);
   return 0;
}
