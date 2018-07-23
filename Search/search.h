#ifndef __SEARCH_H_
#define __SEARCH_H_

#include <stdbool.h>
#include <stddef.h>

// returns whether at least one element in elems[l, r] is in [x, y]
//   also puts the index of the element found in *idx
// return -1 if no such element in elems
bool binarySearch(int *elems, size_t l, size_t r, int x, int y, size_t *idx);

#endif
