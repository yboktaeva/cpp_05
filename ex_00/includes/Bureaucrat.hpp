/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:41:53 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/01 19:10:15 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

# include <iostream>

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name);
        Bureaucrat(int grade);
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &ref);
        Bureaucrat &operator=(const Bureaucrat &ref);
        ~Bureaucrat();
        
        const std::string &getName() const;
        int setGrade(int grade);
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


#endif