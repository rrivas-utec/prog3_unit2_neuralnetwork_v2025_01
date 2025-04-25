//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "neural_network.h"
using namespace std;

static void test_1() {
}

TEST_CASE("Question #1.1") {
    execute_test("question_1_test_1.in", test_1);
}