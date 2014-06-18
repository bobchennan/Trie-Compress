#include "ortc.h"
#include <stdlib.h>

#define M 10

//Return numbers of leaves
int transform(trie_t *root, char *si, int *sa){
	int l=0,r=1,cnt=0,cnt2=0;
	Q[l]=root;
	while(l!=r){
		trie_t* now=Q[l];
		if(now->label!=0)sa[cnt++]=now->label;
		if(now->to[0]!=NULL||now->to[1]!=NULL){
			si[cnt2++]='0';
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
			si[cnt2++]='1';
		succed(&l);
	}
    printf("si length: %d\n",cnt2);
    for(l=0;l<cnt2;++l)putchar(si[l]);
    puts("");
	return cnt;
}

char* transSa(int *sa, int n){
	int ma=0,i,cnt=0,j,k=0;
	char *ret;
	for(i=0;i<n;++i)
		ma=(ma>sa[i])?ma:sa[i];
	while(ma!=0){
		ma/=2;
		cnt+=1;
	}
	ret=malloc(sizeof(char)*cnt*n);
	for(i=0;i<n;++i){
		int tmp=sa[i];
		for(j=0;j<cnt;++j){
			if((tmp&1)==1)ret[k++]='1';
			else ret[k++]='0';
			tmp>>=1;
		}
	}
    printf("sa length: %d\n",k);
    for(i=0;i<k;++i)putchar(ret[i]);
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
}

void xbw_init(trie_t *root, char normalized){
	if(!normalized)root=PassOne(root);
	printf("%d\n",trie_size(root));
    int i,sz=trie_size(root);
	char *si=malloc(sz*sizeof(char));
	int *sa=malloc(sz*sizeof(int));
	int leaves=transform(root,si,sa);
    transSa(sa, leaves);
    //for(i=0;i<sz;++i)putchar('0'+si[i]);
    //putchar('\n');
	//for(i=0;i<leaves;++i)printf("%d ",sa[i]);
	//putchar('\n');
}

