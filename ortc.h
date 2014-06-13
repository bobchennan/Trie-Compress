#ifndef _ORTC_H_
#define _ORTC_H_

#include "trie.h"

trie_t* PassOne(trie_t*);
trie_t* PassRest(trie_t*, int);
trie_t* OptimalRoutingTableConstructor(trie_t*);

#endif