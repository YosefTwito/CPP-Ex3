#include "doctest.h"
#include "solver.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace solver;

TEST_CASE("Test for real equations") { // 14
    RealVariable x;
    CHECK(solve(x*2 == 4) == 2);
    CHECK(solve(x+2 == 4) == 2);
    CHECK(solve(x*2 + x*5 == 7) == 1);
    CHECK(solve(x-2 == 2) == 4);
    CHECK(solve(x+2-(2-x) == 2) == 1);
    CHECK(solve(2*(x-2) == 2) == 3);
    CHECK(solve(x*2 + x*5 - x*6 == 7) == 7);
    CHECK(solve(x/2 == 2) == 4);
    CHECK(solve(x + x/2 == 6) == 4);
    CHECK(solve(2*x - x/2 == 6) == 4);
    CHECK(solve((x^2) == 4) == 2);
    CHECK(solve((x^2) + 2*x - 2 == -3) == -1);
    CHECK(solve((((2*x)^2) + 8*x + 16)/4 == 7) == 1);
    CHECK(solve((x^2)/2 == 8) == 4);
}

TEST_CASE("Test for complex equations") { // 15
    ComplexVariable x;
    CHECK(solve(x*2 == 4) == std::complex<double>(2,0));
    CHECK(solve(x+2 == 4) == std::complex<double>(2,0));
    CHECK(solve(x*2 + x*5 == 7) == std::complex<double>(1,0));
    CHECK(solve(x-2 == 2) == std::complex<double>(4,0));
    CHECK(solve(x+2-(2-x) == 2) == std::complex<double>(1,0));
    CHECK(solve(2*(x-2) == 2) == std::complex<double>(3,0));
    CHECK(solve(x*2 + x*5 - x*6 == 7) == std::complex<double>(7,0));
    CHECK(solve(x/2 == 2) == std::complex<double>(4,0));
    CHECK(solve(x + x/2 == 6) == std::complex<double>(4,0));
    CHECK(solve(2*x - x/2 == 6) == std::complex<double>(4,0));
    CHECK(solve((x^2) == 4) == std::complex<double>(2,0));
    CHECK(solve((x^2) + 2*x - 2 == -4) == std::complex<double>(-1,1));
    CHECK(solve((((2*x)^2) + 8*x + 16)/4 == -1) == std::complex<double>(-1,2));
    CHECK(solve((x^2) == -4) == std::complex<double>(0,2));
    CHECK(solve((x^2)/2 == -8) == std::complex<double>(0,4));
}

TEST_CASE("Test for chaining in real equations") { // 13
    RealVariable x;
    CHECK(solve((x*2)*2 == 4) == 1);
    CHECK(solve(x+2+2+2+2+2 == 10) == 0);
    CHECK(solve((x*2)*2 + (x*5)*5 == 29) == 1);
    CHECK(solve(x-2-2-2-2-2-2 == -2) == 10);
    CHECK(solve(x+2-(2-x)+(x+7)-(3-x)-x == 1) == -1);
    CHECK(solve(2*(2*(x-2)) == 2) == 2.5);
    CHECK(solve((x*2)*2 + (x*5)*5 - (x*6)*6 == 21) == -3);
    CHECK(solve(((x/2)/2)/2 == 2) == 16);
    CHECK(solve(x + x/2 + x/4 + x/8 == 15) == 8);
    CHECK(solve(4*(2*x) - (x/2) == 5*12) == 8);
    CHECK(solve(((x^2)*2)*7 == 14) == 1);
    CHECK((solve(((x^2) + 2*x - 2 == -3) == 1) ||(solve((x^2) + 2*x - 2 == -3) == -1)));
    CHECK(solve((((2*x)^2) + (3*(2*x)^2) + 16) == 16) == 0);
}

