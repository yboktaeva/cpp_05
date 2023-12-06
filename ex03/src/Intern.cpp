/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:03:25 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 20:20:24 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << CYAN << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &ref) {
    std::cout << CYAN << "Intern copy constructor called" << RESET << std::endl;
    *this = ref;
}

Intern &Intern::operator=(const Intern &ref) {
    if (this == &ref)
        return *this;
    return *this;
}

Intern::~Intern() {
    std::cout << YELLOW << "Intern destructor called" << RESET << std::endl;
}

AForm *Intern::makeShrubberyForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialForm(std::string target) {
    return new PresidentialPardonForm(target);
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Intern cannot create Form because of unknown form name";
}

AForm *Intern::makeForm(std::string formName, std::string target) {
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(Intern::*formFuncs[3])(std::string target) = {&Intern::makeShrubberyForm, &Intern::makeRobotomyForm, &Intern::makePresidentialForm};
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << GREEN << "Intern creates " << formName << RESET << std::endl;
            return (this->*formFuncs[i])(target);
        }
    }
    if (formName != "shrubbery creation" && formName != "robotomy request" && formName != "presidential pardon")
        throw FormNotFoundException();
    return NULL;
}