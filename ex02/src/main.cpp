/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:55:56 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 14:15:15 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "__________________________________________" << std::endl;
	std::cout << "__________________TEST____________________" << std::endl;

    try {
        Bureaucrat b1("Clerk#1", 1);
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
        ShrubberyCreationForm f1("target1");
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
        RobotomyRequestForm f2("target2");
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
        PresidentialPardonForm f3("target3");
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
        b1.signForm(f1);
        b1.signForm(f1);
        b1.executeForm(f1);
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
        b1.signForm(f2);
        b1.executeForm(f2);
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
        b1.signForm(f3);
        b1.executeForm(f3);
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    return 0;
}