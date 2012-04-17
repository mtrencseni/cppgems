#include "QuoteParser.h"
#include <iostream>

int main ()
{
    char c;
    QuoteParser parser;

    while (std::cin.get(c))
        parser.OnRead(c);
}
