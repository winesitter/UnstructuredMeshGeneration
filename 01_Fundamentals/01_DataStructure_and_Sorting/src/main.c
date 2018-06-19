#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "data_structures.h"
#include "sorting.h"



int main(int argc, char *argv[])
{
  // Create global node container
  NodeContainer globalNodes;
  init_node_container(&globalNodes, MAX_NODES);

  // Random distribution for nodes
  double xmin = 0.0;
  double xmax = 1.0;
  double ymin = 0.0;
  double ymax = 1.0;
  int    N    = 10;

  srand( time( NULL));
  int i;
  printf("\n==== Initial distribution ====\n");
  for (i=0; i<N; i++)
  {
    globalNodes.xx[i][0] = (double) rand()/RAND_MAX * (xmax-xmin) - xmin;
    globalNodes.xx[i][1] = (double) rand()/RAND_MAX * (ymax-ymin) - ymin;
    printf("xx[%d] = (%lf, %lf) \n", i, globalNodes.xx[i][0], globalNodes.xx[i][1]);
  }

  // --- Sort nodes for x values ---
  int *indices = (int*) malloc(sizeof(int) * N);
  quick_sort(&globalNodes, indices, N, 0, 0);
  printf("\n==== Sorted for x ====\n");
  for (i=0; i<N; i++)
    printf("xx[%d] = (%lf, %lf) \n", indices[i], globalNodes.xx[i][0], globalNodes.xx[i][1]);

  // --- Sort nodes for y values ---
  quick_sort(&globalNodes, indices, N, 1, 1);
  printf("\n==== Sorted for y ====\n");
  for (i=0; i<N; i++)
    printf("xx[%d] = (%lf, %lf) \n", indices[i], globalNodes.xx[i][0], globalNodes.xx[i][1]);

  // Free global node container
  free_node_container(&globalNodes, MAX_NODES);

  printf("\nFINISHED\n");
  




  return 0;

}

