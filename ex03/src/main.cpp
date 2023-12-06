/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:55:56 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 15:21:46 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    std::cout << "__________________________________________" << std::endl;
	std::cout << "__________________TEST____________________" << std::endl;

    try {
        Bureaucrat b1("b1", 1);
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
       
        Intern someIntern;
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
        AForm *f1;
        f1 = someIntern.makeForm("shrubbery creation", "target1");
    std::cout << "__________________________________________" << std::endl;
        b1.signForm(*f1);
        b1.executeForm(*f1);
    std::cout << "__________________________________________" << std::endl;
        AForm *f2;
        f2 = someIntern.makeForm("robotomy request", "target2");
    std::cout << "__________________________________________" << std::endl;
        b1.signForm(*f2);
        b1.executeForm(*f2);
    std::cout << "__________________________________________" << std::endl;
        AForm *f3;
        f3 = someIntern.makeForm("presidential pardon", "target3");
    std::cout << "__________________________________________" << std::endl;
        b1.signForm(*f3);
        b1.executeForm(*f3);
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
    delete f1;
    delete f2;
    delete f3;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    return 0;
}