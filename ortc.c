#include "trie.h"
#include "stdlib.h"

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

//Pass two and pass three
//TODO: use stack to implement recursive
//TODO: use in-place merge sort instead of qsort links can be found here:https://github.com/liuxinyu95/AlgoXY/blob/algoxy/sorting/merge-sort/src/mergesort.c
int QQ[MAXQ];
int cmp ( const void *a , const void *b ) { 
	return *(int *)a - *(int *)b;
} 
int PassCalc(trie_t* root, int st){
	int c1,c2,i,j,k;
	
	if(root->to[0]==NULL&&root->to[1]==NULL){
		if(root->label){
			QQ[st]=root->label;
			return 1;
		}
		else
			return 0;
	}
	c1=PassCalc(root->to[0], st);
	c2=PassCalc(root->to[1], st+c1);
	i=st;
	j=st+c1;
	for(;;){
		if(i>=st+c1&&j>=st+c1+c2)break;
		if(i>=st+c1||QQ[j]<QQ[i])++j;
		else if(j>=st+c1+c2||QQ[i]<QQ[j])++i;
		else if(QQ[i]==QQ[j])break;
	}
	if(i>=st+c1&&j>=st+c1+c2){
		qsort(QQ+st,c1+c2,sizeof(QQ[st]),cmp);
		return c1+c2;
	}
	else{
		i=st;
		k=i;
		j=st+c1;
		for(;;){
			if(i>=st+c1&&j>=st+c1+c2)break;
			if(QQ[i]==QQ[j]){
				QQ[k++]=QQ[i];
				++i;
				++j;
			}
			if(i>=st+c1||QQ[j]<QQ[i])++j;
			else if(j>=st+c1+c2||QQ[i]<QQ[j])++i;
		}
		return k-st;
	}
}

trie_t* PassRest(trie_t* root, int label){
	int c1,c2,i,j,k;
	int given_label,len=0;
	
	if(root->to[0]==NULL&&root->to[1]==NULL){
		QQ[0]=root->label;
		if(root->to[0]==NULL&&root->to[1]==NULL){
			if(label==root->label){
				root->label=0;
				trie_free(root);
				return NULL;
			}
			else{
				QQ[0]=root->label;
				len=1;
			}
		}
	}
	else{
		c1=PassCalc(root->to[0], 0);
		c2=PassCalc(root->to[1], 0+c1);
		i=0;
		j=0+c1;
		for(;;){
			if(i>=0+c1&&j>=0+c1+c2)break;
			if(i>=0+c1||QQ[j]<QQ[i])++j;
			else if(j>=0+c1+c2||QQ[i]<QQ[j])++i;
			else if(QQ[i]==QQ[j])break;
		}
		if(i>=0+c1&&j>=0+c1+c2){
			qsort(QQ+0,c1+c2,sizeof(QQ[0]),cmp);
			len=c1+c2;
		}
		else{
			i=0;
			k=i;
			j=0+c1;
			for(;;){
				if(i>=0+c1&&j>=0+c1+c2)break;
				if(QQ[i]==QQ[j]){
					QQ[k++]=QQ[i];
					++i;
					++j;
				}
				if(i>=0+c1||QQ[j]<QQ[i])++j;
				else if(j>=0+c1+c2||QQ[i]<QQ[j])++i;
			}
			len=k-0;
		}
	}
	if(len){
		short need=1;
		for(i=0;i<len;++i)
			if(QQ[i+0]==label){
				need=0;
				break;
			}
		if(!need){
			root->label=0;
			if(root->to[0]==NULL&&root->to[1]==NULL){
				trie_free(root);
				root=NULL;
				return NULL;
			}
		}
		else{
			if(QQ[0]!=label)root->label=QQ[0];
			else root->label=QQ[0+1];
		}
	}
	given_label=(root->label==0)?label:root->label;
	if(root->to[0]!=NULL)root->to[0]=PassRest(root->to[0], given_label);
	if(root->to[1]!=NULL)root->to[1]=PassRest(root->to[1], given_label);
	return root;
}

trie_t* OptimalRoutingTableConstructor(trie_t * root){
	root=PassOne(root);
	return PassRest(root, 0);
}