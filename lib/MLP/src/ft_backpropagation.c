/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   ft_backpropagation.c                              (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/08/12 18:29:37 by alex             |           |     //    */
/*   Updated: 2015/08/14 18:31:53 by alex              \         /    //      */
/*                                                      ///  ///   --         */
/*                                                                            */
/* ************************************************************************** */

int	ft_back_propagation(double *node_prev, double *synapse, double node_value, double *addr_node_next, int nb_node_next)
{
  double	som;
  double	result;
  int		i;

  result = 0;
  i = 0;
  som = 0;
  result = node_value * (1.0 - node_value);
  while (i < nb_node_next)
    {
      som += node_prev[i] * synapse[i];
      ++i;
    }
  *addr_node_next = result * som;
  return (0);
}
