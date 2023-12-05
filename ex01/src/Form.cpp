/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:34:29 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/05 14:28:34 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {
    std::cout << CYAN << "Form Default constructor called for " << this->getName() <<
    " with sign grade of " << this->getSignGrade() << " and exec grade of " << this->getExecGrade() << RESET << std::endl;
}

Form::Form(const std::string &name, bool isSigned, int signGrade, int execGrade):
    _name(name), _signed(isSigned), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << CYAN << "Form Constructor called for " << this->getName() <<
    " with sign grade of " << this->getSignGrade() << " and exec grade of " << this->getExecGrade() << RESET << std::endl;
    if (this->_signGrade < 1 || this->_execGrade < 1)
        throw Form::GradeTooHighException();
    if (this->_signGrade > 150 || this->_execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &ref) : _name(ref.getName() + "_copy"), _signed(ref._signed), _signGrade(ref.getSignGrade()), _execGrade(ref.getExecGrade()) {
    std::cout << CYAN << "Form Copy constructor called to copy " << ref.getName() <<
    " to " << this->getName() << RESET << std::endl;
    *this = ref;
}

Form::~Form() {
    std::cout << CYAN << "Form Destructor called for " << this->getName() <<
        RESET << std::endl;
}

Form &Form::operator=(const Form &ref) {
    if (this == &ref)
        return *this;
    this->_signed = ref._signed;
    return *this;
}

const std::string &Form::getName() const {
    return this->_name;
}

bool Form::getSigned() const {
    return this->_signed;
}

int Form::getSignGrade() const {
    return this->_signGrade;
}

int Form::getExecGrade() const {
    return this->_execGrade;
}

const char *Form::NotSignedException::what() const throw() {
    return "Form is not signed";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &ref) {
    out << GREEN << "Form " << ref.getName() << " is ";
    if (ref.getSigned())
        out << "signed" << RESET << std::endl;
    else
        out << "not signed" << RESET << std::endl;
    return out;
}

void Form::beSigned(Bureaucrat &ref) {
    if (ref.getGrade() > this->getSignGrade())
        throw Bureaucrat::GradeTooLowException();
    if (!this->getSigned()) {
        std::cout << GREEN << "Form " << this->getName() << " was signed by "<< ref.getName() << RESET << std::endl;
        this->_signed = true;
    }
    else
        std::cout << RED << "Form " << this->getName() << " is already signed" << RESET << std::endl;
}