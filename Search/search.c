#include <stdbool.h>
#include <stddef.h> // size_t
#include <stdint.h> // SIZE_MAX

#include "search.h"

bool binarySearch(int *elems, size_t l, size_t r, int x, int y, size_t *idx) {
    if (l > r) return false;

    size_t mid = (l + r) / 2;
    if (elems[mid] >= x && elems[mid] <= y) {
        *idx = mid;
        return true;
    } else if (elems[mid] > y) {
        // prevent overflow (leading to segfault, or possible infinite loop
        //   if array is of maximal size), if even the arrays' smallest element
        //   is not in [x, y]
        if (mid == 0) return false;

        else return binarySearch(elems, l, mid - 1, x, y, idx);
    } else { /* elems[mid] < x */
        // prevent overflow (leading to infinite loop) if array is of maximal size,
        //   and even the array's largest element is not in [x, y]
        if (mid == SIZE_MAX) return false;

        else return binarySearch(elems, mid + 1, r, x, y, idx);
    }
}
