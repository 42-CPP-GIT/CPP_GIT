/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:24:13 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/22 19:52:21 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <iomanip>
# include <string>

# define MSG_ENDL		'\n'
# define MSG_LINE		"------------------------------------------------------"
# define MSG_CREATE		"Sed is created"
# define MSG_DESTROY	"Sed is destoryed"
# define MSG_SED	"\
  ██╗    ███████╗███████╗██████╗     ██╗	\n\
 ██╔╝    ██╔════╝██╔════╝██╔══██╗    ╚██╗	\n\
██╔╝     ███████╗█████╗  ██║  ██║     ╚██╗	\n\
╚██╗     ╚════██║██╔══╝  ██║  ██║     ██╔╝	\n\
 ╚██╗    ███████║███████╗██████╔╝    ██╔╝	\n\
  ╚═╝    ╚══════╝╚══════╝╚═════╝     ╚═╝"


class Sed {
	public:
		Sed(const std::string& name, const std::string& before, const std::string& afeter);
		~Sed(void);
		void				fileDisplay(void);
		const std::string&	getFileName(void);
		const std::string&	getBefore(void);
		const std::string&	getAfter(void);
		const std::string&	getFileScripts(void);
		void				setFileScripts(std::string input);
		void				replace(void);

	private:
		Sed(void);
		static std::string makeFileString(std::ifstream& ifs);
		const std::string&	file_name_;
		const std::string&	before_;
		const std::string&	after_;
		std::string			file_scripts_;
};

#endif



