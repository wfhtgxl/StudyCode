#include "±êÍ·.h"

IntStack::IntStack(int capacity)
{
	stackArray = make_unique<int[]>(capacity);
	this->capacity = capacity;
	top = 0;
}

void IntStack::push(int value)
{
	if (top == capacity)
		throw IntStack::Overflow();
	stackArray[top] = value;
	top++;
}

bool IntStack::isEmpty() const
{
	return top == 0;
}

void IntStack::pop(int& value)
{
	if (isEmpty()) throw IntStack::Underflow();
	top--;
	value = stackArray[top];
}

class Overflow {
public:
	Overflow(){
		cout << "Òç³ö";
	}
};

int main()
{
	IntStack stack(5);
	int values[] = { 5, 10, 15, 20, 25, 30};
	int value;
	cout << "Pushing \n";
	for (int k = 0; k < 6; k++)
	{
		cout << values[k] << " ";
		stack.push(values[k]);
	}
	cout << "\nPopping\n";
	while (!stack.isEmpty())
	{
		stack.pop(value);
		cout << value << " ";
	}
	cout << endl;
	return 0;
}