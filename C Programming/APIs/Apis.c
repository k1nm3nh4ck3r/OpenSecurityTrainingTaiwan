#include "Apis.h"

void GetBaseNumber(unsigned num, unsigned base, char* snum, unsigned n){
	unsigned i;
	unsigned tmp = num;
	char hexstr[17] = "0123456789ABCDEF";
	
	// get binary
	for(i=0;i<n;i++){
		snum[n-i-1] = hexstr[tmp % base];
		tmp /= base;
	}
	snum[n] = '\0';
}

void HexDump(unsigned char* data, size_t size, int block){
	size_t i, j;
	printf("%19c", ' ');
	for(i=0;i<block;i++)printf("%02X ", i);
	printf("   ");
	for(i=0;i<block;i++)printf("%X", i%16);
	printf("\n");
	for(i=0;i<size;i++){
		if(i%block == 0)printf("%016p | ", &data[i]);
		printf("%02X ", data[i]);
		if((i+1)%block == 0){
			printf("   ");
			for(j=0;j<block;j++)printf("%c", ((data[i-block+1+j] >= 32) && (data[i-block+1+j] <= 126))?data[i-block+1+j]:'.');
			printf("\n");
		}
	}
	if(i%block > 0){
		for(j=0;j<=(block - i%block); j++)printf("   ");
		for(j=0;j<(i%block);j++)printf("%c", ((data[i-i%block+j] >= 32) && (data[i-i%block+j] <= 126))?data[i-i%block+j]:'.');
		printf("\n");
	}
	printf("%016p |\n", &data[size]);
}

void HexDumpEx(unsigned char* data, size_t size, int block, BOOL withhead, BOOL isaddr_offset, BOOL addrprint, BOOL tailprint, BOOL charprint){
	size_t i, j;
	if(withhead){
		printf("%19c", ' ');
		for(i=0;i<block;i++)printf("%02X ", i);
		printf("   ");
		for(i=0;i<block;i++)printf("%X", i%16);
		printf("\n");
	}
	for(i=0;i<size;i++){
		if((i%block == 0) && (addrprint))printf("%016p | ", (isaddr_offset)?(&data[i]):i);
		printf("%02X ", data[i]);
		if((i+1)%block == 0){
			if(charprint){
				printf("   ");
				for(j=0;j<block;j++)printf("%c", ((data[i-block+1+j] >= 32) && (data[i-block+1+j] <= 126))?data[i-block+1+j]:'.');
			}
			printf("\n");
		}
	}
	if(i%block > 0){
		if(charprint){
			for(j=0;j<=(block - i%block); j++)printf("   ");
			for(j=0;j<(i%block);j++)printf("%c", ((data[i-i%block+j] >= 32) && (data[i-i%block+j] <= 126))?data[i-i%block+j]:'.');
		}
		printf("\n");
	}
	if((tailprint) && (addrprint))printf("%016p |\n", (isaddr_offset)?(&data[size]):size);
}

unsigned GetNeedBytesUnknowNumber(void* number_pointer, size_t size, size_t base){
	size_t bits = size * 8;
	size_t bytes = 0;
	size_t log2 = 0;
	size_t tmp = 0;
	
	//printf("base: %u, ", base);
	tmp = base;
	while(tmp != 0){
		// has the number => log2 + 1
		log2++;
		tmp/=2;
	}
	log2--;
	//printf("log2: %u, ", log2);
	bytes = (bits + log2 - 1) / log2; // bits = ceil(bits/base);
	//printf("need bytes: %u\n", bytes);
	
	return bytes;
}

unsigned char* _GetMaxUnknowNumberUnsigned(size_t size){
	unsigned char* mem = NULL;
	size_t i;
	
	mem = (unsigned char*)malloc(sizeof(unsigned char)*size);
	
	if(mem){
		for(i=0;i<size;i++){
			mem[i] = 0xff;
		}
		
		return mem;
	}
	
	return NULL;
}

unsigned char* _GetMaxUnknowNumberSigned(size_t size){
	unsigned char* mem = NULL;
	size_t i;
	
	mem = (unsigned char*)malloc(sizeof(unsigned char)*size);
	
	if(mem) {
		for(i=0;i<(size-1);i++){
			mem[i] = 0xff;
		}
		
		mem[size-1] = 0x7f;
		
		return mem;
	}
	
	return NULL;
}

unsigned char* _GetMinUnknowNumberSigned(size_t size){
	unsigned char* mem = NULL;
	size_t i;
	
	mem = (unsigned char*)malloc(sizeof(unsigned char)*size);
	
	if(mem) {
		for(i=0;i<(size-1);i++){
			mem[i] = 0x00;
		}
		
		mem[size-1] = 0x80;
		
		return mem;
	}
	
	return NULL;
}

