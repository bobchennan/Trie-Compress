#include "ortc.h"
#include <stdlib.h>

#define M 10

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

char* transSa(int *sa, int n){
	int ma=0,i,cnt=0,j,k=0;
	char *ret;
	for(i=0;i<n;++i)
		ma=(ma>si[i])?ma:si[i];
	while(ma!=0){
		ma/=2;
		cnt+=1;
	}
	ret=malloc(sizeof(char)*cnt*n);
	for(i=0;i<n;++i){
		int tmp=si[i];
		for(j=0;j<cnt;++j){
			if((tmp&1)==1)ret[k++]='1';
			else ret[k++]='0';
			tmp>>=1;
		}
	}
	return ret;
}

//from ks001
int next_combination(int n, int k){
    int ret, b = k & -k, t = (k + b);
    ret = (((t ^ k) >> 2) / b) | t;
    if ((1 << n) < ret) return 0;
    return ret;
}

char* transSi(char *si, int n){
	//TODO
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

