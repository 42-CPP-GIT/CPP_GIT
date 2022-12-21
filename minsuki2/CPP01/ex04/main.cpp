/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:43:54 by minsuki2          #+#    #+#             */
/*   Updated: 2022/11/23 19:16:31 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

static std::string	_myGetLine(const std::string &msg) {
	std::string	str;
	do {
		std::cout << msg;
		if (!std::getline(std::cin, str)) {
			std::cin.clear();			// 버퍼 안에 비워주기
			std::clearerr(stdin);		// error bit 재설정해준다.
			std::cout << std::endl;
		}
	} while (str.empty());
	return (str);
}
static bool askIsOkay(void) {
		std::string	question;
		do
			question = _myGetLine("Really want?(y / n) : ");
		while (question != "y" && question != "n");
		if (question == "n")
			return false;
		return true;
}

static bool checkIfstream(std::ifstream& ifs, Sed& target) {
	if (!ifs.is_open()) {
		std::cerr << "[Error] " << target.getFileName() << " couldn't open" << MSG_ENDL;
		return false;
	}
	else if (ifs.fail()) {			// ex) 파일이 없을 때
		std::cerr << "[Error] ifstream open() is failed" << MSG_ENDL;
		return false;
	}
	return true;
}

static bool checkOfstream(std::ofstream& ofs, Sed& target) {
	if (!ofs.is_open()) {
		std::cerr << "[Error] " << target.getFileName() + ".replace" \
											<< " couldn't open" << MSG_ENDL;
		return false;
	}
	else if (ofs.fail()) {			 // ex) 용량이 꽉찼을 때
		std::cerr << "[Error] ifstream open() is failed" << MSG_ENDL;
		return false;
	}
	return true;
}

static std::string _makeFileString(std::ifstream& ifs) {
	std::string str;
	std::string tmp;
	while (std::getline(ifs, tmp, '\0'))
		str += tmp;
	return (str);
}

static void	_fileDisplay(Sed& target) {
	std::cout << MSG_ENDL << MSG_ENDL << MSG_LINE << MSG_ENDL;
	std::cout << "* Filename : " << '"' << target.getFileName() << '"' << MSG_ENDL;
	std::cout << MSG_LINE << MSG_ENDL;
	std::cout << target.getFileScripts() << MSG_ENDL;
	std::cout << MSG_LINE << MSG_ENDL << MSG_ENDL;
}

static void	_chagneDisplay(Sed& target) {
	std::cout << "* Before > " << '"' << target.getBefore() << '"' \
			  << "      ==>       " \
			  << "After > " << '"' << target.getAfter() << '"' << MSG_ENDL;
}

int main(int argc, char *argv[]) {
	std::cout << MSG_SED << "  by minsuki2" << std::endl;
	if (argc != 4) {
		std::cerr << "[Error] Number of arguments is wrong" << MSG_ENDL;
		return 1;
	}
	Sed	target(argv[1], argv[2], argv[3]);
	if (target.getFileName().empty()
		|| target.getBefore().empty()) {
		std::cerr << "[Error] Something is Empty" << MSG_ENDL;
		return 1;
	}
	std::ifstream ifs;
	ifs.open(target.getFileName(), std::ifstream::in);
	if (!checkIfstream(ifs, target))
		return 1;
	target.setFileScripts(_makeFileString(ifs));
	_fileDisplay(target);
	_chagneDisplay(target);
	ifs.close();
	if (!askIsOkay())
		return std::cout << "\n~Good Bye~" << std::endl, 0;		// Error는 아니라고 생각
	std::ofstream ofs;
	ofs.open (target.getFileName() + ".replace", std::ofstream::out);
	if (!checkOfstream(ofs, target))
		return 1;
	target.replace();
	_fileDisplay(target);
	ofs << target.getFileScripts();
	ofs.close();
	return 0;
}
