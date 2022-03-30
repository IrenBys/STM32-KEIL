#ifndef _TYPE_H_
#define _TYPE_H_
//--------------------------------------------------------------------------------------------------------------
#ifndef FALSE
 #define FALSE 0
#endif
#ifndef TRUE
 #define TRUE 1
#endif

typedef unsigned char BOOL;
//--------------------------------------------------------------------------------------------------------------
// THE 8-bit DATA
// The 8-bit signed data type.
typedef char int8;
typedef char CHAR;
typedef const char CCHAR;
typedef CHAR* pCHAR;
// The 8-bit unsigned data type.
typedef unsigned char uint8;
typedef unsigned char UCHAR;
typedef const unsigned char CUCHAR;
typedef UCHAR* pUCHAR;
//--------------------------------------------------------------------------------------------------------
// THE 16-bit DATA
// The 16-bit signed data type.
typedef short int16;
typedef short INT;
// The 16-bit unsigned data type.
typedef unsigned short uint16;
typedef unsigned short UINT;
typedef UINT* pUINT;
//--------------------------------------------------------------------------------------------------------------
// THE 32-bit DATA
// The 32-bit signed data type.
typedef long int32;
typedef long LONG;
// The 32-bit unsigned data type.
typedef unsigned long uint32;
typedef unsigned long ULONG;
typedef ULONG* pULONG;


#endif // _TYPE_H_
