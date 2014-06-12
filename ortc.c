#include "trie.h"

/*
 * Author:cnx
 * Date:2014.06
 */

trie_t* PassOne(trie_t* root){
//complete prefix tree
	int l=0,r=1;
	Q[l]=root;
	while(l!=r){
		trie_t* now=Q[l];
		succed(&l);
		if(now->to[0]!=NULL||now->to[1]!=NULL){
			if(now->to[0]!=NULL){
				Q[r]=now->to[0];
				succed(&r);
			}
			else
				now->to[0]=trie_init();
			if(now->to[1]!=NULL){
				Q[r]=now->to[1];
				succed(&r);
			}
			else
				now->to[1]=trie_init();
			if(now->label!=0){
				if(now->to[0]->label==0)
					now->to[0]->label=now->label;
				if(now->to[1]->label==0)
					now->to[1]->label=now->label;
				now->label=0;
			}
		}
	}
	return root;
}

trie_t* PassTwo(trie_t* root){
	
}

trie_t* PassThree(trie_t* root){
	
}

trie_t* OptimalRoutingTableConstructor(trie_t * root){
	return PassThree(PassTwo(PassOne(root)));
}