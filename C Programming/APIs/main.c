#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Apis.h"

void TestMinMax(){
	int num = 0;
	
	printf("%090d\n",0);
	
	printf("Type Min Max\n");
	printf("%090d\n",0);
	
	printf("[o] signed type:\n");
	
	char* pcnum = GetMaxUnknowNumberSigned(char);
	printf("max(char)      = %20hhd ", *pcnum);
	(*pcnum)++; 
	printf("=>  overflow of char      = %20hhd\n", *pcnum);
	free(pcnum);
	
	pcnum = GetMinUnknowNumberSigned(char);
	printf("min(char)      = %20hhd ", *pcnum);
	(*pcnum)--; 
	printf("=> underflow of char      = %20hhd\n", *pcnum);
	free(pcnum);
	
	short* psnum = GetMaxUnknowNumberSigned(short);
	printf("max(short)     = %20hd ", *psnum);
	(*psnum)++; 
	printf("=>  overflow of short     = %20hd\n", *psnum);
	free(psnum);
	
	psnum = GetMinUnknowNumberSigned(short);
	printf("min(short)     = %20hd ", *psnum);
	(*psnum)--; 
	printf("=> underflow of short     = %20hd\n", *psnum);
	free(psnum);
	
	int* pinum = GetMaxUnknowNumberSigned(int);
	printf("max(int)       = %20d ", *pinum);
	(*pinum)++; 
	printf("=>  overflow of int       = %20d\n", *pinum);
	free(pinum);
	
	pinum = GetMinUnknowNumberSigned(int);
	printf("min(int)       = %20d ", *pinum);
	(*pinum)--; 
	printf("=> underflow of int       = %20d\n", *pinum);
	free(pinum);
	
	long* plnum = GetMaxUnknowNumberSigned(long);
	printf("max(long)      = %20ld ", *plnum);
	(*plnum)++; 
	printf("=>  overflow of long      = %20ld\n", *plnum);
	free(plnum);
	
	plnum = GetMinUnknowNumberSigned(long);
	printf("min(long)      = %20ld ", *plnum);
	(*plnum)--;
	printf("=> underflow of long      = %20ld\n", *plnum);
	free(plnum);
	
	long long* pllnum = GetMaxUnknowNumberSigned(long long);
	printf("max(long long) = %20lld ", *pllnum);
	(*pllnum)++; 
	printf("=>  overflow of long long = %20lld\n", *pllnum);
	free(pllnum);
	
	pllnum = GetMinUnknowNumberSigned(long long);
	printf("min(long long) = %20lld ", *pllnum);
	(*pllnum)--; 
	printf("=> underflow of long long = %20lld\n", *pllnum);
	free(pllnum);
	
	printf("\n[o] unsigned type:\n");
	
	unsigned char* pucnum = GetMaxUnknowNumberUnsigned(unsigned char);
	printf("max(unsigned char) = %hhu\n", *pucnum);
	free(pucnum);
	
	unsigned short* pusnum = GetMaxUnknowNumberUnsigned(unsigned short);
	printf("max(unsigned short) = %hu\n", *pusnum);
	free(pusnum);
	
	unsigned* punum = GetMaxUnknowNumberUnsigned(unsigned);
	printf("max(unsigned) = %u\n", *punum);
	free(punum);
	
	unsigned long* pulnum = GetMaxUnknowNumberUnsigned(unsigned long);
	printf("max(unsigned long) = %lu\n", *pulnum);
	free(pulnum);
	
	unsigned long long* pullnum = GetMaxUnknowNumberUnsigned(unsigned long long);
	printf("max(unsigned long long) = %llu\n", *pullnum);
	free(pullnum);
	
	printf("%090d\n",0);
}

void TestFloatingPoint(){
	float fnum = 0.0;
	
	fnum = 1.024;
	printf("fnum(%.10f) dump = ", fnum);
	HexDumpEx(&fnum, sizeof(float), 16, FALSE, FALSE, FALSE, FALSE, FALSE);
	printf("binary = ");
	GetBaseNumber();
}

int main(int argc, char *argv[]) {
	TestMinMax();
	TestFloatingPoint();
	
	
	return 0;
}
