#ifndef _APIS_H_
#define _APIS_H_

#include <stdio.h>
#include <stdlib.h>

#ifndef BOOL
#define BOOL int
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif


// used must be free
#define GetMaxUnknowNumberUnsigned(type) (type *)_GetMaxUnknowNumberUnsigned(sizeof(type))
#define GetMaxUnknowNumberSigned(type) (type *)_GetMaxUnknowNumberSigned(sizeof(type))
#define GetMinUnknowNumberSigned(type) (type *)_GetMinUnknowNumberSigned(sizeof(type))

unsigned GetNeedBytesUnknowNumber(void* number_pointer, size_t size, size_t base);
void GetBaseNumber(unsigned num, unsigned base, char* snum, unsigned n);
void HexDump(unsigned char* data, size_t size, int block);
void HexDumpEx(unsigned char* data, size_t size, int block, BOOL withhead, BOOL isaddr_offset, BOOL addrprint, BOOL tailprint, BOOL charprint);

#endif // _APIS_H_
