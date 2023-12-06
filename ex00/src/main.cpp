/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:55:56 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 19:42:48 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "__________________________________________" << std::endl;
	std::cout << "__________________TEST____________________" << std::endl;

    try {
        Bureaucrat a("Clerk#1", -1);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << "__________________________________________" << std::endl;
    std::cout << "__________________________________________" << std::endl;
    
    try {
        Bureaucrat b("Clerk#2", 45);
        b.incrementGrade();
        std::cout << b;
        b.decrementGrade();
        std::cout << b;
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
        std::cout << d << RESET;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    return 0;
}