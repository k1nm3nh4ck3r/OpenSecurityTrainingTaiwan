#include <stdio.h>
#include <stdlib.h>

void PrintBCD(unsigned long long ullValue){
	unsigned long long value1 = ullValue%10000000000;
	unsigned long long value2 = ullValue/10000000000;
	//printf("Number Beyond: %llu %llX\n", value1, value1);
	//printf("Number Below: %llu %llX\n", value2, value2);
	//printf("Number Beyond: %llu %llX\n", value1, value1);
	//printf("Number Below: %llu %llX\n", value2, value2);
	unsigned long long value1bcd = 0;
	unsigned long long value2bcd = 0;
	
	unsigned long long base = 0;
	
	// convert bcd of value1
	base = 1;
	while(value1!=0){
		value1bcd += (value1 % 10)*base;
		value1 = value1 / 10;
		base *= 16;
	}
	
	base = 1;
	while(value2!=0){
		value2bcd += (value2 % 10)*base;
		value2 = value2 / 10;
		base *= 16;
	}
	
	
	printf("0x%010llX", value2bcd);
	printf("%010llX\n", value1bcd);
}

int main(int argc, char *argv[]) {
	unsigned long long ullValue = 18446744073709551615;
	
	printf("Input A Number: ");
	scanf("%llu", &ullValue);
	
	//printf("Number = %llu 0x%llX\n", ullValue, ullValue);
	
	PrintBCD(ullValue);
	return 0;
}
