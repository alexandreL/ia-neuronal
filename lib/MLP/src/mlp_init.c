/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   mlp_init.c                                        (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/08/05 00:13:49 by alex             |           |     //    */
/*   Updated: 2015/08/05 11:16:25 by alex              \         /    //      */
/*                                                      ///  ///   --         */
/*                                                                            */
/* ************************************************************************** */
#include "ia_mlp.h"
#include "gcm.h"
#include <stdlib.h>

t_ia_mlp	*get_brain()
{
  static t_ia_mlp	brain = {NULL, 0};

  return (&brain);
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
  brain->network->synapse = NULL;
  brain->network->x = 0;
  brain->network->y = 0;
  brain->network->next = NULL;
  layer = brain->network;
  while (0 < nb_layer--)
    {
      if ((layer->next = get_new_obj(sizeof(t_layer), MLP)) == NULL)
	return (-1);
      layer->next->synapse = NULL;
      layer->next->x = 0;
      layer->next->y = 0;
      layer->next->next = NULL;
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

double		**creat_double_tabtab(int x, int y)
{
  double	**data;
  int		i;
  int		j;

  if ((data = get_new_obj(sizeof(double *) * y, MLP)) == NULL)
    return (NULL);
  i = 0;
  while (i < y)
    {
      if ((data[i] = get_new_obj(sizeof(double) * x, MLP)) == NULL)
	return (NULL);
      j = 0;
      while (j < x)
	data[i][j++] = 0;
      ++i;
    }
  return (data);
}

int		add_hidden_layer(int nb_node)
{
  static t_layer	*layer = NULL;

  if (layer == NULL)
    layer = get_brain()->network;
  if (!layer || !(layer->next))
    return (-1);
  layer->y = nb_node;
  if ((creat_double_tabtab(layer->x, layer->y)) == NULL)
  return (-1);
  layer = layer->next;
  layer->x = nb_node;
  if (!(layer->next))
    if ((creat_double_tabtab(layer->x, layer->y)) == NULL)
      return (-1);
  return (0);
}
