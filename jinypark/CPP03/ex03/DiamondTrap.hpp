#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	name_;
public:
	DiamondTrap(std::string name);
	DiamondTrap(void);
	~DiamondTrap();
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	std::string		getName(void) const;
	unsigned int	getHitPoint(void) const;
	unsigned int	getEnergyPoint(void) const;
	unsigned int	getAttackDamage(void) const;
	void			whoAmI(void);
	void			printStat(void);
};

#endif