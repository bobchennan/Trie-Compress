#include "trie.c"
#include "printtree.c"
#include "ortc.c"
#include "stdio.h"


/*
 * Author:cnx
 * Date:2014.06
 */

int main(){
    trie_t *t=trie_init();
	char s[100];
	int v;
	while(scanf("%d",&v)!=EOF){
		getchar();
		gets(s);
		trie_add(t,s,v);
		//printf("%d\n",trie_find(t,"0101"));
		//printf("%d\n",trie_find(t,"010"));
		print_t(t);
	}
	print_t(PassOne(t));
	print_t(OptimalRoutingTableConstructor(t));
	trie_free(t);
    return 0;
}
