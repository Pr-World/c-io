// -====================== NOTE ==========================-
// format specifiers to be customized before including io.h

// #define IO_INPUT_TOK '%' // uncomment and change the '%' to your own token
// #define IO_OUTPUT_TOK '$' // uncomment and change the '$' to your own token

#include "io.h"

/* ---- Format Specifiers ---- [ default ]
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

int main()
{
    double a, b;
    // $i maps to -> 1, %d maps to -> &a, $i maps to -> 2, %d maps to -> &b
    io("Num $i: %dNum $i: %d", 1, &a, 2, &b);
    // $d maps to -> a+b
    io("Sum is: $d\n",a+b); //or print("Sum is : $d\n",a+b);
    return 0;
}