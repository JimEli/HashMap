// Hash map with separate chaining.
#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

// Visual Leak Detector.
#include "C:\Program Files (x86)\Visual Leak Detector\include\vld.h"

int main()
{
    cout << "Hash Table - Separate Chaining" << endl;

    HashTable<std::string> *hashTable = new HashTable<std::string>();

    cout << (hashTable->isEmpty() ? "Hash table is empty" : "Hash table is not empty") << "\n";

    // Adding a data then check if hash table is empty.
    cout << "Adding data" << endl;
    hashTable->insert(434, "Dylan");
    cout << (hashTable->isEmpty() ? "Hash table is empty" : "Hash table is not empty") << "\n";

    // Adding other data.
    hashTable->insert(391, "Dominic");
    hashTable->insert(806, "Adam");
    hashTable->insert(117, "Lindsey");
    hashTable->insert(548, "Cameron");
    hashTable->insert(669, "Terry");
    hashTable->insert(722, "Brynn");
    hashTable->insert(276, "Jody");
    hashTable->insert(953, "Frankie");
    hashTable->insert(895, "Vanessa");

    // Search key 669, it should be found.
    int key = 669;
    cout << "Search value for key " << key << endl;
    string name = hashTable->search(key);
    if (name != "")
        cout << "Value for key " << key << " is " << name << endl;
    else
        cout << "Value for key " << key << " is not found\n";

    // Remove key 669 then search the key,  it should not be found.
    cout << "Remove node of key " << key << endl;
	hashTable->remove(key);
	name = hashTable->search(key);
    if (name != "")
        cout << "Value for key " << key << " is " << name << endl;
    else
        cout << "Value for key " << key << " is not found\n";

	delete hashTable;
}
