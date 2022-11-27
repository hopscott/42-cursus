/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/27 20:09:10 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <ctime>
# include <cstdlib>
# include <unistd.h>
# include <typeinfo>

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base *	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
