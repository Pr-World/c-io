#ifndef IO_H_INCL
#define IO_H_INCL
#ifndef IO_OUTPUT_TOK
#define IO_OUTPUT_TOK '$'
#endif
#ifndef IO_INPUT_TOK
#define IO_INPUT_TOK '%'
#endif
#ifndef IO_DEF_STR_SPACE
#define IO_DEF_STR_SPACE 0
#endif

#include<stdarg.h>

void vio(const char*, char mode, va_list);
void print(const char*, ...);
void io(const char*, ...);

#endif