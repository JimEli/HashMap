// Basic Hash Map Implementation

#include <iostream>
#include <string>
#include <assert.h>
#include "HashMap.h"
#include "KeyHash.h"

using namespace std;

struct MyKeyHash { unsigned long operator()(const int& k) const { return k % 10; } };

int main() 
{
	HashMap<int, string, 10, MyKeyHash> hmap;
	string value;

	hmap.put(1, "1");
	hmap.put(2, "2");
	hmap.put(3, "3");
	
	assert(hmap.get(2, value));
	assert(value == "2");

	assert(hmap.get(3, value));
	assert(value == "3");
	
	hmap.remove(3);
	assert(!hmap.get(3, value));
};
