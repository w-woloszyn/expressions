#include "gtest/gtest.h"
#include "expression.h"

TEST(Addition, Closure) {
  Expression a, b;
  a = 1;
  b = 2;
  auto result = a + b;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_TRUE(result.isInt());
}
TEST(Addition, Inverse) {
  Expression a, b;
  a = 1;
  auto result = a + (-a);
  ASSERT_TRUE(result.typeCheck());
  EXPECT_EQ(0, result.evaluate());
}
TEST(Addition, Inverse2) {
  Expression a, b;
  a = 1;
  auto result = a - a;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_EQ(0, result.evaluate());
}
TEST(Addition, Associativity) {
  Expression a, b, c;
  a = 1;
  b = 2;
  c = 3;
  auto result = (((a + b) + c) == (a + (b + c)));
  ASSERT_TRUE(result.typeCheck());
  EXPECT_TRUE(result.evaluate());
}
TEST(Addition, Commutativity) {
  Expression a, b, c;
  a = 1;
  b = 2;
  auto result = ((a + b) == (b + a));
  ASSERT_TRUE(result.typeCheck());
  EXPECT_TRUE(result.evaluate());
}
TEST(Multiplication, Closure) {
  Expression a, b;
  a = 1;
  b = 2;
  auto result = a * b;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_TRUE(result.isInt());
}
TEST(Multipication, InverseOfDivision) {
  Expression a, b, c;
  a = 60;
  b = 12;
  auto result = (a / b) * b;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_EQ(std::get<int>(a.get()), result.evaluate());
}
TEST(Multiplication, Associativity) {
  Expression a, b, c;
  a = 1;
  b = 2;
  c = 3;
  auto result = (((a * b) * c) == (a * (b * c)));
  ASSERT_TRUE(result.typeCheck());
  EXPECT_TRUE(result.evaluate());
}
TEST(Multiplication, Commutativity) {
  Expression a, b, c;
  a = 1;
  b = 2;
  auto result = ((a * b) == (b * a));
  ASSERT_TRUE(result.typeCheck());
  EXPECT_TRUE(result.evaluate());
}
TEST(AdditionMultiplication, Distributivity) {
  Expression a, b, c;
  a = 2;
  b = 10;
  c = 31;
  auto result = (a * (b + c) == a * b + a * c);
  ASSERT_TRUE(result.typeCheck());
  EXPECT_TRUE(result.evaluate());
}
TEST(Conjunction, TrueTrueGivesTrue) {
  Expression a, b;
  a = true;
  b = true;
  auto result = a && b;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_TRUE(result.evaluate());
}
TEST(Conjunction, TrueFalseGivesFalse) {
  Expression a, b;
  a = true;
  b = false;
  auto result = a && b;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_FALSE(result.evaluate());
}
TEST(Conjunction, FalseTrueGivesFalse) {
  Expression a, b;
  a = false;
  b = true;
  auto result = a && b;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_FALSE(result.evaluate());
}
TEST(Conjunction, FalseFalseGivesFalse) {
  Expression a, b;
  a = false;
  b = false;
  auto result = a && b;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_FALSE(result.evaluate());
}
TEST(Disjunction, TrueTrueGivesTrue) {
  Expression a, b;
  a = true;
  b = true;
  auto result = a || b;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_TRUE(result.evaluate());
}
TEST(Disjunction, TrueFalseGivesTrue) {
  Expression a, b;
  a = true;
  b = false;
  auto result = a || b;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_TRUE(result.evaluate());
}
TEST(Disjunction, FalseTrueGivesTrue) {
  Expression a, b;
  a = false;
  b = true;
  auto result = a || b;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_TRUE(result.evaluate());
}
TEST(Disjunction, FalseFalseGivesFalse) {
  Expression a, b;
  a = false;
  b = false;
  auto result = a || b;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_FALSE(result.evaluate());
}
TEST(Negation, NotTrueGivesFalse) {
  Expression a;
  a = true;
  auto result = !a;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_FALSE(result.evaluate());
}
TEST(Negation, NotFalseGivesTrue) {
  Expression a;
  a = false;
  auto result = !a;
  ASSERT_TRUE(result.typeCheck());
  EXPECT_TRUE(result.evaluate());
}
TEST(ValidExpression, IntegerPlusInteger) {
  Expression a, b;
  a = 4;
  b = 5;
  auto result = a + b;
  EXPECT_TRUE(result.typeCheck());
}
TEST(InvalidExpression, BooleanPlusInteger) {
  Expression a, b;
  a = true;
  b = 5;
  auto result = a + b;
  EXPECT_FALSE(result.typeCheck());
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
