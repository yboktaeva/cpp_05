/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:47:13 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/04 18:21:29 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;
    public:
        AForm();
        AForm(const std::string &name, bool isSigned, int signGrade, int execGrade);
        AForm(const AForm &ref);
        AForm &operator=(const AForm &ref);
        virtual ~AForm();

        const std::string &getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(Bureaucrat &ref);
        virtual void execute(Bureaucrat const &executor) const;
        
    class GradeTooHighException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &ref);

#endif