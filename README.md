# leetcode
coding exercises on leetcode.com
## plan
doing coding exercises by topics.  
30 big topics and 6 small topics  
1. two topics a day: three easy questions for each topic
2. 

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
   
		
3. p905-Sort Array By Parity[#array]

	3.1 Two Pass  
	Time Complexivity:O(N)  
	Space Complexivity:O(N)  
	
	3.2 Quick sort  
	Time Complexivity: O(N)  
	Space Complexivity: O(1)  
	
4. p26-Remove Duplicate From Sorted Array[#array]
   
   two hints:  
   + read the requirement carefully!  
   + pay attention to details  
   
5. p665-Non-decreasing Array[#array]
   
   test your analysize ability.  
   you need to consider all situations.  
   
6. p13-RomanToInteger [#string]

	6.1 string container: like vector and stack  
	6.2 can use unordered_map

7. p345-ReverseVowelsOfAString [#string]

	using swap function in c++

8. p859-BuddyStrings [#strings]

	+ using set container to count character in string  
	+ write several situations before writing codes  

9. p496-NextGreaterElement [#stack]

	+ O(n^2) brute force  
	+ O(n) using stack and unordered_map  

10. p225-ImplementStackUsingQueues [#stack]

	...
	
11. p155-Min Stack [#stack]

	push min element into she stack.

12. p121-Best Time to Buy and Sell Stocl [#dynamic programming]

	+ min() and max() function in c++  
	+ considering if the input is correct?  
	
13. p53-Maximum Subarray [#dynamic programming]

	+ Kadane's Algorithm  
	  max array ends here => calculate the sum  
	  max[i] = num[i] max[i-1]>0?max[i-1]:0;  

14. p303-Range Sum Query [#dynamic programming]

	+ large queries: create extra space to store useful data;  
	
15. p453-MinimunMovesToEqualArrayElements [#Math]

	+ Math Problem: using math proof to find the formula.
	
16. p204-Count Primes [#Math]

	+ hash table thinking: init an array for recording isPrimes.

17. p69-Sqrtx [#Math]

	+ using binary search  
	+ **multiplex overflow!!!**  

18. p617-Merge Two Binary Tree [#Tree]

	+ struct vs class in c++: public inherience and private inherience
	+ recursive method

19. p108-Convert Sorted Array ti Binary Search Tree [#Tree]
	
	+ BST: left is less; right is greater.
	+ create stack of pointer
	+ using recursive method to find the middle value
	
20. P687-Longest Univalue Path [#Tree]
	
	+ dfs: depth first traversal
	+ bfs: breadth first traversal  
	  + inorder: left root right
	  + preorder: root left right
	  + postorder: left right root
	+ using dynamic programming to calculate!

21. p500-Keyboard Row [#Hash Table]

	+ using unordered_map or unordered_set  
		differences:
		+ set
		  + sorted order
		  + unique value
		  + implemented as BST
		+ multi-set
		  + sorted order
		  + multi value
		  + BST
		+ unordered_set
		  + any order
		  + unique value
		  + hash table
		+ unordered_multiset
	
		
	  
