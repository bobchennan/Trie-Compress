#include "trie.c"

/*
 * Author:cnx
 * Date:2014.06
 */

trie_t* PassOne(trie_t* root){
	int l=0,r=1;
	Q[l]=root;
	while(l!=r){
		trie_t* now=Q[l];
		succed(&l);
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
	}
}

trie_t* PassTwo(trie_t* root){
	
}

trie_t* PassThree(trie_t* root){
	
}

trie_* OptimalRoutingTableConstructor(trie_t * root){
	return PassThree(PassTwo(PassOne(root)));
}