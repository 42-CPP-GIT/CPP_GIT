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
	DiamondTrap(const DiamondTrap &obj);
	DiamondTrap	&operator=(DiamondTrap const &obj);
	void		whoAmI(void);
};

#endif