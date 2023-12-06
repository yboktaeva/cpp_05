/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:00:58 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 14:52:19 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp" 

class Intern {
    public:
        Intern();
        Intern(const Intern &ref);
        Intern &operator=(const Intern &ref);
        ~Intern();
        
        AForm *makeShrubberyForm(std::string target);
        AForm *makeRobotomyForm(std::string target);
        AForm *makePresidentialForm(std::string target);

        AForm *makeForm(std::string formName, std::string target);
};

#endif