#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include <iostream>

class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap(void);
	~FragTrap();
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	std::string		getName(void) const;
	unsigned int	getHitPoint(void) const;
	unsigned int	getEnergyPoint(void) const;
	unsigned int	getAttackDamage(void) const;
	void			highFivesGuys(void);
};

#endif