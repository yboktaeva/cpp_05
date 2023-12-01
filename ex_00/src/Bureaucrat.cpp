/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:40:46 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/01 19:09:40 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << BLUE << "Bureaucrat Default constructor called for " << this->getName() <<
    "with grade of " << this->getGrade() << RESET << std::endl;
}

~Bureaucrat::Bureaucrat() {
    std::cout << BLUE << "Bureaucrat Destructor called for " << this->getName() <<
        RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name) : _name(name) {
    std::cout << BLUE << "Bureaucrat Constructor called for " << this->getName() <<
    "with grade of " << this->getGrade() << RESET << std::endl;
    _grade = this->setGrade(150);
}

Bureaucrat::Bureaucrat(int grade) : _name("default"), _grade(this->setGrade(grade)) {
    std::cout << BLUE << "Bureaucrat Constructor called for " << this->getName() <<
    "with grade of " << this->getGrade() << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(this->setGrade(grade)) {
    std::cout << BLUE << "Bureaucrat Constructor called for " << this->getName() <<
    "with grade of " << this->getGrade() << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : _name(ref.getName() + "_copy") {
    std::cout << BLUE << "Bureaucrat Copy constructor called to copy " << ref.getName() <<
    "to " << this->getName() << RESET << std::endl;
    *this = ref;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref) {
    if (this == &ref)
        return (*this);
    this->_grade = ref._grade;
    return (*this);
}

const std::string &Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}

void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

int Bureaucrat::setGrade(int grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    return (grade);
}

char const *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}