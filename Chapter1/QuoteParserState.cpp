#include "QuoteParserStateIn.h"
#include "QuoteParserStateOut.h"

QuoteParserState* QuoteParserState::in = new QuoteParserStateIn;
QuoteParserState* QuoteParserState::out = new QuoteParserStateOut;
