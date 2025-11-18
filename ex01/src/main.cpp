/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:51:40 by brian             #+#    #+#             */
/*   Updated: 2025/10/16 18:54:57 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{

	Data *data = new Data;
	data->name = "Peter";
	data->age = 42;

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout << "raw (dec): " << raw << "\n";

	std::cout << serialized->name << std::endl;
	std::cout << serialized->age << std::endl;

	delete data;
	return (0);
}