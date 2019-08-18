// Very basic linked-list.
#ifndef LIST_H
#define LIST_H

#include <cassert>

template<typename T>
class list {
private:
	struct node {
		node() { }
		explicit node(const T& v) : value(v) { }

		void reset() { next = prev = this; }

		bool inList() const { return this != next; }

		void linkPrior(node* nextNode) {
			prev = nextNode->prev;
			prev->next = this;
			nextNode->prev = this;
			next = nextNode;
		}

		void unLink() {
			assert(inList());
			prev->next = next;
			next->prev = prev;
			next = prev = this;
		}

		node *next, *prev;
		T value;
	};

	node root;

	template<typename TNodePtr, typename TPtr, typename TRef>
	struct node_iterator {
		explicit node_iterator(TNodePtr node) : pNode(node) { }

		TRef operator* () const {
			assert(pNode != nullptr);
			return pNode->value;
		}
		TPtr operator-> () const { return &pNode->value; }

		TNodePtr node() const { return pNode; }

		node_iterator& operator++ () {
			pNode = pNode->next;
			return *this;
		}

		bool operator== (const node_iterator& rhs) const { return rhs.pNode == pNode; }
		bool operator!= (const node_iterator& rhs) const { return !(rhs == *this); }

	private:
		TNodePtr pNode;
	};

public:
	typedef node_iterator<node*, T*, T&> iterator;
	typedef node_iterator<const node*, const T*, const T&> const_iterator;

	explicit list() { root.reset(); }
	~list() { clear(); }

	iterator begin() { return iterator(root.next); }
	iterator end() { return iterator(&root); }

	template<typename ...Args>
	void emplace_back(Args&&... args) {
		node* newNode = new node(T(std::forward<Args>(args)...)); //constructpNode(T(std::forward<Args>(args)...));
		newNode->linkPrior(&root);
	}

	iterator erase(iterator it) {
		assert(it.node()->inList());
		iterator itErase(it);
		++it;
		itErase.node()->unLink();
		delete itErase.node();
		return it;
	}

	bool empty() const { return !root.inList(); }

	void clear() {
		node* it = root.next;
		while (it != &root) {
			node* nextIt = it->next;
			delete it;
			it = nextIt;
		}
		root.reset();
	}

	std::size_t size() const {
		const node* it = root.next;
		std::size_t size = 0;
		while (it != &root) {
			++size;
			it = it->next;
		}
		return size;
	}
};

#endif // LIST_H
