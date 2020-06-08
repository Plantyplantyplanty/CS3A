#include "Tokenizer.h"

Tokenizer::Tokenizer() {}

//Use functions to check values, don't brute force it
Queue<Token*> Tokenizer::getTokens(const string& equation) {
	int i = 0; //where we are in the string
	Queue<Token*> to_return;
	while (equation.size() > i) {
		/*NUMBER CASE*/
		if (isdigit(equation[i]) || equation[i] == '.') {
			double num = number_case(equation, i); //Gets the full number, returns it
			to_return.push(new Number(num));
		}
		/*SPACE/NEWLINE CASE*/
		else if (equation[i] == ' ' || equation[i] == '\n' || equation[i] == ',') {
			i++;
		}
		/*UNARY OPERATOR*/
		else if (equation[i] == '-' && (i == 0 || equation[i-1] == '(' || equation[i - 1] == '+' || equation[i - 1] == '-' || equation[i - 1] == '/' || equation[i - 1] == '*' || equation[i - 1] == '^')) {
				to_return.push(new Number(-1));
				to_return.push(new Operator("*"));
				i++;
		}
		/*OPERATOR CASE*/ //is there a function for this if? Because I feel like there isn't 
		else if (equation[i] == '+' || equation[i] == '-' || equation[i] == '/' || equation[i] == '*' || equation[i] == '^') {
			string substring = "";
			substring += equation[i];
			to_return.push(new Operator(substring));
			i++;
		}
		/*VARIABLE CASE, goes off before the function case, so grabs x before it can get to it*/
		else if (equation[i] == 'x') {
			to_return.push(new Variable());
			i++;
		}
		else if (equation[i] == 'e') {
			if (equation.size() > (i + 1) && equation[i + 1] == '^') {
				to_return.push(new Function("e^"));
				i += 2;
			}
		}
		/*FUNCTION CASE*/
		else if (isalpha(equation[i])) {
			string substring = function_case(equation, i);
			to_return.push(new Function(substring));
		}
		/*PARENTHESIS CASES*/
		else if (equation[i] == '(') {
			to_return.push(new LeftParen());
			i++;
		}
		else if (equation[i] == ')') {
			to_return.push(new RightParen());
			i++;
		}
		else {
			assert(0 && "INVALID TEXT ENTERED");
		}
	}
	return to_return;
}

Queue<Token*> Tokenizer::operator()(const string& equation) {
	return getTokens(equation);
}

double Tokenizer::number_case(const string& equation, int& i) {
	string substring = "";
	
	//Get the entire number, including decimals, as a string
	while ((equation.size() > i) && ((isdigit(equation[i])) || equation[i] == '.')) {
		substring += equation[i];
		i++;
	}
	//Turn it into a double
	return std::stod(substring);
}

string Tokenizer::function_case(const string& equation, int& i) {
	string substring = "";
	while ((equation.size() > i) && (isalpha(equation[i]))){
		substring += equation[i];
		i++;
	}
	return substring;
}
Tokenizer::~Tokenizer() {
	while (_input.size() > 0) {
		delete _input.pop();
	}
}