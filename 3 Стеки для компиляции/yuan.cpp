#include"MyStack.h"
int main(int argc, char* argv[])
{
	while (1)
	{
		cout << "Enter:";

		char* midExp = (char*)malloc(sizeof(char) * EXPRESS_MAX);
		memset(midExp, 0, EXPRESS_MAX);
		fgets(midExp, 1024, stdin);//midExp 包含换行符
		if ('#' == midExp[0])	break;

		//后缀表达式
		char* afterExp = foo(midExp);
		cout << "result:" << afterExp << endl;
	}

	return 0;
}