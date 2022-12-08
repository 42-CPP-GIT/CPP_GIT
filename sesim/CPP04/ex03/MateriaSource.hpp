/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:16:30 by sesim             #+#    #+#             */
/*   Updated: 2022/12/08 17:29:16 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

typedef	enum	e_mac
{
	FLOOR_CNT	=	100
}	t_mac;

class MateriaSource : public IMateriaSource
{
	private:
		static AMateria*	_floor[FLOOR_CNT];
		AMateria			*items_[4];
		static int			_floor_idx;
		int					idx_;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& obj);
		MateriaSource& operator=(const MateriaSource& obj);
		virtual void		learnMateria(AMateria* source);
		virtual AMateria*	createMateria(std::string const & type);
		static int			getFloorIdx(void);
		static bool			putInFloor(AMateria *src);
		static AMateria*	putOutFloor(int idx);
		static void			clearFloor(void);
		virtual ~MateriaSource();
};

#endif
