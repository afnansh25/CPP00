/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:13:11 by marvin            #+#    #+#             */
/*   Updated: 2026/01/03 22:13:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
   private:
      std::string _firstName;
      std::string _lastName;
      std::string _nickname;
      std::string _phoneNumber;
      std::string _darkestSecret;
   
   public:
      Contact();

      bool setAll(const std::string &first,
                const std::string &last,
                const std::string &nick,
                const std::string &phone,
                const std::string &secret);

      std::string getFirstName() const;
      std::string getLastName() const;
      std::string getNickname() const;
      std::string getPhoneNumber() const;
      std::string getDarkestSecret() const;
};

#endif