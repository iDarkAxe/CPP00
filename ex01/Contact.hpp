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
		void getFirstName();
		void getLastName();
		void getNickName();
		void getPhoneNumber();
		void getDarkestSecret();
};
