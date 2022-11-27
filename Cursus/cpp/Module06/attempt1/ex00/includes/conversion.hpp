/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:45:52 by swillis           #+#    #+#             */
/*   Updated: 2022/11/26 16:30:25 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <iomanip>
# include <sstream>

enum t_token {

	UN,	//Unprintable Char
	CH,	//Printable Char
	NB,	//Int/Double/Float number
	DT,	//Double/float dot
	FF,	//inf/float f
	TOKEN_NBR
};

enum t_state {

	START,
	ERROR,
	UNPRINTABLE,
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	STATE_NBR
};

const t_token	ascii_tbl[256] = {

	UN, UN, UN, UN, UN, UN, UN, UN, //8
	UN, UN, UN, UN, UN, UN, UN, UN, //16
	UN, UN, UN, UN, UN, UN, UN, UN, //24
	UN, UN, UN, UN, UN, UN, UN, CH, //32
	CH, CH, CH, CH, CH, CH, CH, CH, //40
	CH, CH, CH, CH, CH, CH, DT, CH, //48
	NB, NB, NB, NB, NB, NB, NB, NB, //56
	NB, NB, CH, CH, CH, CH, CH, CH, //64
	CH, CH, FF, CH, CH, CH, CH, CH, //72
	CH, CH, CH, CH, CH, CH, CH, CH, //80
	CH, CH, CH, CH, CH, CH, CH, CH, //88
	CH, CH, CH, CH, CH, CH, CH, CH, //96
	CH, CH, CH, CH, CH, CH, FF, CH, //104
	CH, CH, CH, CH, CH, CH, CH, CH, //112
	CH, CH, CH, CH, CH, CH, CH, CH, //120
	CH, CH, CH, CH, CH, CH, CH, UN, //128
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
	CH, CH, CH, CH, CH, CH, CH, CH, //---
};

// t_state tab[STATE_NBR][TOKEN_NBR] = {

// 	// START
// 	{
// 		UNPRINTABLE,	// UN,	//Unprintable Char
// 		CHAR,			// CH,	//Printable Char
// 		INT,			// NB,	//Int/Double/Float number
// 		CHAR,			// DT,	//Double/float dot
// 		POSITIVE,		// PO,	//Sign +ve
// 		NEGATIVE,		// NE,	//Sign -ve
// 		CHAR			// FF,	//inf/float f
// 	},
// 	// ERROR
// 	{
// 		ERROR,			// UN,	//Unprintable Char
// 		ERROR,			// CH,	//Printable Char
// 		ERROR,			// NB,	//Int/Double/Float number
// 		ERROR,			// DT,	//Double/float dot
// 		ERROR,			// PO,	//Sign +ve
// 		ERROR,			// NE,	//Sign -ve
// 		ERROR			// FF,	//inf/float f
// 	},
// 	// UNPRINTABLE
// 	{
// 		ERROR,			// UN,	//Unprintable Char
// 		ERROR,			// CH,	//Printable Char
// 		ERROR,			// NB,	//Int/Double/Float number
// 		ERROR,			// DT,	//Double/float dot
// 		ERROR,			// PO,	//Sign +ve
// 		ERROR,			// NE,	//Sign -ve
// 		ERROR			// FF,	//inf/float f
// 	},
// };

#endif
