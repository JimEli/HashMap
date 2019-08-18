// hash table with seperate chaining via linked-list.
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include "list.h"
#include "pair.h"

// Define std::pair components.
#define _key  first
#define _data second

constexpr int TABLE_SIZE{ 7 };

template <typename T>
class HashTable
{
private:
	//std::list<std::pair<int, T>> tableList[TABLE_SIZE];
	list<std::pair<int, T>> tableList[TABLE_SIZE];

	int hashFunction(int key) { return key % TABLE_SIZE; }

public:
	HashTable()
	{
		for (int i = 0; i < TABLE_SIZE; ++i)
			tableList[i].clear();
	}

	void insert(int key, T data)
	{
		bool isKeyFound = false;
		int hashKey = hashFunction(key);

		for (auto& element : tableList[hashKey])
		{
			// If the key is found update the data.
			if (element._key == key)
			{
				isKeyFound = true;
				element._data = data;
			}
		}

		// If key is not found, append at the back.
		if (!isKeyFound)
		{
			//std::pair<int, T> newElement(key, data);
			//tableList[hashKey].push_back(newElement);
			tableList[hashKey].emplace_back(key, data);
		}
	}

	T search(int key)
	{
		int hashKey = hashFunction(key);

		// Iterate through chaining node (linked list) in selected cell.
		for (auto &element : tableList[hashKey])
		{
			// If key is found return data.
			if (element._key == key)
				return element._data;
		}

		return "";
	}

	void remove(int key)
	{
		int hashKey = hashFunction(key);
		auto &cell = tableList[hashKey];

		for (auto it = cell.begin(); it != cell.end(); ++it) {
			// If key is found then delete the list's element.
			if (it->_key == key)
			{
				cell.erase(it);
				break;
			}
		}
	}

	bool isEmpty()
	{
		int totalElement = 0;

		// Count all elements in table hash.
		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			totalElement += (int)tableList[i].size();
			// If total elements != 0 hash table is not empty.
			if (totalElement > 0)
				return false;
		}
		return true;
	}
};

#endif
