/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:42:08 by marvin            #+#    #+#             */
/*   Updated: 2026/01/03 21:42:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int   main(int ac, char **av)
{
   int   i;
   int   j;

   i = 1;
   if(ac == 1)
   {
      std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
      return (0);
   }
   while(i < ac)
   {
      j = 0;
      while(av[i][j])
      {
         std::cout << (char)std::toupper((unsigned char)av[i][j]);
         j++;
      }
      i++;
   }
   std::cout <<"\n";
   return (0);
}