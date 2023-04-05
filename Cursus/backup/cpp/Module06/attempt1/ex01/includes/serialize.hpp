/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:51:12 by swillis           #+#    #+#             */
/*   Updated: 2022/11/26 17:52:01 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_H
# define SERIALIZE_H

# include "Data.hpp"
# include <inttypes.h>

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif
