#include <prime.hpp>
#include "catch.hpp"

TEST_CASE("A Primality Test", "[is_prime]") {
	REQUIRE(is_prime(0) == false);
	REQUIRE(is_prime(1) == false);
	REQUIRE(is_prime(2) == true);
	REQUIRE(is_prime(3) == true);
	REQUIRE(is_prime(4) == false);
}