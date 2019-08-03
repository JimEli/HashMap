/*
  Basic Hash Map Implementation in C++

  Define a hash function by overloading operator() for integer typed key:
    struct MyKeyHash 
	{ 
	  unsigned long operator() (const int& key) const 
	  { 
	    return key % 10; 
	  } 
	};

 Declare a hash map with integer typed key and string type value pair:
   size_t tableSize = 10;
   HashMap<int, string, tableSize, MyKeyHash> hmap;

 Put a key-value pair into the hashmap:
   hmap.put(1, "1");

 Get the value by key; returns true if successful with value updated:
  string value;
  bool result = hmap.get(2, value);

*/
#include <iostream>
#include <string>
//#include <cmath>
#include <assert.h>
//#include <inttypes.h>
#include "HashMap.h"
#include "KeyHash.h"

using namespace std;
/*
class Param 
{
public:
	enum Type { FLOAT = 0, INT = 1, };

	typedef HashMap<const char*, Param*, 8, KeyHash<const char*, 8>> DictType;
	
	union Value 
	{
		static Value fromInt(int val) 
		{
			Value v;
			v.i = val;
			return v;
		}

		static Value fromFloat(float val) 
		{
			Value v;
			v.f = val;
			return v;
		}
		
		int i;
		float f;
	};

	template <class T>
	Param(const char * name, T defaultValue, Type type) : _def(), _type(type) 
	{
		if (type == FLOAT)
			_def = Value::fromFloat(float(defaultValue));
		else if (type == INT)
			_def = Value::fromInt(int(defaultValue));
	
		getDict().put(name, this);
	}

	Type getType() { return (Type)_type; }

	int getInt() 
	{
		if (getType() == FLOAT) 
			return int(_def.f);
		else if (getType() == INT)
			return _def.i;
		else
			return 0;
	}

	float getFloat() 
	{
		if (getType() == FLOAT) 
			return _def.f;
		else if (getType() == INT) 
			return float(_def.i);
		else
			return 0;
	}

	static DictType & getDict() { return _dict; }

private:
	Value _def;
	Type _type;
	static DictType _dict;

	Param(const Param & p);
	Param& operator= (const Param & p);
};

Param::DictType Param::_dict;

Param p1("param1", 1.0f, Param::FLOAT);
Param p2("param2", 2, Param::INT);
Param p3("param3", 1.3f, Param::FLOAT);
*/
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
/*
	//
	//
	//
	Param *p = NULL;
	bool result = false;
	
	// show structure size
	std::cout << "size of Param: " << sizeof(Param) << std::endl;
	
	// param1
	result = Param::getDict().get("param1", p);
	assert(result);
	assert(p->getType() == Param::FLOAT);
	assert(fabs(p->getFloat() - 1.0f) < 1e-20);
	assert(p->getInt() == 1);
	
	// param2
	result = Param::getDict().get("param2", p);
	assert(result);
	assert(p->getType() == Param::INT);
	assert(fabs(p->getFloat() - 2.0f) < 1e-20);
	assert(p->getInt() == 2);
	
	// param3
	result = Param::getDict().get("param3", p);
	assert(result);
	assert(p->getType() == Param::FLOAT);
	assert(fabs(p->getFloat() - 1.3f) < 1e-20);
	assert(p->getInt() == 1);
*/
};
