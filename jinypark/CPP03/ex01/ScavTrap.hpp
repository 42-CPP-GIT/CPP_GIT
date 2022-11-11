#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include <iostream>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap(void);
	~ScavTrap();
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	std::string		getName(void) const;
	unsigned int	getHitPoint(void) const;
	unsigned int	getEnergyPoint(void) const;
	unsigned int	getAttackDamage(void) const;
	void guardGate();
};

#endif