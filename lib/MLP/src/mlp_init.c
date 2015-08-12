/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   mlp_init.c                                        (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/08/05 00:13:49 by alex             |           |     //    */
/*   Updated: 2015/08/12 18:06:24 by alex              \         /    //      */
/*                                                      ///  ///   --         */
/*                                                                            */
/* ************************************************************************** */
#include "ia_mlp.h"
#include "gcm.h"
#include <stdlib.h>

t_ia_mlp	*get_brain()
{
  static t_ia_mlp	brain = {NULL, 0, NULL, NULL, NULL};

  return (&brain);
}

void		init_struct_layer(t_layer *layer)
{
  layer->synapse = NULL;
  layer->x = 0;
  layer->y = 0;
  layer->next = NULL;
  layer->prev = NULL;
}

int		init_mlp(int nb_layer)
{
  t_ia_mlp	*brain;
  t_layer	*layer;

  brain = get_brain();
  if (nb_layer < 3)
    return (-1);
  brain->nb_layer = nb_layer;
  if ((brain->network = get_new_obj(sizeof(t_layer), MLP)) == NULL)
    return (-1);
  init_struct_layer(brain->network);
  layer = brain->network;
  while (0 < nb_layer--)
    {
      if ((layer->next = get_new_obj(sizeof(t_layer), MLP)) == NULL)
	return (-1);
      init_struct_layer(layer->next);      
      layer->next->prev = layer;
      layer = layer->next;
    }
  return (0);
}

int		init_input_output(int nb_input_node, int nb_output_node)
{
  t_ia_mlp	*brain;
  t_layer	*layer;

  brain = get_brain();
  layer = brain->network;
  layer->x = nb_input_node;
  while (layer->next)
    layer = layer->next;
  layer->y = nb_output_node;
  return (0);
}

int		add_hidden_layer(int nb_node)
{
  static t_layer	*layer = NULL;

  if (layer == NULL)
    layer = get_brain()->network;
  if (!layer || !(layer->next))
    return (-1);
  layer->y = nb_node;
  if ((creat_double_tabtabinv(layer->x, layer->y)) == NULL)
  return (-1);
  layer = layer->next;
  layer->x = nb_node;
  if (!(layer->next))
    if ((creat_double_tabtabinv(layer->x, layer->y)) == NULL)
      return (-1);
  return (0);
}
