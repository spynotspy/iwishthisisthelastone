#include <malloc.h>
#include <stdlib.h>

#include "ordered_array_set.h"

ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {malloc(sizeof(int) * capacity), 0, capacity};
}

static void ordered_array_set_shrinkToFit(ordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size) {
    int b[size];
    copyArray(b, a, size);
    qsort(b, size, sizeof(int), compare_ints);
    ordered_array_set set = ordered_array_set_create(size);
    for (int i = 0; i < size; ++i) {
        ordered_array_set_insert(&set, b[i]);
    }

    return set;
}


size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
    for (int i = 0; i < set1.size; ++i) {
        if (set1.data[i] != set2.data[i])
            return 0;
    }
    return 1;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    if (subset.size > set.size)
        return 0;

    for (int i = 0; i < subset.size; ++i) {
        if (ordered_array_set_in(&set, subset.data[i]) == SIZE_MAX)
            return 0;
    }
    return 1;
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}


void ordered_array_set_insert(ordered_array_set *set, int value) {
    if (ordered_array_set_in(set, value) == set->size) {
        ordered_array_set_isAbleAppend(set);
        int pos = binarySearchMoreOrEqual_(set->data, set->size, value);
        if (pos == set->size)
            append_(set->data, &set->size, value);
        else if (pos == 0)
            set->data[pos] = value;
        else
            insert_(set->data, &set->size, pos, value);
    }
}


void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    assert(ordered_array_set_in(set, value) == set->size);
    size_t pos = binarySearch_(set->data, set->size, value);
    deleteByPosSaveOrder_(set->data, &set->size, pos);
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    int capacity = set1.size + set2.size;
    int sortedArray[capacity];
    merge(set1.data, set1.size, set2.data, set2.size, sortedArray);
    ordered_array_set set3 = ordered_array_set_create_from_array(sortedArray, capacity);

    return set3;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    size_t capacity = set1.size + set2.size;
    ordered_array_set set3 = ordered_array_set_create(capacity);
    size_t i = 0;
    size_t j = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] > set2.data[j]) {
            j++;
        } else if (set1.data[i] < set2.data[j]) {
            i++;
        } else {
            append_(set3.data, &set3.size, set1.data[i++]);
            j++;
        }
    }
    return set3;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    size_t i = 0;
    size_t j = 0;
    int capacity = set1.size + set2.size;
    ordered_array_set set3 = ordered_array_set_create(capacity);
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j]) {
            append_(set3.data, &set3.size, set1.data[i++]);
        } else if (set1.data[i] == set2.data[j]) {
            i++;
        } else {
            j++;
        }
    }
    for (size_t k = i; k < set1.size; k++) {
        append_(set3.data, &set3.size, set1.data[k]);
    }
    return set3;
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set dif1 = ordered_array_set_difference(set1, set2);
    ordered_array_set dif2 = ordered_array_set_difference(set2, set1);
    ordered_array_set symDif = ordered_array_set_union(dif1, dif2);
    ordered_array_set_delete(dif1);
    ordered_array_set_delete(dif2);

    return symDif;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    return ordered_array_set_difference(universumSet, set);
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    bool isEmpty = true;
    for (size_t i = 0; i < set.size; i++) {
        printf("%d, ", set.data[i]);
        isEmpty = false;
    }
    if (isEmpty) printf("}"); else printf("\b\b}\n");
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}

