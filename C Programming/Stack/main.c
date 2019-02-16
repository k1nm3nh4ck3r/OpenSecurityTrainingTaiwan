#include <stdio.h>
#include <stdlib.h>

typedef struct _Stack{
	int sizenow;
	int blocksize;
	int nowtop;
	int* pointer;
}Stack, *PStack;

PStack CreateStack(int blocksize){
	PStack stack = NULL;
	stack = (PStack)malloc(sizeof(Stack));
	
	if(stack){
		stack->nowtop = 0;
		stack->sizenow = stack->blocksize = blocksize;
		stack->pointer = (int*)malloc(sizeof(int)*blocksize);
	}
	
	return stack;
}

void CleanupStack(PStack* pstack) {
	if(pstack && *pstack) {
		if((*pstack)->pointer) {
			free((*pstack)->pointer);
			free(*pstack);
			*pstack = NULL;
		}
	}
}

void PushIntoStack(PStack stack, int ival){
	int* pointer = NULL;
	int i;
	if(stack){
		if(stack->nowtop >= stack->sizenow){
			stack->sizenow += stack->blocksize;
			pointer = (int*)malloc(sizeof(int)*stack->sizenow);
			for(i=0;i<stack->nowtop;i++){
				pointer[i] = stack->pointer[i];
			}
			free(stack->pointer);
			stack->pointer = pointer;
			pointer = NULL;
		}
		stack->pointer[stack->nowtop] = ival;
		stack->nowtop ++;
	}
}

int PopFromStack(PStack stack){
	int ret = -1;
	if(stack){
		if(stack->nowtop > 0){
			ret = stack->pointer[--stack->nowtop];
		}
	} 
	return ret;
}

void PrintFromTailOfStack(PStack stack){
	int i;
	if(stack){
		printf("[");
		for(i=stack->nowtop-1;i>=0;i--){
			printf("%d ", stack->pointer[i]);
		}
		printf("]");
	}
}

PStack gstack = NULL;
int gistackblocksize = 10;

int inputdecint(){
	int c;
	int num = 0;
	int inputed = 0;
	
	while(1){
		c = getch();
		if((c >= '0') && (c <= '9')){
			putchar(c);
			num = num * 10 + c - '0';
			inputed = 1;
		}else if (((c == '\r') || (c == '\n')) && inputed){
			break;
		}else if((c=='\b') && (inputed)){
			putchar('\b');
		}
	}
	
	fflush(stdin);
	
	return num;
}

int init() {
	gstack = CreateStack(gistackblocksize);
	return gstack != NULL;
}

void choice_push(){
	int ival;
	if(gstack != NULL){
		ival = inputdecint();
		printf("\r                 \r");
		printf("%d => ", ival);
		PrintFromTailOfStack(gstack);
		PushIntoStack(gstack, ival);
		printf(" ==>> ");
		PrintFromTailOfStack(gstack);
		printf("\n");
	}
}

void choice_pop(){
	int ival;
	if(gstack != NULL){
		ival = PopFromStack(gstack);
		printf("%d <= ", ival);
		PrintFromTailOfStack(gstack);
		printf("\n");
	}
}

void cleanup(){
	if(gstack != NULL){
		CleanupStack(&gstack);
	}
}

int main(int argc, char *argv[]) {
	int c;
	int exit = 0;
	
	if(init()){
		while(!exit){
			printf("0: exit, 1. push, 2. pop, your choice: ");
			c = getch() - '0';
			switch(c){
				case 0:printf("exit\n");exit=1;break;
				case 1:printf("push\n");choice_push();break;
				case 2:printf("pop\n");choice_pop();break;
			}
		}
		
		cleanup();
	}
	
	return 0;
}

