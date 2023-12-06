/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:40:46 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 19:56:09 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << MAGENTA << "Bureaucrat Default constructor called for " << this->getName() <<
    " with grade of " << this->getGrade() << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    std::cout << MAGENTA << "Bureaucrat Constructor called for " << this->getName() <<
    " with grade of " << this->getGrade() << RESET << std::endl;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : _name(ref.getName() + "_copy") {
    std::cout << MAGENTA << "Bureaucrat Copy constructor called to copy " << ref.getName() <<
    " to " << this->getName() << RESET << std::endl;
    *this = ref;
}

Bureaucrat::~Bureaucrat() {
    std::cout << MAGENTA << "Bureaucrat Destructor called for " << this->getName() <<
        RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref) {
    if (this == &ref)
        return (*this);
    this->_grade = ref._grade;
    return *this;
}

const std::string &Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

char const *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat Grade is too high";
}

char const *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &ref) {
    out << GREEN << ref.getName() << ", bureaucrat grade " << ref.getGrade() << RESET << std::endl;
    return out;
}

void Bureaucrat::signForm(AForm &ref) {
    try {
        ref.beSigned(*this);
        std::cout << GREEN << this->getName() << " signed " << ref.getName() << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << this->getName() << " cannot sign " << ref.getName() << " because " << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << GREEN << this->getName() << " executed " << form.getName() << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << this->getName() << " cannot execute " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}