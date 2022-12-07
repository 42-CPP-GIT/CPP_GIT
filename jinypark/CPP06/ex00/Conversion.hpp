#ifndef CONVERSION_HPP
#define CONVERSION_HPP

# include <iostream>
# include <cmath>
# define ENDL "\n"

class Conversion
{
private:
	char	valueChar_;
	int		valueInt_;
	float	valueFloat_;
	double	valueDouble_;
	Conversion();
public:
	Conversion(const char* str);
	~Conversion();
	Conversion(const Conversion& obj);
	Conversion& operator=(const Conversion& obj);
	char	getChar() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble() const;
};

std::ostream& operator<<(std::ostream& os, const Conversion& obj);

#endif