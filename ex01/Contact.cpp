/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:13:07 by marvin            #+#    #+#             */
/*   Updated: 2026/01/03 22:13:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

bool Contact::setAll(const std::string &first,
                     const std::string &last,
                     const std::string &nick,
                     const std::string &phone,
                     const std::string &secret)
{
    if (first.empty() || last.empty() || nick.empty()
        || phone.empty() || secret.empty())
        return (false);
    _firstName = first;
    _lastName = last;
    _nickname = nick;
    _phoneNumber = phone;
    _darkestSecret = secret;
    return (true);
}

std::string Contact::getFirstName() const
{
    return (_firstName);
}

std::string Contact::getLastName() const
{
    return (_lastName);
}

std::string Contact::getNickname() const
{
    return (_nickname);
}

std::string Contact::getPhoneNumber() const
{
    return (_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
    return (_darkestSecret);
}
