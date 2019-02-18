#include <stdio.h>
#include <stdlib.h>

void SetZero(int* ptr){
   *ptr = 0;
}

int main(){
   unsigned long long ullValue = 0;
   ullValue--;
   printf("value = %llx\n", ullValue);
   SetZero(&ullValue);
   if(ullValue != 0){
      printf("SetZero Failed!! (value = %llx)\n", ullValue);
   }
   return 0;
}
