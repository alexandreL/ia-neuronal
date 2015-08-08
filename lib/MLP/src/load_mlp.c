/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   load_mlp.c                                        (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/08/05 10:20:59 by alex             |           |     //    */
/*   Updated: 2015/08/05 10:21:00 by alex              \         /    //      */
/*                                                      ///  ///   --         */
/*                                                                            */
/* ************************************************************************** */

#include "ia_mlp.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int		random_load_network()
{
  t_layer	*layer;
  int		x;
  int		y;

  layer = get_brain()->network;
  srand(getpid() + time(NULL));
  while (layer)
    {
      y = 0;
      while (y < layer->y)
	{
	  x = 0;
	  while (x < layer->x)
	    layer->synapse[y][x++] = rand();
	  ++y;
	}
      layer = layer->next;
    }
  return (0);
}

