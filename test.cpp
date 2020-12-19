#include "catch_amalgamated.hpp"
#include "580A.h"
#include "996A.h"
#include <vector>

/*
TEST_CASE("580A", "[580A]"){
    int size;
    std::vector<int> input;
    size = 6;
    input = {2, 2, 1, 3, 4, 1};
    REQUIRE(f508A(size, input) == 3);
    size = 3;
    input = {2, 2, 9};
    REQUIRE(f508A(size, input) == 3);
    size = 1;
    input = {9};
    REQUIRE(f508A(size, input) == 1);
}
*/

TEST_CASE("996A", "[996A]"){
    int input;
    input = 125;
    REQUIRE(f996A(input) == 3);
    input = 43;
    REQUIRE(f996A(input) == 5);
    input = 1000000000;
    REQUIRE(f996A(input) == 10000000);
}
