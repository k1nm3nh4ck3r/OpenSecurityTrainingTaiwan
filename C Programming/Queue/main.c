#include <stdio.h>
#include <stdlib.h>

// 這裡使用expanable circle struct implement queue 
typedef struct tagQueue{
	int* pointer;
	int nowsize;
	int blocksize;
	int pointstart;
	int pointend;
}Queue;

#define DEFAULT_QUEUE_BLOCKSIZE 1024

void QueueInit(Queue* pqueue, int blocksize){
	if(pqueue){
		pqueue->pointer = (char*)malloc(sizeof(int)*(blocksize + 1)); // 0...nowsize Mod (nowsize+1)
		pqueue->blocksize = blocksize;
		pqueue->nowsize = blocksize;
		pqueue->pointstart = pqueue->pointend = 0;
	}
} 

void QueueAdd(Queue* pqueue, int ivalue){
	int nextpoint;
	int oldsize;
	int* newarray;
	int i,j=0;
	if(pqueue){
		// caculate next point of end
		nextpoint = (pqueue->pointend + 1) % (pqueue->nowsize + 1);
		if(nextpoint == pqueue->pointstart){
			// expending
			oldsize = pqueue->nowsize;
			pqueue->nowsize += pqueue->blocksize;
			newarray = (int*) malloc(sizeof(int)*(pqueue->nowsize+1));
			for(i=pqueue->pointstart;i!=pqueue->pointend;i = (i+1)%(oldsize+1)){
				newarray[j++] = pqueue->pointer[i];
			}
			pqueue->pointstart = 0;
			pqueue->pointend = j;
			free(pqueue->pointer);
			pqueue->pointer = newarray;
			
			// recaculate next point of end
			nextpoint = (pqueue->pointend + 1) % (pqueue->nowsize + 1);
		}
		
		// fill in the data value
		pqueue->pointer[pqueue->pointend] = ivalue;
		
		// point to next end
		pqueue->pointend = nextpoint;
	}
}

int QueuePop(Queue* pqueue){
	int ivalue = -1;
	if(pqueue){
		if(pqueue->pointstart != pqueue->pointend){
			// stack的話可以改為: 
			// int prevpoint;
			// prevpoint = (pqueue->pointend + pqueue->nowsize) % (pqueue->nowsize + 1);
			// ivalue = pqueue->pointer[prevpoint];
			// pqueue->pointend = prevpoint;
			ivalue = pqueue->pointer[pqueue->pointstart];
			pqueue->pointstart = (pqueue->pointstart + 1) % (pqueue->nowsize + 1);
		}
	}
	return ivalue;
}

void QueuePrint(Queue* pqueue){
	int i;
	if(pqueue){
		printf("Queue = {");
		for(i=pqueue->pointstart;i!=pqueue->pointend;i = (i+1)%(pqueue->nowsize+1)){
			if(i!=pqueue->pointstart){
				printf(", ");
			}
			printf("%d", pqueue->pointer[i]);
		}
		printf("}\n");
	}
}

void QueueClean(Queue* pqueue){
	if(pqueue){
		free(pqueue->pointer);
		pqueue->pointer = NULL;
		pqueue->blocksize = pqueue->nowsize = pqueue->pointstart = pqueue->pointend = 0;
	}
}

Queue queue;

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

void push(){
	int ivalue = 0;
	printf("Push Value: ");
	QueueAdd(&queue, input_integer());
}

void pop(){
	int ivalue;
	ivalue = QueuePop(&queue);
	printf("Pop Value: %d\n", ivalue);
}

int main(int argc, char *argv[]) {
	int exit = 0;
	int cont = 0;
	
	// 為了測試expanable可行這裡使用較小的值，正確的值應該是1024，比較難再重新配置，會比較有效率 
	QueueInit(&queue, 10);
	
	while(!exit){
		printf("1. push, 2. pop, 3. print, 0. exit: ");
		do{
			cont = 0;
			switch(getch()){
				case '0':printf("exit\n");exit = 1;break;
				case '1':printf("push\n");push();break;
				case '2':printf("pop\n");pop();break;
				case '3':printf("print\n");QueuePrint(&queue);break;
				default: cont = 1;break;
			}
		}while(cont);
	}
	
	QueueClean(&queue);
	 
	return 0;
}

