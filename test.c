#include "trie.c"
#include "stdio.h"

/*
 * Author:cnx
 * Date:2014.06
 */

int main(){
    trie_t *t=trie_init();
    trie_add(t,"cnx",3);
    trie_add(t,"cn",4);
    printf("%d\n",trie_find(t,"cnx"));
    printf("%d\n",trie_find(t,"cny"));
    printf("%d\n",trie_size(t));
    return 0;
}
