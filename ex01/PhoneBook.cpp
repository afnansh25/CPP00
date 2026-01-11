/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:13:25 by marvin            #+#    #+#             */
/*   Updated: 2026/01/03 22:13:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
   _index = 0;
   _count = 0;
}

static bool get_input(const std::string &prompt, std::string &input)
{
    while (1)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            return (false);
        }
        if (!input.empty())
            return (true);
        std::cout << "Error: field cannot be empty.\n";
    }
}

static bool is_digits(const std::string &s)
{
    size_t i;

    if (s.empty())
        return (false);
    i = 0;
    while (i < s.length())
    {
        if (s[i] < '0' || s[i] > '9')
            return (false);
        i++;
    }
    return (true);
}

void PhoneBook::addContact()
{
    std::string first;
    std::string last;
    std::string nick;
    std::string phone;
    std::string secret;

    if (!get_input("First name: ", first))
        return ;
    if (!get_input("Last name: ", last))
        return ;
    if (!get_input("Nickname: ", nick))
        return ;
    
    while (1)
    {
        if (!get_input("Phone number: ", phone))
            return ;
        if (is_digits(phone))
            break;
        std::cout << "Error: phone number must contain only digits.\n";
    }
    
    if (!get_input("Darkest secret: ", secret))
        return ;

    _contacts[_index].setAll(first, last, nick, phone, secret);
    _index = (_index + 1) % 8;
    if (_count < 8)
        _count++;
}

static std::string format_field(const std::string &s)
{
    if (s.length() > 10)
        return (s.substr(0, 9) + ".");
    return (s);
}

static int to_int(const std::string &s)
{
    int val;
    size_t i;

    val = 0;
    i = 0;
    while (i < s.length())
    {
        val = val * 10 + (s[i] - '0');
        i++;
    }
    return (val);
}

static void print_full_contact(const Contact &c)
{
    std::cout << "First name: " << c.getFirstName() << "\n";
    std::cout << "Last name: " << c.getLastName() << "\n";
    std::cout << "Nickname: " << c.getNickname() << "\n";
    std::cout << "Phone number: " << c.getPhoneNumber() << "\n";
    std::cout << "Darkest secret: " << c.getDarkestSecret() << "\n";
}

void PhoneBook::searchContacts() const
{
    int         i;
    int         idx;
    std::string input;

    if (_count == 0)
    {
        std::cout << "PhoneBook is empty.\n";
        return ;
    }

    std::cout << "|" << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|\n";
    i = 0;
    while (i < _count)
    {
        std::cout << "|"
                  << std::setw(10) << i << "|"
                  << std::setw(10) << format_field(_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << format_field(_contacts[i].getLastName()) << "|"
                  << std::setw(10) << format_field(_contacts[i].getNickname()) << "|\n";
        i++;
    }

    std::cout << "Enter index: ";
    if (!std::getline(std::cin, input))
    {
        std::cout << std::endl;
        return ;
    }
    if (!is_digits(input))
    {
        std::cout << "Not valid index.\n";
        return ;
    }
    idx = to_int(input);
    if (idx < 0 || idx >= _count)
    {
        std::cout << "Not valid index.\n";
        return ;
    }
    print_full_contact(_contacts[idx]);
}

