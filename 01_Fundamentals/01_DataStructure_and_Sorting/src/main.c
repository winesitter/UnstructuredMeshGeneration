#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "data_structures.h"



int main(int argc, char *argv[])
{
  // Create global node container
  NodeContainer globalNodes;
  init_node_container(&globalNodes, MAX_NODES);

  // Free global node container
  free_node_container(&globalNodes, MAX_NODES);

  printf("FINISHED");
  




  return 0;

}

