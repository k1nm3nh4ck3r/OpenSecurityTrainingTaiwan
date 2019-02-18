#include <stdio.h>
#include <stdlib.h>

int main(){
   int i;
   i=0;
   while(i < 0){
      printf("第1個迴圈: %d\n", i);
      i++;
   }
   i=0;
   do{
      printf("第2個迴圈: %d\n", i);
      i++;
   }while(i<0);
   return 0;
}

