/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:55:56 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 14:14:54 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "__________________________________________" << std::endl;
	std::cout << "__________________TEST____________________" << std::endl;

    try {
        Bureaucrat b1("Clerk#1", 0);
        b1.decrementGrade();
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
    try {
        Bureaucrat b2("Clerk#2", 150);
        Form f1("Form1", false, 2, 2);
        b2.incrementGrade();
        std::cout << GREEN << b2 << RESET <<std::endl;
        b2.signForm(f1);
        f1.beSigned(b2);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
    try {
        Bureaucrat b3("Clerk#3", 160);
        b3.incrementGrade();
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
    try {
        Bureaucrat b4("Clerk#4", 42);
        Form f2("Form2", false, 100, 100);
        b4.incrementGrade();
        std::cout << GREEN << b4 << RESET << std::endl;
        b4.signForm(f2);
        f2.beSigned(b4);
        b4.signForm(f2);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
    try {
        
        Bureaucrat b5("Clerk#1", 42);
        Form f3("Form3", false, 42, 42);
        std::cout << GREEN << f3 << RESET << std::endl;
        b5.signForm(f3);
        f3.beSigned(b5);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    return 0;
}