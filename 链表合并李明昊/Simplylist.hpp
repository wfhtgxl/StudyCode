#ifndef simplylist_hpp
#define simplylist_hpp

#include<iostream>

using namespace std;

struct node {
	node* next_;
	int data_;
	node(const int& data = 0) :
		next_(nullptr),
		data_(data)
	{}
};

class Simplylist {
private:
	node* head_;
public:
	Simplylist() :
		head_(nullptr)
	{}
	Simplylist(Simplylist&& obj) noexcept :
		head_(obj.head_)
	{
		obj.head_ = nullptr;
	}

	Simplylist(const Simplylist& list) :head_(nullptr) {
		if (list.head_) {
			head_ = new node(list .head_->data_);
			node* trav = list.head_->next_;
			node* tmp = head_;
			while (trav) {
				tmp->next_ = new node(trav->data_);
				tmp = tmp->next_;
				trav = trav->next_;
			}
		}
	}

	~Simplylist() {
		node* mark;
		while (head_) {
			mark = head_->next_;
			delete head_;
			head_ = mark;
		}
	}

	const Simplylist& operator=(Simplylist&& data)noexcept {
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
		node* trav = head_;
		while (trav) {
			if (trav->data_ >= data) {
				node* tmp = new node(data);
				tmp->next_ = head_;
				head_ = tmp;
				return;
			}
			else {
				node* tmp = new node(data);
				tmp->next_ = trav;
				head_ = tmp;
			}
			trav = trav->next_;
		}
	}
	bool operator==(const Simplylist& list) {
		node* trav = head_;
		node* trav2 = list .head_;
		while (trav) {
			if (!trav2) {
				return false;
			}
			else if (trav->data_ != trav2->data_) {
				return false;
			}
			trav = trav->next_;
			trav2 = trav2->next_;
		}
		if (trav2) {
			return false;
		}
		else {
			return true;
		}
	}
	friend ostream& operator<<(ostream& out, const Simplylist& list) {
		node* trav = list.head_;
		while (trav) {
			out << trav->data_ << " ";
			trav = trav->next_;
		}
		out << endl;
		return out;
	}
	friend Simplylist operator&(Simplylist& l, Simplylist r) {
		Simplylist list;
		node* trav1 = l.head_;
		node* trav2 = r.head_;
		while (trav1 && trav2) {
			if (trav1->data_ == trav2->data_) {
				list += trav1->data_;
				trav1 = trav1->next_;
				trav2 = trav2->next_;
			}
			else if (trav1->data_ > trav2->data_) {
				list += trav2->data_;
				trav2 = trav2->next_;
			}
			else if (trav1->data_ < trav2->data_) {
				list += trav1->data_;
				trav1 = trav1->next_;
			}
		}
		while (trav1) {
			list += trav1->data_;
			trav1 = trav1->next_;
		}
		while (trav2) {
			list += trav2->data_;
			trav2 = trav2->next_;
		}
		return list;
	}
	friend Simplylist operator|(Simplylist& l, Simplylist r) {
		Simplylist list;
		node* trav1 = l.head_;
		node* trav2 = r.head_;
		while (trav1 && trav2) {
			if (trav1->data_ == trav2->data_) {
				list += trav1->data_;
				trav1 = trav1->next_;
				trav2 = trav2->next_;
			}
			else if (trav1->data_ > trav2->data_) {
				trav2 = trav2->next_;
			}
			else if (trav1->data_ < trav2->data_) {
				trav1 = trav1->next_;
			}
		}
		return list;
	}
	void merge(Simplylist& list) {
		node* trav = list.head_;
		while (trav) {
			*this += trav->data_;
			trav = trav->next_;
		}
		while (list.head_) {
			list.head_ = list.head_->next_;
		}
	}

};

#endif