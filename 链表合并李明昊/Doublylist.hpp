#ifndef doublylist_hpp
#define doublylist_hpp
#include<iostream>
using namespace std;

class Doublylist {
private:
	struct node {
		node* next_;
		node* prev_;
		int data_;
		node(const int& data = 0) :
			next_(nullptr),
			prev_(nullptr),
			data_(data)
		{}
	};
	node* head_;
public:
	Doublylist() :
		head_(nullptr)
	{}
	Doublylist(Doublylist&& obj) noexcept :
		head_(obj.head_)
	{
		obj.head_ = nullptr;
	}

	Doublylist(const Doublylist& list) :head_(nullptr) {
		if (list.head_) {
			head_ = new node(list.head_->data_);
			node* pCurrent= list.head_->next_;
			node* tmp = head_;
			while (pCurrent) {
				tmp->next_ = new node(pCurrent->data_);
				tmp->next_->prev_ = tmp;
				tmp = tmp->next_;
				pCurrent = pCurrent->next_;
			}
		}
	}

	~Doublylist() {
		node* mark;
		while (head_) {
			mark = head_->next_;
			delete head_;
			head_ = mark;
		}
	}

	const Doublylist& operator=(Doublylist&& data)noexcept {
		node* tmp;
		while (head_) {
			tmp = head_->next_;
			delete head_;
			head_ = tmp;
		}
		head_ = data.head_;
		data.head_ = nullptr;
		return *this;
	}

	void operator+=(const int& data) {
		if (head_ == nullptr) {
			head_ = new node(data);
			return;
		}
		node* pCurrent = head_;
		while (pCurrent) {
			if (pCurrent->data_ == data) {
				return;
			}
			else if (pCurrent->data_ > data) {
				node* tmp = new node(data);
				tmp->next_ = pCurrent;
				if (pCurrent->prev_) {
					tmp->prev_ = pCurrent->prev_;
					pCurrent->prev_->next_ = tmp;
				}
				else {
					head_ = tmp;
				}
				pCurrent->prev_ = tmp;
				return;
			}
			pCurrent = pCurrent->next_;
		}
	}
	bool operator==(const Doublylist& list) {
		node* pCurrent = head_;
		node* pCurrent2 = list .head_;
		while (pCurrent) {
			if (!pCurrent2) {
				return false;
			}
			else if (pCurrent->data_ != pCurrent2->data_) {
				return false;
			}
			pCurrent = pCurrent->next_;
			pCurrent2 = pCurrent2->next_;
		}
		if (pCurrent2) {
			return false;
		}
		else {
			return true;
		}
	}
	friend ostream& operator<<(ostream& out, const Doublylist& list) {
		node* pCurrent = list.head_;
		while (pCurrent) {
			out << pCurrent->data_ << " ";
			pCurrent = pCurrent->next_;
		}
		out << endl;
		return out;
	}
	friend Doublylist operator&(Doublylist& l, Doublylist r) {
		Doublylist list;
		node* pCurrent1 = l.head_;
		node* pCurrent2 = r.head_;
		while (pCurrent1 && pCurrent2) {
			if (pCurrent1->data_ == pCurrent2->data_) {
				list += pCurrent1->data_;
				pCurrent1 = pCurrent1->next_;
				pCurrent2 = pCurrent2->next_;
			}
			else if (pCurrent1->data_ > pCurrent2->data_) {
				list += pCurrent2->data_;
				pCurrent2 = pCurrent2->next_;
			}
			else if (pCurrent1->data_ < pCurrent2->data_) {
				list += pCurrent1->data_;
				pCurrent1 = pCurrent1->next_;
			}
		}
		while (pCurrent1) {
			list += pCurrent1->data_;
			pCurrent1 = pCurrent1->next_;
		}
		while (pCurrent2) {
			list += pCurrent2->data_;
			pCurrent2 = pCurrent2->next_;
		}
		return list;
	}
	friend Doublylist operator|(Doublylist& l, Doublylist r) {
		Simplylist list;
		node* pCurrent1 = l.head_;
		node* pCurrent2 = r.head_;
		while (pCurrent1 && pCurrent2) {
			if (pCurrent1->data_ == pCurrent2->data_) {
				list += pCurrent1->data_;
				pCurrent1 = pCurrent1->next_;
				pCurrent2 = pCurrent2->next_;
			}
			else if (pCurrent1->data_ > pCurrent2->data_) {
				pCurrent2 = pCurrent2->next_;
			}
			else if (pCurrent1->data_ < pCurrent2->data_) {
				pCurrent1 = pCurrent1->next_;
			}
		}
		return list;
	}
	void merge(Doublylist& list) {
		node* pCurrent = list.head_;
		while (pCurrent) {
			*this += pCurrent->data_;
			pCurrent = pCurrent->next_;
		}
		while (list.head_) {
			list.head_ = list.head_->next_;
		}
	}

};

#endif