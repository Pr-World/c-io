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
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/* ---- Format Specifier ---- [ default ]
change the '$' if you have customized it!

 ==  ==  For Output  ==  == 
	- $i : integer
	- $c : charachter
	- $f : float
	- $d : double
	- $.nf : prints n number of points after main value [ float ] ( n needs to be 0-9 )
	- $.nd : prints n number of points after main value [ double ] ( n needs to be 0-9 )
	- $u : unsigned integer
	- $p : pointers
	- $x : hexadecimal conversion from int
	- $li : long
	- $lu : long unsigned
	- $ll : long long
	- $LL : long long unsigned
	- $s : string

change the '%' if you have customized it!
 ==  ==  For input  ==  == 
	- %i : integer
	- %c : charachter
	- %f : float
	- %d : double
	- %u : unsigned integer
	- %li : long int
	- %lu : long unsigned [int]
	- %ll : long long [int]
	- %lL : long long unsigned [int]
	- %s : string
*/

// main input output
void vio(const char* fmt, char mode, va_list va){
	size_t i;
	for (i = 0; i < strlen(fmt); i++)
	{
		char cch = fmt[i];
		// if mode == 0 [means input and output both]
		if (!mode)
		{
		// if input token is the current charachter
		if (cch == IO_INPUT_TOK){
			char cch2 = fmt[i+1];
			i+=1;
			// process based on input format specifier
			if (cch2 == 'i' || cch2 == 'I'){
				int* iptr = va_arg(va,int*);
				scanf("%d",iptr);
			}else if (cch2 == 'c' || cch2 == 'C'){
				char* cptr = va_arg(va,char*);
				scanf("%c",cptr);
			}else if (cch2 == 'f' || cch2 == 'F'){
				float* fptr = va_arg(va,float*);
				scanf("%f",fptr);
			}else if (cch2 == 'd' || cch2 == 'D'){
				double* dptr = va_arg(va,double*);
				scanf("%lf",dptr);
			}else if (cch2 == 'u'){
				unsigned int* uptr = va_arg(va,unsigned int*);
				scanf("%u",uptr);
			}else if (cch2 == 'l' || cch2 == 'L'){
				char cch3 = fmt[i];
				i+=1;
				if (cch3 == 'i' || cch3 == 'I')
				{
					long int* li = va_arg(va,long int*);
					scanf("%li",li);
				}else if (cch3 == 'l'){
					long long int* l = va_arg(va,long long int*);
					scanf("%lli",l);
				}else if (cch3 == 'L'){
					long long unsigned int* l = va_arg(va,long long unsigned int*);
					scanf("%llu",l);
				}else if (cch3 == 'u'){
					long unsigned int* lu = va_arg(va,long unsigned int*);
					scanf("%lu",lu);
				}else{
					i-=1;
					printf("%c%c%c",IO_INPUT_TOK,cch2,cch3);
				}
			}else if (cch2 == 's'){
				// if string check string is affected by space or not
				// if not [as default] make up the whole input to string
				char* s = va_arg(va,char*);
				if (IO_DEF_STR_SPACE){
					scanf("%s",s);
				}else{
					scanf("%[^\n]s",s);
				}
			// if it's like %% or INPUT_TOK INPUT_TOK just print INPUT_TOK
			}else if (cch2 == IO_INPUT_TOK){
				printf("%c",IO_INPUT_TOK);
				i-=1;
			}
		}
		}
		// check for output token
		if (cch == IO_OUTPUT_TOK){
			char cch2 = fmt[i+1];
			i+=1;
			// everything is pretty simple
			// check what format specifier, printf it
			if (cch2 == 'i' || cch2 == 'I'){
				printf("%d",va_arg(va,int));
			}else if (cch2 == 'c' || cch2 == 'C'){
				printf("%c",va_arg(va,int));
			}else if (cch2 == 'f' || cch2 == 'F'){
				// float print dynamic points!
				// make a string to store result of snprintf, i for loop variable,
				//flt for actual float value, s2 for output string
				
				char s[50]="";
				char s2[50]="";
				size_t i;
				float flt = va_arg(va,double);

				snprintf(s,50,"%f",flt);
				// states that the current isZero is true [ default ]
				int isZero = 1;

				for(i=strlen(s); i>0; i--)
				{
					// if previously it was zero and now its not, make it false!~
					// stripping zero mechanism [ stripps the continuous zero till hitting
					// a non-zero value ]
					if (isZero&&s[i-1] != '0'){
						isZero = 0;
					}

					// if the zeroes are already stripped out or it is the last element,
					// store it in output s2
					if (!isZero || s[i-2] == '.'){
						s2[i-1] = s[i-1];
					}
				}
				// print the output str
				printf("%s",s2);

			}else if (cch2 == 'd' || cch2 == 'D'){
				// double print dynamic points!
				// make a string to store result of snprintf, i for loop variable,
				//flt for actual float value, s2 for output string
				
				char s[50]="";
				char s2[50]="";
				size_t i;
				double dbl = va_arg(va,double);

				snprintf(s,50,"%lf",dbl);
				// states that the current isZero is true [ default ]
				int isZero = 1;

				for(i=strlen(s); i>0; i--)
				{
					// if previously it was zero and now its not, make it false!~
					// stripping zero mechanism [ stripps the continuous zero till hitting
					// a non-zero value ]
					if (isZero&&s[i-1] != '0'){
						isZero = 0;
					}

					// if the zeroes are already stripped out or it is the last element,
					// store it in output s2
					if (!isZero || s[i-2] == '.'){
						s2[i-1] = s[i-1];
					}
				}
				// print the output str
				printf("%s",s2);

			}else if (cch2 == '.'){
				// if its like $.2f or something explicit like $.2d for double
				char cch3 = fmt[i+1];
				// check if the next number is not a number [ we want it to be a number]
				if (cch3>'9' || cch3<'0'){
					printf("%c.",IO_INPUT_TOK);
				}else{
					// if it is a number check that the last one is a 'f' or a 'd'
					char cch4 = fmt[i+2];
					i+=2;
					if (cch4 == 'f')
					{
						// preparation string for float
						char mk[] = "%. f";
						// since the number is in cch3 [ the explicitly point printing num ]
						// assign it so it becomes like %.nf where n is the number
						mk[2] = cch3;

						// use the preparation string to print what's in the argument
						printf(mk,va_arg(va,double));

					}else if (cch4 == 'd'){
						// preparation string for double
						char mk[] = "%. lf";
						// since the number is in cch3 [ the explicitly point printing num ]
						// assign it so it becomes like %.nlf where n is the number
						mk[2] = cch3;

						// use the preparation string to print what's in the argument
						printf(mk,va_arg(va,double));
						
					}else{
						i-=1;
						printf("%c.%c%c",IO_OUTPUT_TOK,cch3,cch4);
					}
				}
			// just check and print it
			}else if (cch2 == 'u' || cch2 == 'U'){
				printf("%u",va_arg(va,unsigned int));
			}else if (cch2 == 'p' || cch2 == 'P'){
				printf("%p",va_arg(va,void*));
			}else if (cch2 == 'x' || cch2 == 'X'){
				printf("%x",va_arg(va,int));
			}else if (cch2 == 's' || cch2 == 'S'){
				printf("%s",va_arg(va,char*));
			}else if (cch2 == 'l' || cch2 == 'L'){
				// if it is in long type
				char cch3 = fmt[i];
				i+=2;
				if (cch3 == 'i' || cch3 == 'I'){
					printf("%li",va_arg(va,long int));
				}else if (cch3 == 'l'){
					printf("%lli",va_arg(va,long long int));
				}else if (cch3 == 'L'){
					printf("%llu",va_arg(va,long long unsigned int));
				}else if (cch3 == 'u'){
					printf("%lu",va_arg(va,long unsigned int));
				}else{
					i-=1;
					printf("%c%c%c",IO_OUTPUT_TOK,cch2,cch3);
				}
			}else if (cch2 == IO_OUTPUT_TOK){
				printf("%c",IO_OUTPUT_TOK);
			}else{
				i-=1;
				printf("%c",IO_OUTPUT_TOK);
			}
		// if its not input token or if the mode states its not input mode,
		// print the charachter whatever it may be
		}else if (cch!=IO_INPUT_TOK||mode){
			printf("%c",cch);
		}
	}
}

// full wrapper for vio
void io(const char* fmt, ...)
{
	va_list va;
	va_start(va,fmt);
	vio(fmt,0,va);
	va_end(va);
}

// print only wrapper for vio
void print(const char* fmt, ...)
{
	va_list va;
	va_start(va,fmt);
	vio(fmt,1,va);
	va_end(va); 
}

#endif