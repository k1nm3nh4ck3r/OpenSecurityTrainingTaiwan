#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void HexDump(unsigned char* data, size_t size, int block){
	size_t i, j;
	
	printf("%19c", ' ');
	
	for(i=0;i<block;i++){
		printf("%02X ", i);
	}
	printf("   ");
	
	for(i=0;i<block;i++){
		printf("%X", i%16);
	}
	printf("\n");
	
	for(i=0;i<size;i++){
		if(i%block == 0){
			printf("%016p | ", &data[i]);
		}
		printf("%02X ", data[i]);
		if((i+1)%block == 0){
			printf("   ");
			for(j=0;j<block;j++){
				if((data[i-block+1+j] >= 32) && (data[i-block+1+j] <= 126)){
					printf("%c", data[i-block+1+j]);
				}else{
					printf(".");
				}
			}
			printf("\n");
		}
	}
	if(i%block > 0){
		for(j=0;j<=(block - i%block); j++){
			printf("   ");
		}
		for(j=0;j<(i%block);j++){
			if((data[i-i%block+j] >= 32) && (data[i-i%block+j] <= 126)){
				printf("%c", data[i-i%block+j]);
			}else{
				printf(".");
			}
		}
		printf("\n");
	}
	printf("%016p |\n", &data[size]);
}

int main(int argc, char *argv[]) {
	/*int i, j;
	char test[34] = "";
	
	for(i=0;i<33;i++){
		for(j=0;j<=i;j++){
			test[j] = 'A';
		}
		test[j] = '\0';
		HexDump(test, i+2, 32);
	} 
	
	
	HexDump("中文測試: 你好，你在哪", 23, 32);*/
	// HexDump(NULL, 0, 16);
	//HexDump("", 0, 16);
	// HexDump("", 1, 16);
	
	// HexDump("test", 5, 16);
	/*unsigned uval = 0x12345678;
	HexDump(&uval, 4, 16);*/
	
	/*unsigned char vals[10] = {0x12, 0x34, 0x56, 0x78, 0x90, 0x9, 0x87, 0x65, 0x43, 0x21};
	HexDump(vals, 10, 16);*/
	
	/*void* data = 0x40000;
	HexDump(data, 64, 16);*/
	
	/*HexDump(&argc, 64, 16);
	
	int val;
	HexDump(&val, 64, 16);*/
	
	/*const int val2 = 123;
	int* ptr = &val2;
	HexDump(ptr, 4, 16);
	*ptr = 127;
	HexDump(ptr, 4, 16);*/
	
	//VirtualProtectEx(GetCurrentProcess(), 0, 100, PAGE_READWRITE, NULL);
	HexDump(0, 100, 16);
	
	return 0;
}
