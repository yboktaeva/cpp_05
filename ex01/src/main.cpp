/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:55:56 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 19:41:09 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "__________________________________________" << std::endl;
	std::cout << "__________________TEST____________________" << std::endl;

    try {
        Bureaucrat b2("Clerk#2", 150);
        Form f1("Form1", 2, 2);
        b2.incrementGrade();
        std::cout << b2;
        b2.signForm(f1);
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
        Form f2("Form2", 100, 100);
        b4.incrementGrade();
        std::cout << b4;
        b4.signForm(f2);
        b4.signForm(f2);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
    try {
        Bureaucrat b5("Clerk#1", 42);
        Form f3("Form3", 42, 42);
        std::cout << f3;
        b5.signForm(f3);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    return 0;
}