TEST_CASE("Test for chaining in complex equations") { // 16
    ComplexVariable x;
    CHECK(solve((x*2)*2 == 4) == std::complex<double>(1,0));
    CHECK(solve(x+2+2+2+2+2 == 10) == std::complex<double>(0,0));
    CHECK(solve((x*2)*2 + (x*5)*5 == 29) == std::complex<double>(1,0));
    CHECK(solve(x-2-2-2-2-2-2 == -2) == std::complex<double>(10,0));
    CHECK(solve(x+2-(2-x)+(x+7)-(3-x)-x == 1) == std::complex<double>(-1,0));
    CHECK(solve(2*(2*(x-2)) == 2) == std::complex<double>(2.5,0));
    CHECK(solve((x*2)*2 + (x*5)*5 - (x*6)*3 == 11) == std::complex<double>(1,0));
    CHECK(solve(((x/2)/2)/2 == 2) == std::complex<double>(16,0));
    CHECK(solve(x + x/2 + x/4 + x/8 == 30) == std::complex<double>(16,0));
    CHECK(solve(4*(2*x) - (x/2) == 5*15) == std::complex<double>(10,0));
    CHECK(solve(((x^2)*2)*7 == 0) == std::complex<double>(0,0));
    CHECK(solve((x^2) + 2*x - 2 == -3) == std::complex<double>(-1,0));
    CHECK(solve((((2*x)/3)^2) == 144) == std::complex<double>(18,0));
    CHECK(solve((((2*x)^2)/4) == -1) == std::complex<double>(0,1));
    CHECK(solve((((2*x)^2)/2)/4 == -8) == std::complex<double>(0,4));
}

TEST_CASE("Test for real exceptions") {
    RealVariable x;
    CHECK(solve(x+2 == 4) == 2);
    CHECK(solve(x*2 + x*5 == 7) == 1);
    CHECK(solve(x-2 == 2) == 4);
    CHECK(solve(x+2-(2-x) == 2) == 1);
    CHECK(solve(2*(x-2) == 2) == 3);
    CHECK(solve(x*2 + x*5 - x*5 == 6) == 3);
    CHECK(solve(x/2 == 2) == 4);
    CHECK(solve(x + x/2 == 6) == 4);
    CHECK(solve(2*x - x/2 == 6) == 4);
    CHECK(solve((x^2) == 4) == 2);
    CHECK(solve((x^2) + 2*x - 2 == -3) == -1);
    CHECK(solve((((2*x)^2) + 8*x + 16)/4 == 7) == 1);
    CHECK(solve((x^2)/2 == 8) == 4);
    CHECK(solve(x+2 == 4) == 2);
    CHECK(solve(x*2 + x*5 == 7) == 1);
    CHECK(solve(x-2 == 2) == 4);
    CHECK(solve(x+2-(2-x) == 2) == 1);
    CHECK(solve(2*(x-2) == 2) == 3);
    CHECK(solve(x*2 + x*5 - x*6 == 7) == 7);
    CHECK(solve(x/2 == 2) == 4);
    CHECK(solve(x + x/2 == 6) == 4);
    CHECK(solve(2*x - x/2 == 6) == 4);
    CHECK(solve((x^2) == 4) == 2);
    CHECK(solve((x^2) + 2*x - 2 == -3) == -1);
    CHECK(solve((((2*x)^2) + 8*x + 16)/4 == 7) == 1);
    CHECK(solve((x^2)/2 == 8) == 4);
    CHECK(solve(x+2 == 4) == 2);
    CHECK(solve(x*2 + x*5 == 7) == 1);
    CHECK(solve(x-2 == 2) == 4);
    CHECK(solve(x+2-(2-x) == 2) == 1);
    CHECK(solve(2*(x-2) == 2) == 3);
    CHECK(solve(x*2 + x*5 - x*6 == 7) == 7);
    CHECK(solve(x/2 == 2) == 4);
    CHECK(solve(x + x/2 == 6) == 4);
    CHECK(solve(2*x - x/2 == 6) == 4);
    CHECK(solve((x^2) == 4) == 2);
    CHECK(solve((x^2) + 2*x - 2 == -3) == -1);
    CHECK(solve((((2*x)^2) + 8*x + 16)/4 == 7) == 1);
    CHECK(solve((x^2)/2 == 8) == 4);
    CHECK(solve(x+2 == 4) == 2);
    CHECK(solve(x*2 + x*5 == 7) == 1);
    CHECK(solve(x-2 == 2) == 4);
    CHECK(solve(x+2-(2-x) == 2) == 1);
    CHECK(solve(2*(x-2) == 2) == 3);
    CHECK(solve(x*2 + x*5 - x*6 == 7) == 7);
}
