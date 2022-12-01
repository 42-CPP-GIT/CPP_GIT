/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:53:48 by seungsle          #+#    #+#             */
/*   Updated: 2022/11/14 17:20:52 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_MANAGER_HPP
# define FILE_MANAGER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class FileManager
{
private:
	std::string _fileName;
	std::string _content;
public:
	FileManager(std::string fileName);
	FileManager();
	~FileManager();
	void	readFile(void);
	void	writeFile(void);
	void	setFileName(std::string fileName);
	void	setContent(std::string content);
	const std::string	getFileName(void);
	const std::string getContent(void);
};

#endif