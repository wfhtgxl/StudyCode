#ifndef LinkedList_hpp
#define LinkedList_hpp

using namespace std;
#include <iostream>



class LinkList {
private:
	struct LinkNode {
		int Data_;
		LinkNode* next_;
		LinkNode(const int& Data = 0, LinkNode* const next = nullptr) :Data_(Data), next_(next) {}
	};
	LinkNode* head_;
	LinkNode* tail_;
public:
	LinkList() :head_(nullptr), tail_(nullptr) {}
	LinkList(LinkList&& list) noexcept :head_(list.head_), tail_(list.tail_) {
		list.head_ = list.tail_ = nullptr;
	}
	LinkList(const LinkList& list) :head_(nullptr), tail_(nullptr) {
		if (list.head_) {
			head_ = new LinkNode(list.head_->Data_);
			LinkNode* pCurrent = list.head_->next_;
			tail_ = head_;
			while (pCurrent) {
				tail_->next_ = new LinkNode(pCurrent->Data_);
				tail_ = tail_->next_;
				pCurrent = pCurrent->next_;
			}
		}
	}
	~LinkList() {
		while (head_) {
			tail_ = head_->next_;
			delete head_;
			head_ = tail_;
		}
	}
	const LinkList& operator=(LinkList&& list)noexcept {
		while (head_) {
			tail_ = head_->next_;
			delete head_;
			head_ = tail_;
		}
		head_ = list.head_;
		tail_ = list.tail_;
		list.head_ = list.tail_ = nullptr;
		return *this;
	}
	bool operator+=(const int& Data) {
		LinkNode* pCurrent = head_;
		while (pCurrent) {
			if (pCurrent->Data_ == Data) {
				return false;
			} else if (pCurrent->Data_ > Data) {
				LinkNode* node = new LinkNode(Data);
				node->next_ = head_;
				head_ = node;
				return true;
			} else if (pCurrent->Data_ < Data && !pCurrent->next_) {
				tail_->next_ = new LinkNode(Data);
				tail_ = tail_->next_;
				return true;
			} else if (pCurrent->Data_ < Data && pCurrent->next_->Data_ > Data) {
				LinkNode* node = new LinkNode(Data);
				node->next_ = pCurrent->next_;
				pCurrent->next_ = node;
				return true;
			}
			pCurrent = pCurrent->next_;
		}
		head_ = tail_ = new LinkNode(Data);
		return true;
	}
	bool operator==(const LinkList& list) {
		LinkNode* pCurrent = head_;
		LinkNode* pCurrent2 = list.head_;
		while (pCurrent) {
			if (!pCurrent2) {
				return false;
			} else if (pCurrent->Data_ != pCurrent2->Data_) {
				return false;
			}
			pCurrent = pCurrent->next_;
			pCurrent2 = pCurrent2->next_;
		}
		if (pCurrent2) {
			return false;
		} else {
			return true;
		}
	}
	friend ostream& operator<<(ostream& out, const LinkList& list) {
		LinkNode* pCurrent = list.head_;
		if (!pCurrent) {
			out << "NULL";
		}
		while (pCurrent) {
			out << pCurrent->Data_ << " ";
			pCurrent = pCurrent->next_;
		}
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, LinkList& list) {
		while (in) {
			int n;
			in >> n;
			if (!(list += n)) {
				in.clear(std::ios::failbit);
				return in;
			}
		}
		return in;
	}
	friend LinkList operator&(LinkList& l, LinkList& r) {
		LinkList list;
		LinkNode* pCurrent1 = l.head_;
		LinkNode* pCurrent2 = r.head_;
		while (pCurrent1 && pCurrent2) {
			if (pCurrent1->Data_ == pCurrent2->Data_) {
				list += pCurrent1->Data_;
				pCurrent1 = pCurrent1->next_;
				pCurrent2 = pCurrent2->next_;
			} else if (pCurrent1->Data_ > pCurrent2->Data_) {
				pCurrent2 = pCurrent2->next_;
			} else if (pCurrent1->Data_ < pCurrent2->Data_) {
				pCurrent1 = pCurrent1->next_;
			}
		}
		return list;
	}
	friend LinkList operator|(LinkList& l, LinkList& r) {
		LinkList list;
		LinkNode* pCurrent1 = l.head_;
		LinkNode* pCurrent2 = r.head_;
		while (pCurrent1 && pCurrent2) {
			if (pCurrent1->Data_ == pCurrent2->Data_) {
				pCurrent1 = pCurrent1->next_;
				pCurrent2 = pCurrent2->next_;
			} else if (pCurrent1->Data_ > pCurrent2->Data_) {
				list += pCurrent2->Data_;
				pCurrent2 = pCurrent2->next_;
			} else if (pCurrent1->Data_ < pCurrent2->Data_) {
				list += pCurrent1->Data_;
				pCurrent1 = pCurrent1->next_;
			}
		}
		while (pCurrent1) {
			list += pCurrent1->Data_;
			pCurrent1 = pCurrent1->next_;
		}
		while (pCurrent2) {
			list += pCurrent2->Data_;
			pCurrent2 = pCurrent2->next_;
		}
		return list;
	}
	void merge(LinkList& list) {
		LinkNode* pCurrent1 = head_;
		LinkNode* pCurrent2 = list.head_;
		LinkNode* del;
		while (pCurrent1 && pCurrent2) {
			if (pCurrent1->Data_ == pCurrent2->Data_) {
				pCurrent1 = pCurrent1->next_;
				del = pCurrent2;
				pCurrent2 = pCurrent2->next_;
				delete del;
			} else if (pCurrent1->Data_ > pCurrent2->Data_) {
				*this += pCurrent2->Data_;
				del = pCurrent2;
				pCurrent2 = pCurrent2->next_;
				delete del;
			} else if (pCurrent1->Data_ < pCurrent2->Data_) {
				pCurrent1 = pCurrent1->next_;
			}
		}
		while (pCurrent2) {
			*this += pCurrent2->Data_;
			del = pCurrent2;
			pCurrent2 = pCurrent2->next_;
			delete del;
		}
		list.head_ = list.tail_ = nullptr;
	}
};

