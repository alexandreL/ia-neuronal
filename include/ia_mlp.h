/* ************************************************************************** */
/*                                                                            */
/*                                                      /\ ___ /\             */
/*   ia_mlp.h                                          (  o   o  )            */
/*                                                      \  >#<  /             */
/*   By: alex <alexandre.loubeyres@gmail.com>           /       \             */
/*                                                     /         \       ^    */
/*   Created: 2015/08/05 00:14:30 by alex             |           |     //    */
/*   Updated: 2015/08/05 01:48:45 by alex              \         /    //      */
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
};

typedef struct	s_ia_mlp
{
  t_layer	*network;
  int		nb_layer;
}		t_ia_mlp;

#endif /* IA_MLP_H_ */
