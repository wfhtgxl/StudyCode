#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Stack.hpp"
using namespace std;
bool testBalanceBrackets(const char* text, bool StackType, int maxDeep = 30);
int main() {
	const char* text00 = " ok ";
	cout << text00 << ": " << (testBalanceBrackets(text00, 0) ? "right" : "wrong") << endl;
	const char* text01 = "( ) ok ";
	cout << text01 << ": " << (testBalanceBrackets(text01, 0) ? "right" : "wrong") << endl;
	const char* text02 = "( ( [] ) ) ok ";
	cout << text02 << ": " << (testBalanceBrackets(text02, 0) ? "right" : "wrong") << endl;
	const char* text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) OK";
	cout << text03 << ": " << (testBalanceBrackets(text03, 0) ? "right" : "wrong") << endl;
	const char* text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
	cout << text04 << ": " << (testBalanceBrackets(text04, 0) ? "right" : "wrong") << endl;
	const char* text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
	cout << text05 << ": " << (testBalanceBrackets(text05, 0) ? "right" : "wrong") << endl;
	const char* text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
	cout << text06 << ": " << (testBalanceBrackets(text06, 0) ? "right" : "wrong") << endl;
	cout << endl;
	cout << text00 << ": " << (testBalanceBrackets(text00, 1) ? "right" : "wrong") << endl;
	cout << text01 << ": " << (testBalanceBrackets(text01, 1) ? "right" : "wrong") << endl;
	cout << text02 << ": " << (testBalanceBrackets(text02, 1) ? "right" : "wrong") << endl;
	cout << text03 << ": " << (testBalanceBrackets(text03, 1) ? "right" : "wrong") << endl;
	cout << text04 << ": " << (testBalanceBrackets(text04, 1) ? "right" : "wrong") << endl;
	cout << text05 << ": " << (testBalanceBrackets(text05, 1) ? "right" : "wrong") << endl;
	cout << text06 << ": " << (testBalanceBrackets(text06, 1) ? "right" : "wrong") << endl;
	return 0;
}

bool testBalanceBrackets(const char* text, bool StackType, int maxDeep) {
	Stack<char>* stack;
	if (StackType) stack = new StackLinkedList<char>;
	else stack = new StackArray<char>(maxDeep);
	bool isBalanceBrackets = true;
	try {
		char cText = '\0';
		for (int i = 0; ((cText = text[i]) != '\0') && (isBalanceBrackets == true); i++) {
		 	switch (cText) {
			case '(': case '[': case '{':
				stack->push(cText);
				break;
			case ')':
				if (stack->pop() != '(') {
					isBalanceBrackets = false;
				}
				break;
			case ']':
				if (stack->pop() != '[') {
					isBalanceBrackets = false;
				}
				break;
			case '}':
				if (stack->pop() != '{') {
					isBalanceBrackets = false;
				}
				break;
			}
		}
		isBalanceBrackets = isBalanceBrackets && stack->isEmpty();
	}
	catch (StackUnderflow) {
		isBalanceBrackets = false;
	}
	catch (StackOverflow) {
		isBalanceBrackets = false;
	}
	delete stack;
	return isBalanceBrackets;
}