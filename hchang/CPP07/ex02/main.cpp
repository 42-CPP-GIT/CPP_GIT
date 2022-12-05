/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchang <hchang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:18:37 by hchang            #+#    #+#             */
/*   Updated: 2022/12/02 11:59:22 by hchang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
# define MAX_VAL 10

void a()
{
	system("leaks Array");
}
int main(int, char**)
{
	// atexit(a);
    srand(time(NULL));
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = (rand() % 10) + 1;
        numbers[i] = value;
		std::cout << numbers[i] << std::endl;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     numbers[i] = rand() % 20;
    // }
	for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << " ";
    }
	delete [] mirror;
    return 0;
}