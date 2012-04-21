#include "QuoteParser.h"
#include <iostream>

/*

 Based on More C++ Gems Chapter 1 by Immo Huneke.
 Typed up and sanified by Marton Trencseni (mtrencseni@gmail.com).
 
 */

int main ()
{
    char c;
    QuoteParser parser;

    while (std::cin.get(c))
        parser.OnRead(c);
}
