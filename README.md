# HashMap
### Basic Hash Map Implementation in C++

Define a hash function by overloading operator() for integer typed key:
```  struct MyKeyHash 
	{ 
	  unsigned long operator() (const int& key) const 
	  { 
	    return key % 10; 
	  } 
	};
```

Declare a hash map with integer typed key and string type value pair:
```  size_t tableSize = 10;
  HashMap<int, string, tableSize, MyKeyHash> hmap;
```

Put a key-value pair into the hashmap:
```  hmap.put(1, "1");
```

Get the value by key; returns true if successful with value updated:
```  string value;
  bool result = hmap.get(2, value);
```
