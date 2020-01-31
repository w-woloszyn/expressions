#pragma once
#include "boolean_visitor.h"
#include "integer_visitor.h"
struct Expression {
  ExpressionType expression;
  template <typename... Ts>
  Expression(Ts &&... xs) : expression(std::forward<Ts>(xs)...) {}
  auto get() const -> const ExpressionType & { return expression; }
  auto get() -> ExpressionType & { return expression; }

  auto operator+(Expression &expr) -> Expression {
    return std::visit(AddVisitor{}, get(), expr.expression);
  }
  auto operator+(Expression &&expr) -> Expression {
    return std::visit(AddVisitor{}, get(), expr.expression);
  }
  auto operator-() -> Expression { return std::visit(MinusVisitor{}, get()); }
  auto operator-(Expression &expr) -> Expression {
    return std::visit(MinusVisitor{}, get(), expr.expression);
  }
  auto operator-(Expression &&expr) -> Expression {
    return std::visit(MinusVisitor{}, get(), expr.expression);
  }
  auto operator*(Expression &expr) -> Expression {
    return std::visit(MultiplyVisitor{}, get(), expr.expression);
  }
  auto operator*(Expression &&expr) -> Expression {
    return std::visit(MultiplyVisitor{}, get(), expr.expression);
  }
  auto operator/(Expression &expr) -> Expression {
    return std::visit(DivideVisitor{}, get(), expr.expression);
  }
  auto operator/(Expression &&expr) -> Expression {
    return std::visit(DivideVisitor{}, get(), expr.expression);
  }
  auto operator!() -> Expression { return std::visit(NotVisitor{}, get()); }
  auto operator&&(Expression &expr) -> Expression {
    return std::visit(AndVisitor{}, get(), expr.expression);
  }
  auto operator&&(Expression &&expr) -> Expression {
    return std::visit(AndVisitor{}, get(), expr.expression);
  }
  auto operator||(Expression &expr) -> Expression {
    return std::visit(OrVisitor{}, get(), expr.expression);
  }
  auto operator||(Expression &&expr) -> Expression {
    return std::visit(OrVisitor{}, get(), expr.expression);
  }
  auto operator==(Expression &expr) -> Expression {
    return std::visit(EqualsVisitor{}, get(), expr.expression);
  }
  auto operator==(Expression &&expr) -> Expression {
    return std::visit(EqualsVisitor{}, get(), expr.expression);
  }
  auto isBool() -> bool {
    return std::visit(
        [](ExpressionType &&arg) -> bool {
          return std::holds_alternative<bool>(arg);
        },
        get());
  }
  auto isInt() -> bool {
    return std::visit(
        [](ExpressionType &&arg) -> bool {
          return std::holds_alternative<int>(arg);
        },
        get());
  }
  auto typeCheck() -> bool { return isBool() || isInt(); }

  template <typename T> auto evaluateT() {
    return std::visit(
        [](ExpressionType &&arg) -> T { return std::get<T>(arg); }, get());
  }
  auto evaluate() -> int {
    if (isInt()) {
      return evaluateT<int>();
    }
    return evaluateT<bool>();
  }
};
