#ifndef QUOTEPARSERSTATEOUT
#define QUOTEPARSERSTATEOUT

#include "QuoteParserState.h"

class QuoteParserStateOut : public QuoteParserState
{
public:
        virtual QuoteParserState* OnQuote(std::string& s);
};

#endif
