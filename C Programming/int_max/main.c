#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
	printf("CHAR_BIT   = %16llx %20lld\n",   CHAR_BIT,   CHAR_BIT); // 輸出   CHAR_BIT 的 10 進位與 16 進位
	printf("SCHAR_MIN  = %16llx %20d\n"  ,  SCHAR_MIN,  SCHAR_MIN); // 輸出  SCHAR_MIN 的 10 進位與 16 進位
	printf("SCHAR_MAX  = %16llx %20lld\n",  SCHAR_MAX,  SCHAR_MAX); // 輸出  SCHAR_MAX 的 10 進位與 16 進位
	printf("UCHAR_MAX  = %16llx %20lld\n",  UCHAR_MAX,  UCHAR_MAX); // 輸出  UCHAR_MAX 的 10 進位與 16 進位
	printf("CHAR_MIN   = %16llx %20d\n"  ,   CHAR_MIN,   CHAR_MIN); // 輸出   CHAR_MIN 的 10 進位與 16 進位
	printf("CHAR_MAX   = %16llx %20lld\n",   CHAR_MAX,   CHAR_MAX); // 輸出   CHAR_MAX 的 10 進位與 16 進位
	printf("MB_LEN_MAX = %16llx %20lld\n", MB_LEN_MAX, MB_LEN_MAX); // 輸出 MB_LEN_MAX 的 10 進位與 16 進位
	printf("SHRT_MIN   = %16llx %20hd\n" ,   SHRT_MIN,   SHRT_MIN); // 輸出   SHRT_MIN 的 10 進位與 16 進位
	printf("SHRT_MAX   = %16llx %20lld\n",   SHRT_MAX,   SHRT_MAX); // 輸出   SHRT_MAX 的 10 進位與 16 進位
	printf("USHRT_MAX  = %16llx %20lld\n",  USHRT_MAX,  USHRT_MAX); // 輸出  USHRT_MAX 的 10 進位與 16 進位
	printf("INT_MIN    = %16llx %20d\n"  ,    INT_MIN,    INT_MIN); // 輸出    INT_MIN 的 10 進位與 16 進位
	printf("INT_MAX    = %16llx %20lld\n",    INT_MAX,    INT_MAX); // 輸出    INT_MAX 的 10 進位與 16 進位
	printf("UINT_MAX   = %16llx %20lld\n",   UINT_MAX,   UINT_MAX); // 輸出   UINT_MAX 的 10 進位與 16 進位
	printf("LONG_MIN   = %16llx %20ld\n" ,   LONG_MIN,   LONG_MIN); // 輸出   LONG_MIN 的 10 進位與 16 進位
	printf("LONG_MAX   = %16llx %20lld\n",   LONG_MAX,   LONG_MAX); // 輸出   LONG_MAX 的 10 進位與 16 進位
	printf("ULONG_MAX  = %16llx %20lld\n",  ULONG_MAX,  ULONG_MAX); // 輸出  ULONG_MAX 的 10 進位與 16 進位
	printf("LLONG_MIN  = %16llx %20lld\n",  LLONG_MIN,  LLONG_MIN); // 輸出  LLONG_MIN 的 10 進位與 16 進位
	printf("LLONG_MAX  = %16llx %20lld\n",  LLONG_MAX,  LLONG_MAX); // 輸出  LLONG_MAX 的 10 進位與 16 進位
	printf("ULLONG_MAX = %16llx %20llu\n", ULLONG_MAX, ULLONG_MAX); // 輸出 ULLONG_MAX 的 10 進位與 16 進位
	return 0;
}
