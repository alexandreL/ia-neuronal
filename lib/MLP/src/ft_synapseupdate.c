/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   ft_synapseupdate.c                                (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/08/12 18:29:51 by alex             |           |     //    */
/*   Updated: 2015/08/14 18:31:48 by alex              \         /    //      */
/*                                                      ///  ///   --         */
/*                                                                            */
/* ************************************************************************** */

int	ft_synapseupdate(double node_prev, double node_next, double coef_learn, double *addr_synapse)
{
  *addr_synapse += node_prev * node_next * coef_learn;
  return (0);
}
