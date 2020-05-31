#include "crypto.h"
#include <ctime>
#include <string>

/*
		srand change le parametre "seed" de rand() qui genere des nombres.
		ironiquement, rand() n'est pas vraiment aleatoire, on attribue la
		variable seed en appelant srand() pour que la serie de chiffre generee
		par rand() soit differente a chaque coup.

		unsigned char kchar = rand() % 255;		//randomize un masque de 8 bits
*/

unsigned short generateShortKey() {
	srand(time(NULL));
	unsigned short key = (unsigned short)rand() % 65535;
	return key;		//randomize un masque de 16 bits;
}

unsigned short xorCypher(unsigned short message, unsigned short key) {
	return message ^ key;
}

//implementation en string 
std::string generateKey(std::string message) {
	std::string key = "";
	srand(time(NULL));

	for (int i = 0; i < message.length(); i++) {
		int rnumber = rand() % 25;
		char kchar = 'A' + rnumber;
		key.push_back(kchar);
	}

	return key;
}


std::string cypher(std::string message, std::string key) {
	std::string cypher;

	for (int i = 0; i < message.length(); i++) {
		char c = message[i] + key[i];
		cypher.push_back(c);
	}

	return cypher;
}


std::string decypher(std::string cypher, std::string key) {
	std::string message;

	for (int i = 0; i < cypher.length(); i++) {
		char c = cypher[i] - key[i];
		message.push_back(c);
	}

	return message;
}
