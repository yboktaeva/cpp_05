/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:03:48 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 15:29:28 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137) {
    std::cout << CYAN << "ShrubberyCreationForm default constructor called for " 
    << this->getName() << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", false, 25, 5), _target(target) {
    std::cout << CYAN << "ShrubberyCreationForm constructor called for " 
    << this->getName() << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : AForm(ref) {
    std::cout << CYAN << "ShrubberyCreationForm copy constructor called for " 
    << this->getName() << RESET << std::endl;
    *this = ref;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref) {
    if (this == &ref)
        return *this;
    this->_target = ref._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << CYAN << "ShrubberyCreationForm destructor called for " 
    << this->getName() << RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!this->getSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    std::ofstream file((this->_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("File open error");
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "    \\====/    " << std::endl;
    file << std::endl;
}
