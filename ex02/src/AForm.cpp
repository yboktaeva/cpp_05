/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:14:25 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 19:47:02 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {
    std::cout << CYAN << "AForm Default constructor called for " << this->getName() <<
    " with sign grade of " << this->getSignGrade() << " and exec grade of " << this->getExecGrade() << RESET << std::endl;
}

AForm::AForm(const std::string &name, int signGrade, int execGrade):
    _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << CYAN << "AForm Constructor called for " << this->getName() <<
    " with sign grade of " << this->getSignGrade() << " and exec grade of " << this->getExecGrade() << RESET << std::endl;
    if (this->_signGrade < 1 || this->_execGrade < 1)
        throw AForm::GradeTooHighException();
    if (this->_signGrade > 150 || this->_execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &ref) : _name(ref.getName() + "_copy"), _signed(ref._signed), _signGrade(ref.getSignGrade()), _execGrade(ref.getExecGrade()) {
    std::cout << CYAN << "AForm Copy constructor called to copy " << ref.getName() <<
    " to " << this->getName() << RESET << std::endl;
    *this = ref;
}

AForm::~AForm() {
    std::cout << CYAN << "AForm Destructor called for " << this->getName() <<
        RESET << std::endl;
}

AForm &AForm::operator=(const AForm &ref) {
    if (this == &ref)
        return *this;
    this->_signed = ref._signed;
    return *this;
}

const std::string &AForm::getName() const {
    return this->_name;
}

bool AForm::getSigned() const {
    return this->_signed;
}

int AForm::getSignGrade() const {
    return this->_signGrade;
}

int AForm::getExecGrade() const {
    return this->_execGrade;
}

const char *AForm::NotSignedException::what() const throw() {
    return "AForm is not signed";
}

const char *AForm::SignedException::what() const throw() {
    return "AForm is already signed";
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "AForm Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "AForm Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const AForm &ref) {
    out << GREEN << "AForm " << ref.getName() << " is ";
    if (ref.getSigned())
        out << "signed" << RESET << std::endl;
    else
        out << "not signed" << RESET << std::endl;
    return out;
}

void AForm::beSigned(Bureaucrat &ref) {
    if (ref.getGrade() > this->getSignGrade())
        throw Bureaucrat::GradeTooLowException();
    if (this->getSigned())
        throw AForm::SignedException();
    std::cout << GREEN << "AForm " << this->getName() << " was signed by "<< ref.getName() << RESET << std::endl;
    this->_signed = true;
}
