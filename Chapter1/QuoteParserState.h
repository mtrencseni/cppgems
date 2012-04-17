#ifndef QUOTEPARSERSTATE_H
#define QUOTEPARSERSTATE_H

#include <string>

class QuoteParserState
{
public:
        virtual ~QuoteParserState () {}

        virtual QuoteParserState*   OnChar(std::string& s, char c) { return this; }
        virtual QuoteParserState*   OnQuote(std::string& s) { return this; }
        static QuoteParserState*    Reset() { return out; }

protected:
        static QuoteParserState* in;
        static QuoteParserState* out;
};

#endif
