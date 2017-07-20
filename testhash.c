#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "hashtable.h"

static int elem_cnt = 0;
static void travel(int id, void *obj)
{
	intptr_t o = (intptr_t)obj;
	assert(o == (id+1));
	elem_cnt++;
	return ;
}

int main()
{
	intptr_t i;
	intptr_t conflict = 0;
	struct hash_table *tbl = hash_create(64);
	//test conflict 1
	for (i = 0; i < 64; i++) {
		hash_set(tbl, conflict, (void *)(conflict + 1));
		conflict += 64;
	}
	for (i = 0; i < 64; i++) {
		hash_set(tbl, i, (void *)(i + 1));
	}
	//test conflict 2
	for (i = 0; i < 64; i++) {
		hash_set(tbl, i * 2, (void *)(i * 2 + 1));
	}
	hash_foreach(tbl, travel);
	printf("total elem:%d\n", elem_cnt);
	hash_free(tbl);
	return 0;
}
