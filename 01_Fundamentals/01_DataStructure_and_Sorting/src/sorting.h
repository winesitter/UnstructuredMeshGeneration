#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "data_structures.h"


/************************************************
 * Function pointer for node-sort function
 *
 * Arguments:
 * *nodes    - NodeContanier
 *  N        - Number of nodes
 *  dir      - Geometric direction (0 - x
 *                                  1 - y)
 *  order    - Sorting order (0 - ascending 
 *                            1 - descending)
 ***********************************************/
typedef int (*nodeSort)(NodeContainer *nodes,
                        int            N,
                        int            dir,
                        int            order);

/************************************************
 * Function-Pointer: Compare two doubles a and b
 ***********************************************/
typedef int (*compare_double)(double a, 
                              double b);


/************************************************
 * Function: Bubble sort algorithm
 *
 * Arguments:
 * *nodes    - NodeContanier
 * *indices  - Optional arrays for sorted indices
 *  N        - Number of nodes
 *  dir      - Geometric direction (0 - x
 *                                  1 - y)
 *  order    - Sorting order (0 - ascending 
 *                            1 - descending)
 ***********************************************/
int bubble_sort(NodeContainer *nodes,
                int           *indices,
                int            N,
                int            dir,
                int            order);

/************************************************
 * Function: Quick sort algorithm
 *
 * Arguments:
 * *nodes    - NodeContanier
 * *indices  - Optional arrays for sorted indices
 *  N        - Number of nodes
 *  dir      - Geometric direction (0 - x
 *                                  1 - y)
 *  order    - Sorting order (0 - ascending 
 *                            1 - descending)
 *
 ***********************************************/
int quick_sort(NodeContainer *nodes,
               int           *indices,
               int            N,
               int            dir,
               int            order);


#endif /* SORTING_H_INCLUDED */
