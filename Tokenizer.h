#define _CRTDBG_MAP_ALLOC
#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "shunting_yard.h"
class Tokenizer{
public:
	Tokenizer();
	Queue<Token*> getTokens(const string& equation);
	Queue<Token*> operator()(const string& equation);
	Queue<Token*> return_Tokens() { return _input; }
	~Tokenizer();
private:
	string function_case(const string& equation, int& i);
	double number_case(const string & equation, int &i);
	Queue<Token*> _input;
};
#endif
