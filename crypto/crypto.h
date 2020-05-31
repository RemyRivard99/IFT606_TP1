#pragma once

#include <string>

unsigned short generateShortKey();
unsigned short xorCypher(unsigned short, unsigned short);

std::string generateKey(std::string message);
std::string decypher(std::string, std::string);
std::string cypher(std::string, std::string);