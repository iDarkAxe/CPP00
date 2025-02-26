#include <iostream>

class Contact{
	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _NickName;
		std::string _PhoneNumber;
		std::string _DarkestSecret;
	
	public:
		Contact();
		~Contact();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();

		void setFirstName(std::string str);
		void setLastName(std::string str);
		void setNickName(std::string str);
		void setPhoneNumber(std::string str);
		void setDarkestSecret(std::string str);
};
