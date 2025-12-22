/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:30:12 by brian             #+#    #+#             */
/*   Updated: 2025/12/17 01:21:36 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#define MIN_INT std::numeric_limits<int>::min()
#define MAX_INT std::numeric_limits<int>::max()
#define MIN_FLOAT  (-std::numeric_limits<float>::max())
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_DOUBLE (-std::numeric_limits<double>::max())
#define MAX_DOUBLE std::numeric_limits<double>::max()

enum e_type {
  SPECIAL = 0,
  CHAR = 1,
  INT = 2,
  FLOAT = 3,
  DOUBLE = 4,
  INVALID = -1
};

class ScalarConverter {
private:
  ScalarConverter(void);
  ScalarConverter(ScalarConverter const &src);
  ~ScalarConverter(void);
  ScalarConverter &operator=(ScalarConverter const &rhs);

public:
  static void convert(const std::string &str);
};

e_type getType(const std::string &str, size_t &len);
void printSpecial(const std::string &str);
void convertChar(const std::string &str, size_t &len);
void convertInt(const std::string &str);
void convertFloat(const std::string &str);
void convertDouble(const std::string &str);