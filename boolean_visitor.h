#pragma once
#include "expression_type.h"

struct NotVisitor {
  auto operator()(bool a) const -> ExpressionType { return !a; }
  auto operator()(ExpressionType &a, ExpressionType &b) const
      -> ExpressionType {
    return std::visit(NotVisitor{}, a);
  }
  template <class T> auto operator()(T) const -> ExpressionType {
    return std::monostate();
  }
};

struct AndVisitor {
  auto operator()(bool a, bool b) const -> ExpressionType { return a && b; }
  auto operator()(ExpressionType &a, ExpressionType &b) const
      -> ExpressionType {
    return std::visit(AndVisitor{}, a, b);
  }
  template <class T, class U> auto operator()(T, U) const -> ExpressionType {
    return std::monostate();
  }
};

struct OrVisitor {
  auto operator()(bool a, bool b) const -> ExpressionType { return a || b; }
  auto operator()(ExpressionType &a, ExpressionType &b) const
      -> ExpressionType {
    return std::visit(AndVisitor{}, a, b);
  }
  template <class T, class U> auto operator()(T, U) const -> ExpressionType {
    return std::monostate();
  }
};
