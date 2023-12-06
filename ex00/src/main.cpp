/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:55:56 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 15:35:29 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "__________________________________________" << std::endl;
	std::cout << "__________________TEST____________________" << std::endl;

    try {
        Bureaucrat a("Clerk#1", 0);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
    try {
        Bureaucrat b("Clerk#2", 150);
        b.incrementGrade();
        std::cout << GREEN << b << RESET <<std::endl;
        b.decrementGrade();
        std::cout << GREEN << b << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
    try {
        Bureaucrat c("Clerk#3", 160);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
    try {
        Bureaucrat d("Clerk#4", 42);
        d.incrementGrade();
        std::cout << GREEN << d << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    return 0;
}