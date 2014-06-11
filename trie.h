#ifndef _TRIE_H_
#define _TRIE_H_

/*
 * Author:cnx
 * Date:2014.06
 */

typedef struct trie_t{
	int label;
	struct trie_t *to[2];	
} trie_t;

trie_t *trie_init(void);
int trie_find(trie_t *, char *);
int trie_size(trie_t *);
void trie_save(trie_t *, int *);
void trie_free(trie_t *);
void trie_add(trie_t *, char *, int);

#endif
