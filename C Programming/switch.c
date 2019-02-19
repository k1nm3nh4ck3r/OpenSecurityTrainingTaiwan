#include <stdio.h>
#include <stdlib.h>

int main(){
   int choice;
   int money = 0;
   int iexit = 0;
   while(!iexit){
      do{
         printf("[o] 咖啡廳您好，請選一杯飲品: 1. 咖啡 2. 果汁 3. 水 4. 休息一下 0. 離開: ");
         scanf("%d", &choice);
         if((choice < 0) || (choice > 4))
            printf("[-] 請重新輸入\n");
      }while((choice < 0) || (choice > 4));
      switch(choice){
         case 1:
            money+=90;
            printf("[o] 給你一杯咖啡，一杯90元，消費金額總共是%d元\n",money);
            break;
         case 2:
            money+=50;
            printf("[o] 給你一杯果汁，一杯50元，消費金額總共是%d元\n",money);
            break;
         case 3:
            money+=10;
            printf("[o] 給你一杯水，一杯10元，消費金額總共是%d元\n",money);
            break;
         case 4:
            printf("[o] 休息一下\n");
            sleep(1);
            break;
         case 0:
            iexit = 1;
            printf("[o] 消費金額一共是%d元，請麻煩結帳後再離開\n", money);
            break;
         default: 
            printf("[-] 程式錯誤\n");
            break;
      }
   }
   return 0;
}
