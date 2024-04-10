#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int mod_binary_search(int *array, int value, int begin, int end);
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int linear_search_range(int *array, size_t start, size_t end, int value);
int get_midpoint(int begin, int end);
size_t calculate_pos(size_t l, size_t h, int v, int *arr);
int exponential_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
#endif
