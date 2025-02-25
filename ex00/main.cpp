/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:22:36 by ppontet           #+#    #+#             */
/*   Updated: 2025/02/25 17:58:24 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int i;
	int j;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	j = 0;
	while (i < argc && argv[i] != NULL)
	{
		while(argv[i][j] != '\0')
			std::cout << static_cast<char>(std::toupper(static_cast<char>(argv[i][j++])));
		j = 0;
		i++;
	}
	std::cout << std::endl;
	return (0);
}
