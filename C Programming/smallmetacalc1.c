#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ULLNumber;
typedef char PATH[256];
typedef void* HANDLE;
typedef char OP[10];
typedef char CMD[1000];


int main(){
   HANDLE filehandle;
   PATH prefix, language, file, full;
   ULLNumber num1, num2;
   OP op;
   CMD cmd;
   
   // directory is at C:\MyProject
   strcpy(prefix, "/mnt/c/Users/user/Desktop/課程/OpenSecurityTrainingTaiwan");
   strcpy(language, "C Programming");
   printf("請輸入檔名: ");scanf("%256s", file);
   sprintf(full, "%s/%s/%s", prefix, language, file);
   printf("請輸入數字1: ");scanf("%llu", &num1);
   printf("請輸入運算元: ");scanf("%10s", op);
   printf("請輸入數字2: ");scanf("%llu", &num2);
   filehandle = fopen(full, "w");
   fprintf(filehandle, "#include <stdio.h>\n");
   fprintf(filehandle, "#include <stdlib.h>\n");
   fprintf(filehandle, "\n");
   fprintf(filehandle, "int main(){\n");
   fprintf(filehandle, "   printf(\"計算機執行結果: %%d\\n\", %llu %s %llu);\n", num1, op, num2);
   fprintf(filehandle, "   return 0;\n");
   fprintf(filehandle, "}\n");
   fclose(filehandle);
   sprintf(cmd, "gcc \"%s\" -o test", full);
   system(cmd);
   system("./test");
   return 0;
}

