#include"MyStack.h"
int main(int argc, char* argv[])
{
	while (1)
	{
		cout << "Enter:";

		char* midExp = (char*)malloc(sizeof(char) * EXPRESS_MAX);
		memset(midExp, 0, EXPRESS_MAX);
		fgets(midExp, 1024, stdin);//midExp �������з�
		if ('#' == midExp[0])	break;

		//��׺���ʽ
		char* afterExp = foo(midExp);
		cout << "result:" << afterExp << endl;
	}

	return 0;
}