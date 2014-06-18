#include <stdio.h>
#include "trie.h"
#include "ortc.h"
#include "xbw-b.c"

char s[33];

void tran(int v, char* s){
	int i;
	for(i=7;i>=0;--i){
		s[i]='0'+(v&1);
		v>>=1;
	}
}

int main(){
	FILE *in=fopen("bgp.out","r");
	int a,b,c,d,v,limit;
	
	trie_t *t=trie_init();
	
	while(fscanf(in,"%d.%d.%d.%d/%d %d",&a,&b,&c,&d,&limit,&v)!=EOF){
		tran(a,s+0);
		tran(b,s+8);
		tran(c,s+16);
		tran(d,s+24);
        s[limit]='\0';
		//printf("%s\n",s);
		trie_add(t,s,v);
	}
	printf("%d\n",trie_size(t));
	//print_t(t);
    printf("%d\n",trie_size(PassOne(t)));
    t=OptimalRoutingTableConstructor(t);
    printf("%d\n",trie_size(t));
    //print_t(OptimalRoutingTableConstructor(t));
	xbw_init(t,0);
	return 0;
}