struct DoublyNode {
	int Data_;
	DoublyNode* next_;
	DoublyNode* prev_;
	DoublyNode() :Data_(0), next_(nullptr), prev_(nullptr) {}
	DoublyNode(const int& Data) :Data_(Data), next_(nullptr), prev_(nullptr) {}
};

class DoublyLinkedList {
private:
	DoublyNode* head_;
	DoublyNode* tail_;
public:
	DoublyLinkedList() :head_(nullptr), tail_(nullptr) {}
	DoublyLinkedList(DoublyLinkedList&& list) noexcept :head_(list.head_), tail_(list.tail_) {
		list.head_ = list.tail_ = nullptr;
	}
	DoublyLinkedList(const DoublyLinkedList& list) :head_(nullptr), tail_(nullptr) {
		if (list.head_) {
			head_ = new DoublyNode(list.head_->Data_);
			DoublyNode* pCurrent = list.head_->next_;
			tail_ = head_;
			while (pCurrent) {
				tail_->next_ = new DoublyNode(pCurrent->Data_);
				tail_->next_->prev_ = tail_;
				tail_ = tail_->next_;
				pCurrent = pCurrent->next_;
			}
		}
	}
	~DoublyLinkedList() {
		while (head_) {
			tail_ = head_->next_;
			delete head_;
			head_ = tail_;
		}
	}
	const DoublyLinkedList& operator=(DoublyLinkedList&& list)noexcept {
		while (head_) {
			tail_ = head_->next_;
			delete head_;
			head_ = tail_;
		}
		head_ = list.head_;
		tail_ = list.tail_;
		list.head_ = list.tail_ = nullptr;
		return *this;
	}
	bool operator+=(const int& Data) {
		DoublyNode* pCurrent = head_;
		while (pCurrent) {
			if (pCurrent->Data_ == Data) {
				return false;
			} else if (pCurrent->Data_ > Data) {
				DoublyNode* node = new DoublyNode(Data);
				node->next_ = head_;
				head_->prev_ = node;
				head_ = node;
				return true;
			} else if (pCurrent->Data_ < Data && !pCurrent->next_) {
				tail_->next_ = new DoublyNode(Data);
				tail_->next_->prev_ = tail_;
				tail_ = tail_->next_;
				return true;
			} else if (pCurrent->Data_ < Data && pCurrent->next_->Data_ > Data) {
				DoublyNode* node = new DoublyNode(Data);
				node->next_ = pCurrent->next_;
				node->next_->prev_ = node;
				pCurrent->next_ = node;
				node->prev_ = pCurrent;
				return true;
			}
			pCurrent = pCurrent->next_;
		}
		head_ = tail_ = new DoublyNode(Data);
		return true;
	}
	bool operator==(const DoublyLinkedList& list) {
		DoublyNode* pCurrent = head_;
		DoublyNode* pCurrent2 = list.head_;
		while (pCurrent) {
			if (!pCurrent2) {
				return false;
			} else if (pCurrent->Data_ != pCurrent2->Data_) {
				return false;
			}
			pCurrent = pCurrent->next_;
			pCurrent2 = pCurrent2->next_;
		}
		if (pCurrent2) {
			return false;
		} else {
			return true;
		}
	}
	friend ostream& operator<<(ostream& out, const DoublyLinkedList& list) {
		DoublyNode* pCurrent = list.head_;
		while (pCurrent) {
			out << pCurrent->Data_ << " ";
			pCurrent = pCurrent->next_;
		}
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, DoublyLinkedList& list) {
		while (in) {
			int n;
			in >> n;
			if (!(list += n)) {
				in.clear(std::ios::failbit);
				return in;
			}
		}
		return in;
	}
	friend DoublyLinkedList operator&(DoublyLinkedList& l, DoublyLinkedList r) {
		DoublyLinkedList list;
		DoublyNode* pCurrent1 = l.head_;
		DoublyNode* pCurrent2 = r.head_;
		while (pCurrent1 && pCurrent2) {
			if (pCurrent1->Data_ == pCurrent2->Data_) {
				list += pCurrent1->Data_;
				pCurrent1 = pCurrent1->next_;
				pCurrent2 = pCurrent2->next_;
			} else if (pCurrent1->Data_ > pCurrent2->Data_) {
				pCurrent2 = pCurrent2->next_;
			} else if (pCurrent1->Data_ < pCurrent2->Data_) {
				pCurrent1 = pCurrent1->next_;
			}
		}
		return list;
	}
	friend DoublyLinkedList operator|(DoublyLinkedList& l, DoublyLinkedList r) {
		DoublyLinkedList list;
		DoublyNode* pCurrent1 = l.head_;
		DoublyNode* pCurrent2 = r.head_;
		while (pCurrent1 && pCurrent2) {
			if (pCurrent1->Data_ == pCurrent2->Data_) {
				list += pCurrent1->Data_;
				pCurrent1 = pCurrent1->next_;
				pCurrent2 = pCurrent2->next_;
			} else if (pCurrent1->Data_ > pCurrent2->Data_) {
				list += pCurrent2->Data_;
				pCurrent2 = pCurrent2->next_;
			} else if (pCurrent1->Data_ < pCurrent2->Data_) {
				list += pCurrent1->Data_;
				pCurrent1 = pCurrent1->next_;
			}
		}
		while (pCurrent1) {
			list += pCurrent1->Data_;
			pCurrent1 = pCurrent1->next_;
		}
		while (pCurrent2) {
			list += pCurrent2->Data_;
			pCurrent2 = pCurrent2->next_;
		}
		return list;
	}
	void merge(DoublyLinkedList& list) {
		DoublyNode* pCurrent = list.head_;
		while (pCurrent) {
			*this += pCurrent->Data_;
			pCurrent = pCurrent->next_;
		}
		while (list.head_) {
			list.tail_ = list.head_->next_;
			delete list.head_;
			list.head_ = list.tail_;
		}
	}
};

class a {
protected:
	void foo() {
		std::cout << "a";
	}
};

class b :public a {
public:
	void foo() {
		a::foo();
	}
};
#endif