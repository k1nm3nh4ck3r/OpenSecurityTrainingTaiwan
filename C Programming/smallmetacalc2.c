#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char PATH[256];
typedef void* HANDLE;
typedef char CMD[1000];
typedef char EXP[1000];


int main(){
   HANDLE filehandle;
   PATH prefix, language, file, full;
   CMD cmd;
   EXP exp;
   
   // directory is at C:\MyProject
   strcpy(prefix, "/mnt/c/Users/user/Desktop/課程/OpenSecurityTrainingTaiwan");
   strcpy(language, "C Programming");
   strcpy(file, "calc.c");
   sprintf(full, "%s/%s/%s", prefix, language, file);
   printf("請輸入運算式: ");scanf("%1000s", exp);
   filehandle = fopen(full, "w");
   fprintf(filehandle, "#include <stdio.h>\n");
   fprintf(filehandle, "#include <stdlib.h>\n");
   fprintf(filehandle, "#include <math.h>\n");
   fprintf(filehandle, "\n");
   fprintf(filehandle, "int main(){\n");
   fprintf(filehandle, "   double dexp = %s;\n", exp);
   fprintf(filehandle, "   printf(\"計算機執行結果: %%lf\\n\", dexp);\n");
   fprintf(filehandle, "   return 0;\n");
   fprintf(filehandle, "}\n");
   fclose(filehandle);
   sprintf(cmd, "gcc \"%s\" -o test", full);
   system(cmd);
   system("./test");
   return 0;
}

