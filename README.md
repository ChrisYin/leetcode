# leetcode
coding exercises on leetcode.com
## plan
1. difficulty: easy  
   goal: basic grammar for c++
   
2. diffuculty:medium  
   for different topic  


## notes
1. p1-Two Sum

	1.1 knowing how to use vector in C++;

		+ initialize a vector 
	
		```c++
		//"=" operator
		vector<int> t0 = t1;
		//constructor
		vector<int> t0(t1);
		```
	
		+ loop
	
		```c++
		for(int i = 0; i < t0.size(); i++){
			...
		}
		```
	
		+ push_back and pop_back

	1.2 algorithms
		
		+ brute force
		
		find the complement number  
		Time Complexivity: O(n^2)  
		Space Complexivity: O(1)  
		
		+ one pass hash table  
		using hash table to find.  
		Time Complexivity: O(n)  
		Space Complexvity: O(n)  
	
2. p7-Reverse Integer
   
   2.1 integer overflow
   
   unsigned int: 0 to 4294967295  
   signed int: -2147483648 to 2147483647  
   the limits are defined in limits.h header  
	   + std::numeric_limits<int>::min()
	   + std::numeric_limits<int>::max()
   
		
3. p905-Sort Array By Parity[array]

	3.1 Two Pass  
	Time Complexivity:O(N)  
	Space Complexivity:O(N)  
	
	3.2 Quick sort  
	Time Complexivity: O(N)  
	Space Complexivity: O(1)  
	
