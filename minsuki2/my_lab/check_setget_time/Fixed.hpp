

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed {
	public:
		Fixed(void);
		~Fixed(void);
		const int&		getRawBits(void) const;
		void			setRawBits(int const& raw);
		void	count(const int& num);
	private:
		int					num_;
};

#endif
