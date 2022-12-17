/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:30:17 by minsuki2          #+#    #+#             */
/*   Updated: 2022/12/17 18:09:27 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

# define MSG_CONSTRUCT		"[Constructor]"
# define MSG_DESTRUCT		"[Destructor]"
# define MSG_ANNOUNCE		"[Announce]"
# define MSG_CLAPTRAP_BORN	"Seriously? Claptrap? You'vs heard about his weird Actions Skill, right? This is REALLY what you want?"
# define MSG_GONE			"is gone..."
# define MSG_CLAPTRAP		"ClapTrap"
# define MSG_GETRB			"getRawBits member function"
# define MSG_ATTACK			"attacks"
# define MSG_TAKE_DAMAGE	"is taken damage"
# define MSG_CAUSE			"causinig"
# define MSG_USE			"Using"
# define MSG_LEFT			"lefting"
# define MSG_INCREASE		"increasing"
# define MSG_HP				"HP"
# define MSG_P_O_D			"points of damage!"
# define MSG_P_O_E			"points of energy!"
# define MSG_NO_HP			"can not do anything because HP is 0!"
# define MSG_FULL_HP			"do not need to do because HP is FULL!"
# define MSG_NO_EP			"can not do anything because EP is 0!"
# define MSG_DIED			"is already dead..."
# define MSG_REPAIR			"is repaired by"


enum e_max { MAX_HP = 10, MAX_EP = 10, MAX_AD = 0 };

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& obj);
		ClapTrap& operator=(const ClapTrap& obj);
		virtual ~ClapTrap(void);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		checkStatus(void);
	protected:
		std::string					bot_name_;
		unsigned int				health_point_;
		unsigned int				energy_point_;
		unsigned int				attack_damage_;
		// static unsigned int			max_hp_;
		// static unsigned int			max_ep_;
		// static unsigned int			max_ad_;
		const unsigned int			max_hp_;
		const unsigned int			max_ep_;
		const unsigned int			max_ad_;
};

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#endif
