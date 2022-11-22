#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include <iostream>

# define FRAG_HP 100
# define FRAG_EP 100
# define FRAG_AD 30

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &obj);
	FragTrap	&operator=(FragTrap const &obj);
	void		highFivesGuys(void);
};

#endif