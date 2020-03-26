#ifndef Stack_hpp
#define Stack_hpp

#include <exception>

class StackOverflow :public std::exception {
public:
	StackOverflow() :
		reason("Stack Overflow")
	{}
	const char* what()const {
		return reason;
	}
private:
	const char* reason;
};

class StackUnderflow :public std::exception {
public:
	StackUnderflow() :
		reason("Stack Underflow")
	{}
	const char* what()const {
		return reason;
	}
private:
	const char* reason;
};

class WrongStackSize :public std::exception {
public:
	WrongStackSize() :
		reason("Wrong Stack Size")
	{}
	const char* what()const {
		return reason;
	}
private:
	const char* reason;
};

template <class T> class Stack {
public:
	virtual ~Stack() {}
	virtual void push(const T& e) = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
};

template <class T>
class StackArray :public Stack<T> {
public:
	StackArray(const int& = 100);
	StackArray(const StackArray<T>&);
	~StackArray() { delete[] array_; }
	void push(const T&);
	T pop();
	bool isEmpty() { return top_ == 0; }
private:
	T* array_;
	int top_ = 0;
	int size_;
};

template <class T>
StackArray<T>::StackArray(const int& size) {
	try {
		array_ = new T[size_ = size];
	}
	catch (const std::bad_alloc & e) {
		throw WrongStackSize();
	}
}

template <class T>
StackArray<T>::StackArray(const StackArray<T>& src) {
	try {
		array_ = new T[size_ = src.size_];
	}
	catch (const std::bad_alloc & e) {
		throw WrongStackSize();
	}
	for (int i = 0; i < src.top_; i++) {
		array_[i] = src.array_[i];
	}
	top_ = src.top_;
}

template <class T>
void StackArray<T>::push(const T& Data) {
	if (top_ == size_) {
		throw StackOverflow();
	}
	array_[top_] = Data;
	top_++;
}

template <class T>
T StackArray<T>::pop() {
	if (top_ == 0) {
		throw StackUnderflow();
	}
	return array_[--top_];
}

//-----------------------------------------------------------

template <class T>
struct StackNode {
	T Data_;
	StackNode* Next_;
	StackNode(const T& Data) :
		Data_(Data),
		Next_(nullptr)
	{}
};

template <class T>
class StackLinkedList :public Stack<T> {
private:
	StackNode<T>* LinkedList_;
public:
	StackLinkedList():
		LinkedList_(nullptr)
	{}
	~StackLinkedList() {
		StackNode<T>* mark;
		while (LinkedList_) {
			mark = LinkedList_->Next_;
			delete LinkedList_;
			LinkedList_ = mark;
		}

	}
	void push(const T& Data) {
		StackNode<T>* tmp = new StackNode<T>(Data);
		tmp->Next_ = LinkedList_;
		LinkedList_ = tmp;
	}
	T pop() {
		if (!LinkedList_) {
			throw StackOverflow();
		}
		StackNode<T>* tmp = LinkedList_;
		T popData = LinkedList_->Data_;
		LinkedList_ = LinkedList_->Next_;
		delete tmp;
		return popData;
	}
	bool isEmpty() { return LinkedList_ == nullptr; }
};


#endif