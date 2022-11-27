/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:04:56 by swillis           #+#    #+#             */
/*   Updated: 2022/11/26 16:45:05 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.hpp"

t_state		state = START; //global

int	main( int ac, char **av )
{
    // Check args --------------------------------------------------------------------
    if (ac != 2) {
        
        std::cout << "[ERROR] - Wrong number of arguments, only one input!" << std::endl;
        return 1;
    }

    // Set inputs --------------------------------------------------------------------
	std::string	input = av[1];

    // Check pseudo literal floats ---------------------------------------------------
	if ((input == "+inff") || (input == "-inff") || (input == "nanf"))
	{
		float	output = std::numeric_limits<float>::infinity();	
		if (input == "-inff")
			output *= -1;
		else if (input == "nanf")
			output = std::numeric_limits<float>::quiet_NaN();	
	
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(output) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(output) << std::endl;
        return 0;
	}
	
    // Check pseudo literal doubles ---------------------------------------------------
	if ((input == "+inf") || (input == "-inf") || (input == "nan"))
	{
		double	output = std::numeric_limits<double>::infinity();	
		if (input == "-inf")
			output *= -1;
		else if (input == "nan")
			output = std::numeric_limits<double>::quiet_NaN();	
		
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(output) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(output) << std::endl;
        return 0;
	}

	// State maching for parsing input -----------------------------------------------
	size_t				n;
	t_token				token;

	for (size_t i=0; i<input.length(); ++i)
	{
		n = static_cast<size_t>(input[i]);
		token = ascii_tbl[n];

		switch(token)
		{
			case UN:
				switch(state)
				{
					case START:
						state = UNPRINTABLE;
						break;
					default:
						state = ERROR;
						break;
				}
				break;

			case CH:
				switch(state)
				{
					case START:
						state = CHAR;
						break;
					default:
						state = ERROR;
						break;
				}
				break;

			case NB:
				switch(state)
				{
					case START:
						state = INT;
						break;
					case INT:
						state = INT;
						break;
					case DOUBLE:
						state = DOUBLE;
						break;
					default:
						state = ERROR;
						break;
				}
				break;

			case DT:
				switch(state)
				{
					case START:
						state = CHAR;
						break;
					case INT:
						state = DOUBLE;
						break;
					default:
						state = ERROR;
						break;
				}
				break;

			case FF:
				switch(state)
				{
					case START:
						state = CHAR;
						break;
					case INT:
						state = FLOAT;
						break;
					case DOUBLE:
						state = FLOAT;
						break;
					default:
						state = ERROR;
						break;
				}
				break;
				
			default:
				state = ERROR;
				break;

		}
	}

	// Printing -------------------------------------------------------------------------------
	std::stringstream	ss(input);

	switch(state)
	{
		case UNPRINTABLE:
			{
				char	output = static_cast<char>(input[0]);
				
				//Char
				std::cout << "char: Non displayable" << std::endl;

				//Int
				std::cout << "int: " << static_cast<int>(output) << std::endl;

				//Float
				std::cout << std::setprecision(std::numeric_limits<float>::digits10 + 1);
				std::cout << "float: " << static_cast<float>(output) << ".0f" << std::endl;

				//Double
				std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1);
				std::cout << "double: " << static_cast<double>(output) << ".0" << std::endl;
			}
			break;
				
		case CHAR:
			{
				char	output = static_cast<char>(input[0]);
				
				//Char
				std::cout << "char: '" << static_cast<char>(output) << "'" << std::endl;

				//Int
				std::cout << "int: " << static_cast<int>(output) << std::endl;

				//Float
				std::cout << std::setprecision(std::numeric_limits<float>::digits10 + 1);
				std::cout << "float: " << static_cast<float>(output) << ".0f" << std::endl;

				//Double
				std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1);
				std::cout << "double: " << static_cast<double>(output) << ".0" << std::endl;
			}
			break;

		case INT:
			{
				int		output;
				if (!(ss >> output)) //atoi
				{
					std::cout << "[ERROR] - Int conversion failed!" << std::endl;
					return 1;
				}
			
				//Char
				if (output > std::numeric_limits<char>::max())
					std::cout << "char: impossible" << std::endl;
				else
				{
					n = static_cast<size_t>(output);
					token = ascii_tbl[n];
					if (token == UN)
						std::cout << "char: Non displayable" << std::endl;
					else
						std::cout << "char: '" << static_cast<char>(output) << "'" << std::endl;	
				}

				//Int
				std::cout << "int: " << static_cast<int>(output) << std::endl;

				//Float
				std::cout << std::setprecision(std::numeric_limits<float>::digits10 + 1);
				std::cout << "float: " << static_cast<float>(output) << ".0f" << std::endl;

				//Double
				std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1);
				std::cout << "double: " << static_cast<double>(output) << ".0" << std::endl;
			}
			break;
			
		case FLOAT:
			{
				float	output;
				if (!(ss >> output)) //atof
				{
					std::cout << "[ERROR] - Float conversion failed!" << std::endl;
					return 1;
				}

				//Char
				if (output > std::numeric_limits<char>::max())
					std::cout << "char: impossible" << std::endl;
				else
				{
					n = static_cast<size_t>(output);
					token = ascii_tbl[n];
					if (token == UN)
						std::cout << "char: Non displayable" << std::endl;
					else
						std::cout << "char: '" << static_cast<char>(output) << "'" << std::endl;	
				}

				//Int
				if (output > static_cast<float>(std::numeric_limits<int>::max()))
					std::cout << "int: impossible" << std::endl;
				else if (output < static_cast<float>(std::numeric_limits<int>::min()))
					std::cout << "int: impossible" << std::endl;
				else
					std::cout << "int: " << static_cast<int>(output) << std::endl;

				//Float
				std::cout << std::setprecision(std::numeric_limits<float>::digits10 + 1);
				std::cout << "float: " << output;
				if (floorf(output) == output)
					std::cout << ".0";
				std::cout << "f" << std::endl;

				//Double
				std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1);
				std::cout << "double: " << static_cast<double>(output);
				if (floor(static_cast<double>(output)) == static_cast<double>(output))
					std::cout << ".0";
				std::cout << std::endl;
			}
			break;
			
		case DOUBLE:
			{
				double	output;
				if (!(ss >> output)) //atod
				{
					std::cout << "[ERROR] - Double conversion failed!" << std::endl;
					return 1;
				}
				
				//Char
				if (output > std::numeric_limits<char>::max())
					std::cout << "char: impossible" << std::endl;
				else
				{
					n = static_cast<size_t>(output);
					token = ascii_tbl[n];
					if (token == UN)
						std::cout << "char: Non displayable" << std::endl;
					else
						std::cout << "char: '" << static_cast<char>(output) << "'" << std::endl;	
				}

				//Int
				if (output > static_cast<double>(std::numeric_limits<int>::max()))
					std::cout << "int: impossible" << std::endl;
				else if (output < static_cast<double>(std::numeric_limits<int>::min()))
					std::cout << "int: impossible" << std::endl;
				else
					std::cout << "int: " << static_cast<int>(output) << std::endl;
					
				//Float
				std::cout << std::setprecision(std::numeric_limits<float>::digits10 + 1);
				std::cout << "float: " << static_cast<float>(output);
				if (floorf(static_cast<float>(output)) == static_cast<float>(output))
					std::cout << ".0";
				std::cout << "f" << std::endl;

				//Double
				std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1);
				std::cout << "double: " << output;
				if (floor(output) == output)
					std::cout << ".0";
				std::cout << std::endl;

			}
			break;

		default:
			std::cout << "[ERROR] - Invalid input!" << std::endl;
			break;
	}

    return 0;
}
