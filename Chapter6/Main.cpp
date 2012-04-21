#include "String.h"

/*

 Based on More C++ Gems Chapter 6 by James O. Coplien.
 Typed up and sanified by Marton Trencseni (mtrencseni@gmail.com).
 
 */
 
int main()
{
    String a("hello world");
    String b = a;
    String c;
    c = b;
    c = "foo bar";    
}