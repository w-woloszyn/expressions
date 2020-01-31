#pragma once
#include <variant>
#include <vector>
struct Expression;
using ExpressionType =
    std::variant<int, bool, std::vector<Expression>, std::monostate>;
using ExpressionWrapper = std::vector<Expression>;
