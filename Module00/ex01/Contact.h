# ifndef CONTACT_H
#define CONTACT_H

# include <string>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
public:
	std::string&	get_first_name(void);
	std::string&	get_last_name(void);
	std::string&	get_nickname(void);
	std::string&	get_phone_number(void);
	std::string&	get_secret(void);

	void	set_first_name(const std::string& input);
	void	set_last_name(const std::string& input);
	void	set_nickname(const std::string& input);
	void	set_phone_number(const std::string& input);
	void	set_secret(const std::string& input);
};

#endif
