/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:18:16 by ppontet           #+#    #+#             */
/*   Updated: 2025/02/28 12:20:26 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>
#include <cerrno>
#include <cstdlib>

int safe_atoi(const char *str, int *out);
size_t count_digit(size_t n);
void print_error(std::string str);

/**
 * @brief Safely convert a string to an integer using errno and strtol
 * 
 * @param str string to convert
 * @param out number to output
 * @return int 1 if success, 0 if error
 */
int safe_atoi(const char *str, int *out)
{
    char *endptr;
    long val;

    errno = 0;
    val = std::strtol(str, &endptr, 10);
    if (errno == ERANGE || val > 2147483647 || val < -2147483648)
	{
		print_error("Number is way above int limits (-2147483648 to 2147483647)");
		return (0);
	}
    if (endptr == str || *endptr != '\0')
	{
		print_error("Please enter a valid number");
		return (0);
	}
    *out = static_cast<int>(val);
    return (1);
}

size_t count_digit(size_t n)
{
	size_t count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void print_error(std::string str)
{
	std::cerr << "\033[0;31m" << "ERROR : " << str << "\033[0m " << std::endl;
}
