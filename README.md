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
		
		
