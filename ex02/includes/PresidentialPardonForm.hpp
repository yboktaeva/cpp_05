/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:57:49 by yuboktae          #+#    #+#             */
/*   Updated: 2023/12/05 15:50:39 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &ref);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);
        ~PresidentialPardonForm();

        virtual void execute(Bureaucrat const &executor) const;
};

#endif