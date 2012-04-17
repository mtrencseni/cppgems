#ifndef QUOTEPARSERSTATEIN_H
#define QUOTEPARSERSTATEIN_H

#include "QuoteParserState.h"

class QuoteParserStateIn : public QuoteParserState
{

public:
        virtual QuoteParserState* OnChar(std::string& s, char c);
        virtual QuoteParserState* OnQuote(std::string& s);
};

#endif
