# ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat {

private :
	std::string const	_name;
	int					_grade;

public :
	Bureaucrat();
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat& src);
	
	Bureaucrat(std::string name, int grade);

	std::string const	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form& form);

	class	GradeTooHighException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		public :
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& src);

#endif
