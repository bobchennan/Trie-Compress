#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "trie.h"

/*
 * Author:cnx
 * Date:2014.06
 */

#define MAXL 14
#define MAXQ (1<<MAXL)
trie_t* Q[MAXQ];

inline void succed(int* v){
	(*v)=((*v)+1)&((1<<MAXQ)-1);
}

inline trie_t *trie_init(void){
	return calloc(1, sizeof(trie_t));
}

int trie_find(trie_t *root, char *s){
	int i,len=strlen(s),ret=root->label;
	short v;
	for(i=0;i<len;++i)
		if(s[i]=='0'||s[i]=='1'){
			v=s[i]-'0';
			if(root->to[v]==NULL)
				root->to[v]=trie_init();
			root=root->to[v];
			if(root->label!=NULL)
				ret=root->label;
		}
	return ret;
}

int trie_size(trie_t *root){
	int ret=0,l=0,r=1;
	Q[l]=root;
	while(l!=r){
		trie_t* now=Q[l];
		++ret;
		succed(&l);
		if(now->to[0]!=NULL){
			Q[r]=now->to[0];
			succed(&r);
		}
		if(now->to[1]!=NULL){
			Q[r]=now->to[1];
			succed(&r);
		}
	}
	return ret*sizeof(trie_t);
}

void trie_save(trie_t * root, int *s){
	int l=0,r=1,cnt=0;
	Q[l]=root;
	while(l!=r){
		trie_t* now=Q[l];
		s[cnt]=now->label;
		succed(&l);
		if(now->to[0]!=NULL){
			Q[r]=now->to[0];
			succed(&r);
			s[cnt+1]=((l+MAXQ-r)&MAXQ)*3;
		}
		else 
			s[cnt+1]=0;
		if(now->to[1]!=NULL){
			Q[r]=now->to[1];
			succed(&r);
			s[cnt+2]=((l+MAXQ-r)&MAXQ)*3;
		}
		else
			s[cnt+2]=0;
	}
}

void trie_free(trie_t *root){
	int l=0,r=1;
	Q[l]=root;
	while(l!=r){
		trie_t* now=Q[l];
		succed(&l);
		if(now->to[0]!=NULL){
			Q[r]=now->to[0];
			succed(&r);
		}
		if(now->to[1]!=NULL){
			Q[r]=now->to[1];
			succed(&r);
		}
		free(now);
	}
}

void trie_add(trie_t *root, char *s, int label){
	int i,len=strlen(s),ret=root->label;
	short v;
	for(i=0;i<len;++i)
		if(s[i]=='0'||s[i]=='1'){
			v=s[i]-'0';
			if(root->to[v]==NULL)
				root->to[v]=trie_init();
			root=root->to[v];
			if(root->label!=NULL)
				ret=root->label;
		}
	root->label=label;
}
