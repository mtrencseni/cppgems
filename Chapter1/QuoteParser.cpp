#include "QuoteParser.h"
#include "QuoteParserState.h"

void QuoteParser::OnRead(char c)
{
        if (c == '"')
                state = state->OnQuote(buffer);
        else
                state = state->OnChar(buffer, c);
}

QuoteParser::QuoteParser ()
{
        state = QuoteParserState::Reset();
}
