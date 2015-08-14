/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   ft_propagation.c                                  (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/08/12 18:29:45 by alex             |           |     //    */
/*   Updated: 2015/08/14 18:31:50 by alex              \         /    //      */
/*                                                      ///  ///   --         */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>

double	logistic(double som)
{
  return (1.0 / (exp(som * -1) + 1.0));
}

int	ft_propagation(double *node_prev, double *synapse, double *addr_node_next, int nb_node_next)
{
  double	result;
  int		i;

  result = 0;
  i = 0;
  while (i < nb_node_next)
    {
      result += node_prev[i] * synapse[i];
      ++i;
    }
  *addr_node_next = logistic(result);
  return (0);
}
