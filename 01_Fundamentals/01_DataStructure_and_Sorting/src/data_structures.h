#ifndef DATA_STRUCTURES_H_INCLUDED
#define DATA_STRUCTURES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*===============================================
 * Definition of global constans
 *=============================================*/
#define MAX_NODES 1000

/************************************************
 * Struct: Container for mesh nodes
 ***********************************************/
typedef struct NodeContainer
{
  double **xx;
} NodeContainer;



/************************************************
 * Function: Initializes the global node 
 *           container
 *
 * Arguments:
 * *nodes    - NodeContanier to initialize
 *  N        - Number of nodes 
 ***********************************************/
int init_node_container(NodeContainer *nodes, 
                        int            N);

/************************************************
 * Function: Initializes the free node 
 *           container
 *
 * Arguments:
 * *nodes    - NodeContanier to initialize
 *  N        - Number of nodes 
 ***********************************************/
int free_node_container(NodeContainer *nodes,
                        int            N);

#endif /* DATA_STRUCTURES_H_INCLUDED */
