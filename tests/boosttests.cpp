#include "crypto.h"

#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <chrono>
#include <thread>
#include <string>


BOOST_AUTO_TEST_CASE( key_generation_test_for_unsigned_short ) {
	unsigned short key = generateShortKey();
	BOOST_CHECK(key != 0);
	std::cout << "key No 1 : " << cypher << std::endl;

	std::cout << "sleep 1000ms for tests" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	unsigned short key2 = generateShortKey();
	std::cout << "key No 2 : " << key2 << std::endl;
	BOOST_CHECK((key & key2) != key);
}

BOOST_AUTO_TEST_CASE( cypher_and_decypher_test_for_unsigned_short ) {
	unsigned short message = 35U;
	unsigned short key = generateShortKey();
	unsigned short crpt = xorCypher(message, key);

	BOOST_CHECK(message != crpt);

	//decyphering
	unsigned short receivedMessage = xorCypher(crpt, key);
	BOOST_CHECK(receivedMessage == message);
}


BOOST_AUTO_TEST_CASE( key_generation_test_for_string )
{
	std::string message = "HELLO";
	std::string key = generateKey(message);
	BOOST_CHECK(key.length() == 5);
	std::cout << "key No 1 : " << key << std::endl;

	//puisque la fonction generateKey() se base sur le temps, 2 appels ayant le meme timestamp 
	//vont generer le meme masque.
	std::cout << "sleep 1000ms for tests" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::string key2 = generateKey(message);
	std::cout << "key No 2 : " << key2 << std::endl;
	BOOST_CHECK(key.compare(key2) != 0);
}


BOOST_AUTO_TEST_CASE( cyphering_and_decyphering_test_for_string )
{
	//cyphering
	std::string message = "HELLO";
	std::string key = generateKey(message);
	std::string crpt = cypher(message, key);
	
	BOOST_CHECK(crpt.compare(message) != 0);
	BOOST_CHECK(crpt.length() == 5);

	//decyphering
	std::string receivedMessage = decypher(crpt, key);
	BOOST_CHECK(receivedMessage.compare(message) == 0);
}