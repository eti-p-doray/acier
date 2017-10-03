#pragma once

#include <utility>
#include <functional>

#include "base/utility/forward.hpp"
#include "base/utility/type_traits.hpp"

#define ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(op, fcn) \
struct fcn { \
  template <class T, class U> \
  constexpr auto operator()(T&& t, U&& u) const -> \
  decltype(fw<T>(t) op fw<U>(u)) { \
    return fw<T>(t) op fw<U>(u); \
  } \
};

#define ACIER_DEFINE_UNARY_GENERIC_FUNCTOR(op, fcn) \
struct fcn { \
  template <class T> \
  constexpr auto operator()(T&& t) const -> \
  decltype(op fw<T>(t)) { \
    return op fw<T>(t); \
  } \
};

#define ACIER_DEFINE_POSTFIX_UNARY_GENERIC_FUNCTOR(op, fcn) \
struct fcn { \
  template <class T> \
  constexpr auto operator()(T&& t, int) const -> \
  decltype(fw<T>(t) op ) { \
    return fw<T>(t) op; \
  } \
};

namespace acier {

ACIER_DEFINE_UNARY_GENERIC_FUNCTOR(, identity);
ACIER_DEFINE_UNARY_GENERIC_FUNCTOR(*, dereference);
ACIER_DEFINE_UNARY_GENERIC_FUNCTOR(&, address_of);

ACIER_DEFINE_UNARY_GENERIC_FUNCTOR(++, pre_increment);
ACIER_DEFINE_UNARY_GENERIC_FUNCTOR(--, pre_decrement);
ACIER_DEFINE_POSTFIX_UNARY_GENERIC_FUNCTOR(++, post_increment);
ACIER_DEFINE_POSTFIX_UNARY_GENERIC_FUNCTOR(--, post_decrement);

ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(==, equal_to);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(!=, not_equal_to);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(<, less);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(>, greater);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(<=, less_equal);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(>=, greater_equal);

ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(+, plus);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(-, minus);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(*, multiplies);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(/, divides);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(%, modulus);
ACIER_DEFINE_UNARY_GENERIC_FUNCTOR(+, unary_plus);
ACIER_DEFINE_UNARY_GENERIC_FUNCTOR(-, negate);

ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(&, bit_and);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(|, bit_or);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(^, bit_xor);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(<<, left_shift);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(>>, right_shift);

ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(&&, logical_and);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(||, logical_or);
ACIER_DEFINE_UNARY_GENERIC_FUNCTOR(!, logical_not);

ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(=, assign);

ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(+=, plus_assign);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(-=, minus_assign);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(*=, multiplies_assign);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(/=, divides_assign);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(%=, modulus_assign);

ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(&=, bit_and_assign);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(|=, bit_or_assign);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(^=, bit_xor_assign);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(<<=, left_shift_assign);
ACIER_DEFINE_BINARY_GENERIC_FUNCTOR(>>=, right_shift_assign);

struct subscript {
  template <class T, class U>
  constexpr auto operator()(T&& lhs, U&& rhs) const ->
  decltype(fw<U>(rhs)[fw<U>(rhs)]) {
    return fw<U>(rhs)[fw<U>(rhs)];
  }
};

struct first {
  template <class T>
  constexpr auto operator()(T&& x) const ->
  delctype(fw<T>(x).first) {
    return fw<T>(x).first;
  }
};

struct second {
  template <class T>
  constexpr auto operator()(T&& x) const ->
  delctype(fw<T>(x).second) {
    return fw<T>(x).second;
  }
};

}
