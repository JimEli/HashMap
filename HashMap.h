// HashMap.h

#include <cstddef>

// Default hash function class.
template <typename K, size_t tableSize>
struct KeyHash
{
	unsigned long operator() (const K &key) const
	{
		return reinterpret_cast<unsigned long>(key) % tableSize;
	}
};

// Hash map class template
template <typename K, typename V, size_t tableSize, typename F = KeyHash<K, tableSize> >
class HashMap 
{
private:
	// Hash node class template.
	template <typename K, typename V>
	class HashNode
	{
	public:
		HashNode(const K &key, const V &value) : _key(key), _value(value), _next(NULL) { }

		K getKey() const { return _key; }
		V getValue() const { return _value; }
		HashNode *getNext() const { return _next; }
		void setNext(HashNode *next) { _next = next; }
		void setValue(V value) { _value = value; }

	private:
		// Key-value pair.
		K _key;
		V _value;

		// Next bucket with the same key.
		HashNode *_next;

		// Disallow copy and assignment.
		HashNode(const HashNode &);
		HashNode & operator= (const HashNode &);
	};

	HashMap(const HashMap& other);
	const HashMap & operator= (const HashMap & other);

	// Hash table.
	HashNode<K, V> *table[tableSize];
	F hashFunc;

public:
	HashMap() : table(), hashFunc() { }

	~HashMap() 
	{
		// Destroy all buckets one by one.
		for (size_t i = 0; i < tableSize; ++i) 
		{
			HashNode<K, V> *entry = table[i];
			
			while (entry != NULL) 
			{
				HashNode<K, V> *prev = entry;
				entry = entry->getNext();
				delete prev;
			}
			
			table[i] = NULL;
		}
	}

	bool get(const K &key, V &value) 
	{
		unsigned long hashValue = hashFunc(key);
		HashNode<K, V> *entry = table[hashValue];
		
		while (entry != NULL) 
		{
			if (entry->getKey() == key) 
			{
				value = entry->getValue();
				return true;
			}
			entry = entry->getNext();
		}
		
		return false;
	}

	void put(const K &key, const V &value) 
	{
		unsigned long hashValue = hashFunc(key);
		HashNode<K, V> *prev = NULL;
		HashNode<K, V> *entry = table[hashValue];

		while (entry != NULL && entry->getKey() != key) 
		{
			prev = entry;
			entry = entry->getNext();
		}
		
		if (entry == NULL) 
		{
			entry = new HashNode<K, V>(key, value);
		
			if (prev == NULL) 
			{
				// Insert as first bucket.
				table[hashValue] = entry;
			}
			else
				prev->setNext(entry);
		}
		else
			// Just update the value.
			entry->setValue(value);
	}

	void remove(const K &key) {
		unsigned long hashValue = hashFunc(key);
		HashNode<K, V> *prev = NULL;
		HashNode<K, V> *entry = table[hashValue];
		
		while (entry != NULL && entry->getKey() != key) {
			prev = entry;
			entry = entry->getNext();
		}
		
		if (entry == NULL)
			// Key not found.
			return;
		else 
		{
			if (prev == NULL) 
				// Remove first bucket of the list.
				table[hashValue] = entry->getNext();
			else
				prev->setNext(entry->getNext());
			
			delete entry;
		}
	}
};
