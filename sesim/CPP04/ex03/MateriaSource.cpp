/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:16:30 by sesim             #+#    #+#             */
/*   Updated: 2022/12/03 22:00:01 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

AMateria*	MateriaSource::_floor[FLOOR_CNT];
int			MateriaSource::_floor_idx(0);

MateriaSource::MateriaSource() : idx_(0)
{
	std::cout << "[ MateriaSource Created ]" << std::endl;
	for (int i(0); i < 4; ++i)
		this->items_[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj) : idx_(0)
{
	std::cout << "[ MateriaSource Created ]" << std::endl;
	for (int i(0); i < 4; ++i)
		this->items_[i] = NULL;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	if (this == &obj)
		return (*this);
	for (int i(0); i < 4; ++i)
	{
		if (this->items_[i])
		{
			delete this->items_[i];
			this->items_[i] = NULL;
		}
		if (obj.items_[i])
			this->items_[i] = obj.items_[i]->clone();
	}
	this->idx_ = obj.idx_;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* source)
{
	if (!source)
		return ;
	if (this->idx_ > 3)
	{
		std::cout << "Skill slot is already Full!" << std::endl;
		delete source;
		return ;
	}
	std::cout << "You learn new materia : " << source->getType() << std::endl;
	this->items_[this->idx_] = source;
	this->idx_++;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int	max(this->idx_ - (this->idx_ > 3));

	if (this->idx_ == 0)
		return (NULL);
	for (int i(0); i < max; ++i)
	{
		if (type == this->items_[i]->getType())
		{
			std::cout << "You create " << type << std::endl;
			return (this->items_[i]);
		}
	}
	std::cout << "No match skill with " << type << std::endl;
	return (NULL);
}

int	MateriaSource::getFloorIdx(void)
{
	return (MateriaSource::_floor_idx);
}

bool	MateriaSource::putInFloor(AMateria *src)
{
	if (MateriaSource::_floor_idx >= FLOOR_CNT)
	{
		std::cout << "Floor is full!" << std::endl;
		return (false);
	}
	MateriaSource::_floor[MateriaSource::_floor_idx] = src;
	MateriaSource::_floor_idx++;
	return (true);
}

AMateria*	MateriaSource::putOutFloor(int idx)
{
	if (idx < 0 || idx >= FLOOR_CNT)
	{
		std::cout << "Wrong Idx!" << std::endl;
		return (NULL);
	}
	else if (MateriaSource::_floor_idx == 0 || idx > MateriaSource::_floor_idx)
	{
		std::cout << "Empty slot!" << std::endl;
		return (NULL);
	}
	if (idx == MateriaSource::_floor_idx)
	{
		AMateria	*res(MateriaSource::_floor[MateriaSource::_floor_idx]);

		delete MateriaSource::_floor[MateriaSource::_floor_idx];
		MateriaSource::_floor[MateriaSource::_floor_idx] = NULL;
		--MateriaSource::_floor_idx;
		return (res);
	}
	else
	{
		AMateria	*res(MateriaSource::_floor[idx]);

		for (int i(idx); i < MateriaSource::_floor_idx - 1; ++i)
		{
			delete MateriaSource::_floor[i];
			if (MateriaSource::_floor[i + 1])
				MateriaSource::_floor[i] = MateriaSource::_floor[i + 1]->clone();
		}
		MateriaSource::_floor[MateriaSource::_floor_idx] = NULL;
		--MateriaSource::_floor_idx;
		return (res);
	}
}

void	MateriaSource::clearFloor(void)
{
	for (int i(0); i < MateriaSource::_floor_idx; ++i)
	{
		delete MateriaSource::_floor[i];
		MateriaSource::_floor[i] = 0;
	}
}


MateriaSource::~MateriaSource()
{
	std::cout << "[ MateriaSource Destroyed ]" << std::endl;
	for (int i(0); i < 4; ++i)
	{
		if (this->items_[i])
		{
			std::cout << "wtf\n";
			delete this->items_[i];
			this->items_[i] = 0;
		}
	}
}
