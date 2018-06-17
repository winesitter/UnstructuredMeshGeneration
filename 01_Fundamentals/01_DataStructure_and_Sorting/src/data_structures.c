#include "data_structures.h"

/************************************************
 * Function: Initializes the global node 
 *           container
 *
 * Arguments:
 * *nodes    - NodeContanier to initialize
 *  N        - Number of nodes 
 ***********************************************/
int init_node_container(NodeContainer *nodes, 
                        int            N)
{
  nodes->xx = (double**) malloc(sizeof(double*) * N);
  int i;
  for (i=0; i<N; i++)
    nodes->xx[i] = (double*) malloc(sizeof(double) * 2);
  return 0;
}


/************************************************
 * Function: Initializes the free node 
 *           container
 *
 * Arguments:
 * *nodes    - NodeContanier to initialize
 *  N        - Number of nodes 
 ***********************************************/
int free_node_container(NodeContainer *nodes,
                        int            N)
{
  int i;
  for (i=0; i<N; i++)
    free(nodes->xx[i]);
  free(nodes->xx);
  return 0;
}





