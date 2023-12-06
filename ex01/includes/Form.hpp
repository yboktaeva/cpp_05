/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:23:28 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/06 19:22:48 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;
    public:
        Form();
        Form(const std::string &name, int signGrade, int execGrade);
        Form(const Form &ref);
        Form &operator=(const Form &ref);
        ~Form();

        const std::string &getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(Bureaucrat &ref);
    
    class NotSignedException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
    
    class SignedException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
    
    class GradeTooHighException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Form &ref);

#endif