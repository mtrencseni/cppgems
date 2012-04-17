#include "QuoteParserStateOut.h"

QuoteParserState* QuoteParserStateOut::OnQuote(std::string& s)
{
        s.clear();
        return in;
}
