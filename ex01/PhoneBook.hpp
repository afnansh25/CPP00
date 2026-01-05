/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:13:21 by marvin            #+#    #+#             */
/*   Updated: 2026/01/03 22:13:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHONEBOOK_HPP
#define  PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
   private:
      Contact _contacts[8];   // fixed array
      int     _index;        // where next ADD goes (0 → 7 → 0)
      int     _count;        // how many contacts exist (max 8)

   public:
      PhoneBook();

      void addContact();
      void searchContacts() const;

};

#endif