/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:03:45 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 20:07:27 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
    std::cout << CYAN << "RobotomyRequestForm default constructor called for " 
    << this->getName() << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << CYAN << "RobotomyRequestForm constructor called for " 
    << this->getName() << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : AForm(ref) {
    std::cout << CYAN << "RobotomyRequestForm copy constructor called for " 
    << this->getName() << RESET << std::endl;
    *this = ref;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref) {
    if (this == &ref)
        return *this;
    this->_target = ref._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << CYAN << "RobotomyRequestForm destructor called for " 
    << this->getName() << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!this->getSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    static bool first = true;
    if (first) {
        srand(time(NULL));
        first = false;
    }
    std::cout << YELLOW << "Brrrrrrr" << RESET << std::endl;
    if (rand() % 2)
        std::cout << YELLOW << this->_target << " has been robotomized successfully" << RESET << std::endl;
    else
        std::cout << YELLOW << this->_target << " has been failed to robotomized" << RESET << std::endl;
}