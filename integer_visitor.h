#pragma once
#include "expression_type.h"

struct AddVisitor {
  auto operator()(int a, int b) const -> ExpressionType { return a + b; }
  auto operator()(ExpressionType &a, ExpressionType &b) const
      -> ExpressionType {
    return std::visit(AddVisitor{}, a, b);
  }
  template <class T, class U> auto operator()(T, U) const -> ExpressionType {
    return std::monostate();
  }
};

struct MinusVisitor {
  auto operator()(int a) const -> ExpressionType { return -a; }
  auto operator()(ExpressionType &a) const -> ExpressionType {
    return std::visit(MinusVisitor{}, a);
  }
  auto operator()(int a, int b) const -> ExpressionType { return a - b; }
  auto operator()(ExpressionType &a, ExpressionType &b) const
      -> ExpressionType {
    return std::visit(MinusVisitor{}, a, b);
  }
  template <class T> auto operator()(T) const -> ExpressionType {
    return std::monostate();
  }
  template <class T, class U> auto operator()(T, U) const -> ExpressionType {
    return std::monostate();
  }
};

struct MultiplyVisitor {
  auto operator()(int a, int b) const -> ExpressionType { return a * b; }
  auto operator()(ExpressionType &a, ExpressionType &b) const
      -> ExpressionType {
    return std::visit(MultiplyVisitor{}, a, b);
  }
  template <class T, class U> auto operator()(T, U) const -> ExpressionType {
    return std::monostate();
  }
};

struct DivideVisitor {
  auto operator()(int a, int b) const -> ExpressionType { return a / b; }
  auto operator()(ExpressionType &a, ExpressionType &b) const
      -> ExpressionType {
    return std::visit(DivideVisitor{}, a, b);
  }
  template <class T, class U> auto operator()(T, U) const -> ExpressionType {
    return std::monostate();
  }
};

struct EqualsVisitor {
  auto operator()(int a, int b) const -> ExpressionType { return (a == b); }
  auto operator()(ExpressionType &a, ExpressionType &b) const
      -> ExpressionType {
    return std::visit(EqualsVisitor{}, a, b);
  }
  template <class T, class U> auto operator()(T, U) const -> ExpressionType {
    return std::monostate();
  }
};
