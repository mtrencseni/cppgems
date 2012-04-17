#ifndef QUOTEPARSER_H
#define QUOTEPARSER_H

#include <string>

class QuoteParserState;

class QuoteParser
{
public:
        QuoteParser();

        virtual void OnRead(char c);

protected:
        QuoteParserState*   state;
        std::string         buffer;
};

#endif
