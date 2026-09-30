#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Parallelogram.h"

#include "Matthews.h"

using sequence::MatthewsOutcome;
using sequence::checkMatthewsOutcome;

using namespace testing;

using shapes::Angle;
using shapes::Parallelogram;
using shapes::Side;

constexpr double ktolerance = 1e-9;

// 4 tests hiding arithmetic bugs

TEST(ParallelogramTests, PerimeterOfEqualSidedShapeIsFourTimesSide) {
  Parallelogram p{Side{4}, Side{4}, Angle{60.0}};
  EXPECT_EQ(16, p.getPerimeter());
}

TEST(ParallelogramTests, AreaOfEqualSidedShapeScalesWithSineOfAngle) {
  Parallelogram p{Side{4}, Side{4}, Angle{30.0}};
  EXPECT_NEAR(8.0,p.getArea(), ktolerance);
}

TEST(ParallelogramTests, EqualSidesAtObliqueAngleIsRhombus) {
  Parallelogram p{Side{4}, Side{4}, Angle{60.0}};
  EXPECT_EQ(Parallelogram::Kind::RHOMBUS, p.getKind());
}

TEST(ParallelogramTests, DistinctSidesAtObliqueAngleIsPlainParallelogram) {
  Parallelogram p{Side{3}, Side{8}, Angle{72.5}};
  EXPECT_EQ(Parallelogram::Kind::PARALLELOGRAM, p.getKind());
}

// three bugs


TEST(ParallelogramTests, PerimeterSumsBothDistinctSides) {
  Parallelogram p{Side{3}, Side{5}, Angle{90.0}};
  EXPECT_EQ(16, p.getPerimeter()); // should return 12
}


TEST(ParallelogramTests, AreaMultipliesBothDistinctSides) {
  Parallelogram p{Side{3}, Side{4}, Angle{90.0}};
  EXPECT_NEAR(12, p.getArea(), ktolerance); // should return 16
}


TEST(ParallelogramTests, EqualSidesAtRightAngleIsSquare) {
  Parallelogram p{Side{4}, Side{4}, Angle{90.0}};
  EXPECT_EQ(Parallelogram::Kind::SQUARE, p.getKind()); // returns rectangle when its actually a square
}

// Task 2 Matthews

// reminder == 0

TEST(MatthewsTests, MultipleOfThreeIsZero) {
  EXPECT_EQ(MatthewsOutcome::ZERO, checkMatthewsOutcome(3));
}

// number == -1
TEST(MatthewsTests, NegativeOneReturnsMinusOneCycle) {
  EXPECT_EQ(MatthewsOutcome::MINUS_ONE_CYCLE, checkMatthewsOutcome(-1));
}

// number == -2
TEST(MatthewsTests, NegativeTwoReturnsNegativeTwoCycle) {
  EXPECT_EQ(MatthewsOutcome::MINUS_TWO_CYCLE, checkMatthewsOutcome(-2));
}

// number == -4
TEST(MatthewsTests, NegativeFourReturnsNegativeTwoCycle) {
  EXPECT_EQ(MatthewsOutcome::MINUS_TWO_CYCLE, checkMatthewsOutcome(-4));
}

// remainder == 1
TEST(MatthewsTests, RemainderOneTakesGrowingBranchThenTerminates) {
  EXPECT_EQ(MatthewsOutcome::ZERO, checkMatthewsOutcome(1));     
}

// remainder == 2
TEST(MatthewsTests, RemainderTwoTakesShrinkingBranchThenTerminates) {
  EXPECT_EQ(MatthewsOutcome::ZERO, checkMatthewsOutcome(2));
}