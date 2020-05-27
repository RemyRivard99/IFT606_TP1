#pragma once

#include <string> 

unsigned short generateShortKey();
unsigned short xorDecipher(unsigned short, unsigned short);

std::string generateKey(std::string message);
std::string decypher(std::string);
std::string cypher(std::string);