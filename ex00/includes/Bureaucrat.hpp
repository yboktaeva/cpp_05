/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:41:53 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/04 13:04:10 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define CYAN "\033[1;36m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &ref);
        Bureaucrat &operator=(const Bureaucrat &ref);
        ~Bureaucrat();
        
        const std::string &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        
    class GradeTooHighException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &ref);

#endif