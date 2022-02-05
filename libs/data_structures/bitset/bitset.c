#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "bitset.h"

unsigned int max2(int a, int b) {
    return a > b ? a : b;
}

bitset bitset_create(unsigned setMaxValue) {
    assert(setMaxValue < 32);
    return (bitset) {0, setMaxValue};
}

bool bitset_checkValue(bitset set, uint32_t value) {
    return value >= 0 && value <= set.maxValue;
}

bool bitset_in(bitset set, uint32_t value) {
    assert(bitset_checkValue(set, value));
    return set.values >> value & 1;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values;
}

bool bitset_isSubset(bitset subset, bitset set) {
    return (set.values & subset.values) == subset.values;
}

void bitset_insert(bitset *set, uint32_t x) {
    assert(bitset_checkValue(*set, x));
    set->values |= 1 << x;
}

void bitset_deleteElement(bitset *set, unsigned int value) {
    if (bitset_in(*set, value))
        set->values = set->values & ~(1 << value);
}

bitset bitset_union(bitset set1, bitset set2) {
    return (bitset) {set1.values | set2.values, max2(set1.maxValue, set2.maxValue)};
}

bitset bitset_intersection(bitset set1, bitset set2) {
    return (bitset) {set1.values & set2.values, max2(set1.maxValue, set2.maxValue)};
}

bitset bitset_difference(bitset set1, bitset set2) {
    return (bitset) {set1.values & ~set2.values, max2(set1.maxValue, set2.maxValue)};
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    return (bitset) {set1.values ^ set2.values, max2(set1.maxValue, set2.maxValue)};
}

bitset bitset_complement(bitset set) {
    return (bitset) {~set.values, set.maxValue};
}

void bitset_print(bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}


