#include"LinkStack.h"

typedef struct PERSON {
	LinkNode node;
	int age;
}Person;

int main() {
	//创建栈
	LinkStack* stack = Init_LinkStack();

	Person p1, p2, p3, p4, p5;//Person p1.age =  { 1 }; xx
	 p1.age = { 1 };
	 p2.age = { 2 };
	 p3.age = { 3 }; 
	 p4.age = { 4 };
	 p5.age = { 5 };
	 //入栈
	Push_LinkStack(stack, (LinkNode*)&p1);//？
	Push_LinkStack(stack, (LinkNode*)&p2);
	Push_LinkStack(stack, (LinkNode*)&p3);
	Push_LinkStack(stack, (LinkNode*)&p4);
	Push_LinkStack(stack, (LinkNode*)&p5);

	while (Size_LinkStack(stack) > 0) {
		Person* person = (Person*)Top_LinkStack(stack);//强转
		cout << person->age;
		Pop_LinkStack(stack);
	}

	FreeSpace_LinkStack(stack);
}