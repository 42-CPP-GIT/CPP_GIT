#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include <iostream>

# define SCAV_HP 100
# define SCAV_EP 50
# define SCAV_AD 20

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap(void);
	~ScavTrap();
	ScavTrap(const ScavTrap &obj);
	ScavTrap	&operator=(ScavTrap const &obj);
	void		attack(const std::string& target);
	void		guardGate();
};

#endif