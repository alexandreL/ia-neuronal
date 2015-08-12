/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   ia_mlp.h                                          (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/08/05 00:14:30 by alex             |           |     //    */
/*   Updated: 2015/08/12 18:06:10 by alex              \         /    //      */
/*                                                      ///  ///   --         */
/*                                                                            */
/* ************************************************************************** */

#ifndef IA_MLP_H_
# define IA_MLP_H_

# define MLP 200

typedef struct s_layer t_layer;

struct	s_layer
{
  double	**synapse;
  int		x;
  int		y;
  t_layer	*next;
  t_layer	*prev;
};

typedef struct	s_ia_mlp
{
  t_layer	*network;
  int		nb_layer;
  int		(*propag)(double *node_prev, double *synapse, double *addr_node_next, int nb_node_next);
  int		(*backpropag)(double *node_prev, double *synapse, double node_value, double *addr_node_next, int nb_node_next);
  int		(*synapseupdate)(double node_prev, double node_next, double coef_learn, double *addr_synapse);
}		t_ia_mlp;

t_ia_mlp	*get_brain();
double		**creat_double_tabtabinv(int x, int y);
int		ft_synapseupdate(double node_prev, double node_next, double coef_learn, double *addr_synapse);
int		ft_back_propagation(double *node_prev, double *synapse, double node_value, double *addr_node_next, int nb_node_next);
int		ft_propagation(double *node_prev, double *synapse, double *addr_node_next, int nb_node_next);

#endif /* IA_MLP_H_ */
