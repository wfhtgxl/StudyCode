#include<iostream>
using namespace std;

class Base 
{
	public:  
		static int getNum() { 
			return sNum; 
		}  
		static int getNum(int param) { 
			return sNum + param; 
		}