#include "ortc.h"
#include <stdlib.h>

//Return numbers of leaves
int transform(trie_t *root, char *si, int *sa){
	int l=0,r=1,cnt=0;
	Q[l]=root;
	while(l!=r){
		trie_t* now=Q[l];
		if(now->label!=0)sa[cnt++]=now->label;
		if(now->to[0]!=NULL||now->to[1]!=NULL){
			si[l]=0;
			if(now->to[0]!=NULL){
				Q[r]=now->to[0];
				succed(&r);
			}
			if(now->to[1]!=NULL){
				Q[r]=now->to[1];
				succed(&r);
			}
		}
		else
			si[l]=1;
		succed(&l);
	}
	return cnt;
}

void xbw_init(trie_t *root, char normalized){
	if(!normalized)root=PassOne(root);
	int i,sz=trie_size(root)/sizeof(trie_t);
	char *si=malloc(sz);
	int *sa=malloc(sz*sizeof(int));
	int leaves=transform(root,si,sa);
	for(i=0;i<sz;++i)putchar('0'+si[i]);
	putchar('\n');
	for(i=0;i<leaves;++i)printf("%d ",sa[i]);
	putchar('\n');
}

