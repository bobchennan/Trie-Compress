//http://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console

int printtree_maxdep=0;

#define COMPACT

int _print_t(trie_t *tree, int is_left, int offset, int depth, char s[][255])
{
    char b[20];
    int width = 5, i;

    if (!tree) return 0;

    if(tree->label)sprintf(b, "(%03d)", tree->label);
	else sprintf(b, "  o  ");

    int left  = _print_t(tree->to[0],  1, offset,                depth + 1, s);
    int right = _print_t(tree->to[1], 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];
	if(depth>printtree_maxdep)
		printtree_maxdep=depth;

    if (depth && is_left) {

        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
	if(2*depth>printtree_maxdep)
		printtree_maxdep=2*depth;
    for (i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}

int print_t(trie_t *tree)
{
    char s[200][255];
    int i;
	for (i = 0; i < 200; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (i = 0; i <= printtree_maxdep; i++)
        printf("%s\n", s[i]);
}
