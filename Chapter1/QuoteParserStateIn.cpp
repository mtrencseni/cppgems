#include "QuoteParserStateIn.h"
#include <iostream>

QuoteParserState* QuoteParserStateIn::OnChar(std::string& s, char c)
{
        s += c;
        return this;
}

QuoteParserState* QuoteParserStateIn::OnQuote(std::string& s)
{
        std::cout << s << std::endl;
        return out;
}
