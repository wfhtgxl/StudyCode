#include<iostream>
using namespace std;

class Caculator 
	{ 
	public:  
	void setA(int a) {
	this->mA = a; 
	}  
	void setB(int b) { 
	this->mB = b; 
	}  
	void setOperator(string oper) {
	this->mOperator = oper; 
	}  
	int getResult() { 
	if (this->mOperator == "+") { 
	return mA + mB; } else if (
	this->mOperator == "-"
	) { return mA - mB; } 
	else if (this->mOperator == "*") { return mA * mB; } else if (this->mOperator == "/") { return mA / mB; } } private:  int mA;  int mB;  string mOperator; };