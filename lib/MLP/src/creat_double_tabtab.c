/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   creat_double_tabtab.c                             (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/08/12 18:04:55 by alex             |           |     //    */
/*   Updated: 2015/08/12 18:04:58 by alex              \         /    //      */
/*                                                      ///  ///   --         */
/*                                                                            */
/* ************************************************************************** */

#include "ia_mlp.h"

double		**creat_double_tabtabinv(int x, int y)
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

