/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:32:59 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 19:57:30 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
    std::cout << CYAN << "PresidentialPardonForm default constructor called for " 
    << this->getName() << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << CYAN << "PresidentialPardonForm constructor called for " 
    << this->getName() << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm(ref) {
    std::cout << CYAN << "PresidentialPardonForm copy constructor called for " 
    << this->getName() << RESET << std::endl;
    *this = ref;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref) {
    if (this == &ref)
        return *this;
    this->_target = ref._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << CYAN << "PresidentialPardonForm destructor called for " 
    << this->getName() << RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!this->getSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    std::cout << YELLOW << this->_target << " has been pardoned by Zafod Beeblebrox" << RESET << std::endl;
}