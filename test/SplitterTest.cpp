#include "Splitter.h"
#include "Resources.h"

#include "gtest/gtest.h"

#include <vector>
#include <string>

using namespace Homework;
using namespace std::string_literals;

const std::string ROOT_DIR = BINARY_DIR + "/test-data/splitter-test/"s;

TEST(splitterTest, singleChar) {
    //when
    auto result = splitInputData(ROOT_DIR + "single-char.txt", 1);

    //then
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(1, result[0]);
}

TEST(splitterTest, moreMappersThanData) {
    //when
    auto result = splitInputData(ROOT_DIR + "single-char.txt", 2); //the number of mappers is 2 but there is not enough data

    //then
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(1, result[0]);
}

TEST(splitterTest, twoEqualSections) {
    //when
    auto result = splitInputData(ROOT_DIR + "two-equal-sections.txt", 2);

    //then
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(4, result[0]);
    ASSERT_EQ(7, result[1]);
}

TEST(splitterTest, firstSectionBigger) {
    //when
    auto result = splitInputData(ROOT_DIR + "first-section-bigger.txt", 2);

    //then
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(6, result[0]);
    ASSERT_EQ(8, result[1]);
}

TEST(splitterTest, secondSectionBigger) {
    //when
    auto result = splitInputData(ROOT_DIR + "second-section-bigger.txt", 2); //the number of mappers is 2 but it is impossible to split the data

    //then
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(8, result[0]);
}

TEST(splitterTest, twoSectionsComplex) {
    //when
    auto result = splitInputData(ROOT_DIR + "two-sections-complex.txt", 2);

    //then
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(21, result[0]);
    ASSERT_EQ(41, result[1]);
}

TEST(splitterTest, threeSectionComplex) {
    //when
    auto result = splitInputData(ROOT_DIR + "three-sections-complex.txt", 3);

    //then
    ASSERT_EQ(3, result.size());
    ASSERT_EQ(28, result[0]);
    ASSERT_EQ(56, result[1]);
    ASSERT_EQ(72, result[2]);
}
