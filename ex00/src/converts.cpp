/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brian <brian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:53:26 by brian             #+#    #+#             */
/*   Updated: 2025/12/17 02:16:00 by brian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isScientificStr(const std::string &s) {
  return (s.find('e') != std::string::npos) || (s.find('E') != std::string::npos);
}

static std::string noSciDouble(double d) {
  std::ostringstream oss;
  oss << d;
  std::string s = oss.str();

  double ip = 0.0;
  bool isWhole = (std::modf(d, &ip) == 0.0);
  bool isSci = isScientificStr(s);

  if (isWhole && !isSci)
    s += ".0";

  return s;
}

static std::string noSciFloat(float f) {
  std::ostringstream oss;
  oss << f;
  std::string s = oss.str();

  double ip = 0.0;
  bool isWhole = (std::modf(static_cast<double>(f), &ip) == 0.0);
  bool isSci = isScientificStr(s);

  if (isWhole && !isSci)
    s += ".0";

  s += "f";
  return s;
}

void printSpecial(const std::string &str) {
  if (str == "nan" || str == "nanf") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  } else if (str == "+inf" || str == "+inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
  } else if (str == "-inf" || str == "-inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
  }
}

void convertChar(const std::string &str, size_t &len) {
  char c = 0;

  if (len == 1)
    c = str[0];
  else
    c = str[1];
  std::cout << "char: ";
  if (isprint(c)) {
    std::cout << "'" << c << "'" << std::endl;
  } else
    std::cout << "Non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  std::cout << "float: " << noSciFloat(static_cast<float>(c)) << std::endl;
  std::cout << "double: " << noSciDouble(static_cast<double>(c)) << std::endl;
}

void convertInt(const std::string &str) {
  long l = std::atol(str.c_str());

  std::cout << "char: ";
  if (l < 0 || l > 127)
    std::cout << "impossible" << std::endl;
  else {
    if (isprint(l))
      std::cout << "'" << static_cast<char>(l) << "'" << std::endl;
    else
      std::cout << "Non displayable" << std::endl;
  }
  std::cout << "int: ";
  if (l < MIN_INT || l > MAX_INT)
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(l) << std::endl;
  std::cout << "float: " << noSciFloat(static_cast<float>(l)) << std::endl;
  std::cout << "double: " << noSciDouble(static_cast<double>(l)) << std::endl;
}

void convertFloat(const std::string &str) {
  float f = std::atof(str.c_str());
  
  std::cout << "char: ";
  if (f < 0 || f > 127)
    std::cout << "impossible" << std::endl;
  else {
    if (isprint(f))
      std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    else
      std::cout << "Non displayable" << std::endl;
  }
  std::cout << "int: ";
  if (static_cast<long>(f) < MIN_INT || static_cast<long>(f) > MAX_INT)
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(f) << std::endl;
  std::cout << "float: ";
  if (f < MIN_FLOAT || f > MAX_FLOAT)
    std::cout << "impossible" << std::endl;
  else
    std::cout << noSciFloat(f) << std::endl;
  std::cout << "double: " << noSciDouble(static_cast<double>(f)) << std::endl;
}

void convertDouble(const std::string &str) {
  double d = std::atof(str.c_str());

  std::cout << "char: ";
  if (d < 0 || d > 127)
    std::cout << "impossible" << std::endl;
  else {
    if (isprint(d))
      std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    else
      std::cout << "Non displayable" << std::endl;
  }
  std::cout << "int: ";
  if (d < MIN_INT || d > MAX_INT)
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(d) << std::endl;
  std::cout << "float: ";
  if (d < MIN_FLOAT || d > MAX_FLOAT)
    std::cout << "impossible" << std::endl;
  else
    std::cout << noSciFloat(static_cast<float>(d)) << std::endl;
  std::cout << "double: ";
  if (d < MIN_DOUBLE || d > MAX_DOUBLE)
    std::cout << "impossible" << std::endl;
  else
    std::cout << noSciDouble(d) << std::endl;
}