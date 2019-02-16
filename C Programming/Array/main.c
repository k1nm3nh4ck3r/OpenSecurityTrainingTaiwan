#include <stdio.h>
#include <stdlib.h>

typedef struct _ExpendableArray{
	int blocksize;
	int nowsize;
	int* pointer;
}ExpendableArray, *PExpendableArray;

// 為了測試expanable可行這裡使用較小的值，正確的值應該是1024，比較難再重新配置，會比較有效率 
#define DEFAULT_BLOCKSIZE 2

#define CreateArrayDefault() CreateArray(DEFAULT_BLOCKSIZE)

PExpendableArray CreateArray(int blocksize) {
	PExpendableArray array = NULL;
	int* oarray;
	int i;
	
	array = (PExpendableArray)malloc(sizeof(ExpendableArray));
	if(array){
		oarray = (int*)malloc(sizeof(int)*(blocksize+1));
		if(oarray){
			array->nowsize = array->blocksize = blocksize;
			array->pointer = oarray;
			memset(oarray, 0, sizeof(int)*(blocksize+1));
		}else{
			free(array);
			array = NULL;
		}
	}
	
	return array;
}

void CleanArray(PExpendableArray* pparray) {
	if(pparray) {
		free((*pparray)->pointer);
		free(*pparray);
		(*pparray) = NULL;
	}
}

void ExpendArray(PExpendableArray parray, int index) {
	int iSizeFromIndex = index+1;
	int* oarray = NULL;
	int needsize;
	int i;
	//printf("%d %d %d\n", iSizeFromIndex, parray->nowsize, iSizeFromIndex > parray->nowsize);
	if((parray) && (iSizeFromIndex > parray->nowsize)) {
		needsize = parray->nowsize;
		while((iSizeFromIndex > needsize)){
			needsize += parray->blocksize;
		}
		oarray = (int*)malloc(sizeof(int)*(needsize + 1));
		memcpy(oarray, parray->pointer, sizeof(int)*(parray->nowsize));
		memset(&oarray[parray->nowsize], 0, sizeof(int)*(needsize - parray->nowsize + 1));
		free(parray->pointer);
		parray->pointer = oarray;
		parray->nowsize = needsize;
	}
}

int ArrayGet(PExpendableArray parray, int index) {
	if(parray){
		ExpendArray(parray, index);
		return parray->pointer[index];
	}
	return 0;
}

void ArraySet(PExpendableArray parray, int index, int ivalue) {
	if(parray){
		ExpendArray(parray, index);
		parray->pointer[index] = ivalue;
	}
}

void ArrayPrint(PExpendableArray parray){
	int i;
	
	printf("{");
	if(parray){
		for(i=0;i<parray->nowsize;i++){
			if(i!=0){
				printf(", ");
			}
			printf("%d", parray->pointer[i]);
		}
	}
	printf("}");
}

int input_integer(){
	int ivalue = 0;
	int started = 0;
	int c;
	while(1){
		c = getch();
		if((c == '\n' || c == '\r') && (started == 1)){
			putch(c);
			break;
		}else if((c >= '0') && (c <= '9')){
			putch(c);
			ivalue = ivalue*10 + c - '0';
			started = 1;
		}
	}
	putch('\n');
	fflush(stdin);
	return ivalue;
}

PExpendableArray exparr = NULL;

void get(){
	int index = 0;
	int value = 0;
	printf("index: ");
	index = input_integer();
	//printf("index = %d\n", index);
	value = ArrayGet(exparr, index);
	printf("value #%d = %d\n", index, value);
	//ArrayPrint(exparr);printf("\n");
}

void set(){
	int index = 0;
	int value = 0;
	int oldvalue = 0;
	
	oldvalue = ArrayGet(exparr, index);
	printf("index: ");
	index = input_integer();
	//printf("index = %d\n", index);
	printf("value: ");
	value = input_integer();
	ArraySet(exparr, index, value);
	//ArrayPrint(exparr);printf("\n");
	printf("value #%d changed from %d to %d\n", index, oldvalue, value);
}

int main(int argc, char *argv[]) {
	int exit = 0;
	int c;
	int cont = 0;
	
	exparr = CreateArrayDefault();
	
	while(!exit){
		printf("1. get 2. set 3. print 0. exit: ");
		do{
			cont = 0;
			switch(getch()){
				case '1':printf("get\n");get();break;
				case '2':printf("set\n");set();break;
				case '3':printf("print\n");printf("array = ");ArrayPrint(exparr);printf("\n");break;
				case '0':printf("exit\n");exit = 1;break;
				default:cont = 1;break;
			}
		}while(cont);
	}
	
	CleanArray(&exparr);
	return 0;
}

