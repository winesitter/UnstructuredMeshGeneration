#include "sorting.h"


/************************************************
 * Function: Switch nodes
 *
 * Arguments:
 * *nodes    - NodeContanier
 ***********************************************/
static int switch_nodes(NodeContainer *nodes,
                        int            r,
                        int            k)
{
  const double tmpx = nodes->xx[r][0];
  const double tmpy = nodes->xx[r][1];
  nodes->xx[r][0]   = nodes->xx[k][0];
  nodes->xx[r][1]   = nodes->xx[k][1];
  nodes->xx[k][0]   = tmpx;
  nodes->xx[k][1]   = tmpy;
  return 0;
}

/************************************************
 * Function: Switch indices
 *
 * Arguments:
 * *indices  - Array containing node indices
 ***********************************************/
static int switch_indices(int *indices,
                          int  r,
                          int  k)
{
  if (indices == NULL)
    return 0;

  const int tmp = indices[r];
  indices[r] = indices[k];
  indices[k] = tmp;
  return 0;
}

/************************************************
 * Function: Comparison for sorting algorithms
 *           with ascending order.
 *           Returns: -1 if a is larger than b
 *                     1 if a is smaller than b
 ***********************************************/
static int ascending_order(double a, double b)
{
  return (a > b) - (a < b);
}

/************************************************
 * Function: Comparison for sorting algorithms
 *           with descending order.
 *           Returns:  1 if a is larger than b
 *                    -1 if a is smaller than b
 ***********************************************/
static int descending_order(double a, double b)
{
  return (a < b) - (a > b);
}

/************************************************
 * Function: Partitioning step for quick sort 
 *           algorithm
 *
 * Arguments:
 * *nodes    - NodeContanier
 * *indices  - Optional array for indices
 *  cmp      - Function pointer for comparison 
 *  dir      - Geometric direction (0 - x
 *                                  1 - y)
 *  p, r     - Quick sort indices
 ***********************************************/
static int qs_partition(NodeContainer *nodes,
                        int           *indices,
                        compare_double cmp,
                        int            dir,
                        int            p,
                        int            r)
{
  int i = p-1;
  int j;
  for (j=p; j<r; j++)
    if (cmp(nodes->xx[r][dir], nodes->xx[j][dir]) > 0)
    {
      i++;
      switch_nodes(nodes, i, j);
      switch_indices(indices, i, j);
    }

  switch_nodes(nodes, i+1, r);
  switch_indices(indices, i+1, r);

  return i+1;
}

/************************************************
 * Function: Sorting step for quick sort 
 *           algorithm
 *
 * Arguments:
 * *nodes    - NodeContanier
 * *indices  - Optional array for indices
 *  cmp      - Function pointer for comparison 
 *  dir      - Geometric direction (0 - x
 *                                  1 - y)
 *  p, r     - Quick sort indices
 ***********************************************/
static int qs_sorting(NodeContainer *nodes,
                      int           *indices,
                      compare_double cmp,
                      int            dir,
                      int            p,
                      int            r)
{
  if (p < r)
  {
    int q = qs_partition(nodes, indices, cmp, dir, p, r);
    qs_sorting(nodes, indices, cmp, dir, p, q-1);
    qs_sorting(nodes, indices, cmp, dir, q+1, r);
  }
  return 0;
}

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
 *
 * Bubble sort algorithm:
 * Go from left to right through the array, 
 * Compare the actual element with its right 
 * neighbour. If the neighbour element is larger,
 * switch it to the left.
 ***********************************************/
int bubble_sort(NodeContainer *nodes,
                int           *indices,
                int            N,
                int            dir,
                int            order)
{
  int i,j;

  // Initialize indices
  if (indices != NULL)
    for (i=0; i<N; i++)
      indices[i] = i;

  compare_double cmp;
  if (order == 0)
    cmp = ascending_order;
  else
    cmp = descending_order;

  for (i = 0; i < N; i++)
    for (j = 0; j < N - 1; j++)
      if (cmp(nodes->xx[j][dir], nodes->xx[j+1][dir]) > 0)
      {
        switch_nodes(nodes, j+1, j);
        switch_indices(indices, j+1, j);
      }

  return 0;
}

/************************************************
 * Function: Quick sort algorithm
 *
 * Arguments:
 * *nodes    - NodeContanier
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
               int            order)
{
  /*********************************************
   * Initialize indices
   ********************************************/
  int i;
  if (indices != NULL)
    for (i=0; i<N; i++)
      indices[i] = i;

  /*********************************************
   * Initialize comparison function
   ********************************************/
  compare_double cmp = descending_order;

  /*********************************************
   * Do quicksort
   ********************************************/
  qs_sorting(nodes, indices, cmp, dir, 0, N);
  
  /*********************************************
   * Reverse order if ascending
   ********************************************/
  if (order == 0)
    for (i=0; i<N/2; i++)
    {
      switch_nodes(nodes, i, N-i-1);
      switch_indices(indices, i, N-i-1);
    }

  return 0;
}



                
