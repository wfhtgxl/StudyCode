#include"SeqStack.h"
typedef struct PERSON {
	int age;
}Person;

int main() {
	//´´½¨Õ»
	SeqStack* stack = Init_SeqStack();

	Person p1 = { 1 };
	Person p2 = { 2 };
	Person p3 = { 3 };
	Person p4 = { 4 };
	Person p5 = { 5 };

	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);
	Push_SeqStack(stack, &p4);
	Push_SeqStack(stack, &p5);

	while (Size_SeqStack(stack) > 0) {
		Person* person = (Person*)Top_SeqStack(stack);
		cout << person->age;
		Pop_SeqStack(stack);
	}

	FreeSpace_SeqStack(stack);
}