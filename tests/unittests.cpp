#define CATCH_CONFIG_MAIN

// RTFM catch2:
// https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top

#include "catch.hpp"
#include "crypto.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <string>


TEST_CASE("key generation test for unsigned short") {
	unsigned short key = generateShortKey();
	REQUIRE(key != 0);
	std::cout << "key No 1 : " << cypher << std::endl;

	std::cout << "sleep 1000ms for tests" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	unsigned short key2 = generateShortKey();
	std::cout << "key No 2 : " << key2 << std::endl;
	REQUIRE((key & key2) != key);
}


TEST_CASE("decypher test for unsigned short") {

}


TEST_CASE("key generation test for string")
{
	std::string message = "HELLO";
	std::string key = generateKey(message);
	REQUIRE(key.length() == 5);
	std::cout << "key No 1 : " << key << std::endl;

	//puisque la fonction generateKey() se base sur le temps, 2 appels ayant le meme timestamp 
	//vont generer le meme masque.
	std::cout << "sleep 1000ms for tests" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::string key2 = generateKey(message);
	std::cout << "key No 2 : " << key2 << std::endl;
	REQUIRE(key.compare(key2) != 0);
}


TEST_CASE("cyphering & decyphering test for string")
{
	//cyphering
	std::string message;
	std::string crpt = cypher(message);
	REQUIRE(crpt.compare(message) != 0);
	REQUIRE(crpt.length() == 5);

	//decyphering
	std::string receivedMessage = decypher(crpt);
}