Trie-Compress
=============

Briefly implement algorithms introduced in "Compressing IP Forwarding Tables: Towards Entropy Bounds and Beyond A revised technical report", mainly contains algorithms about compressing the Trie structure.

Algorithms include(plan):

*   original binary Trie
*   ~~Path-compressed Trie(PATRICIA Tree)~~(omitted due to the backtracking overhead)
*   ORTC algorithm
*   level compress trie
*   XBW-b implementation

Also, a visualized tree can be used to view the transform of different algorithms.
There are two views using in printtree.c, just define COMPACT or not:

<pre>
COMPACT look:                                                  
	     .-----------------  o  -----------------.       
	  .--  o  -------.                   .-------  o  --.                           
	  o         .--  o  --.         .--  o  --.       (003)                         
	          (001)       o         o       (002)          
			  

DEFAULT look:
                           o                                                    
       +-------------------+-------------------+                                
       o                                       o                                
  +----+---------+                   +---------+----+                           
  o              o                   o            (003)                         
            +----+----+         +----+----+                                     
          (001)       o         o       (002)       
</pre>		  
