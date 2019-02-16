#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]) {
	unsigned num = 0;
	char snum[33] = "";
	
	printf("Input A Number: ");
	scanf("%u", &num);
	
	printf("dec: %u\n", num);
	GetBaseNumber(num, 2, snum, 32);
	printf("bin: %s\n", snum);
	GetBaseNumber(num, 8, snum, 11);
	printf("oct: %s\n", snum);
	GetBaseNumber(num, 16, snum, 8);
	printf("hex: %s\n", snum);
	return 0;
}
