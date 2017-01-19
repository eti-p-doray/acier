#pragma once

#include <utility>
#include <functional>

//#include "base/functional/invoke.hpp"
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




#define ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(op, fcn) \
template <class T, class U, \
    when< std::is_bind_expression<decay_t<T>>{} || \
          std::is_bind_expression<decay_t<U>>{} > = 0> \
decltype(auto) operator op(T&& t, U&& u) { \
  return bind(fcn(), fw<T>(t), fw<U>(u)); \
}

#define ACIER_DEFINE_FUNCTONAL_UNARY_OPERATOR(op, fcn) \
template <class T, \
    when< std::is_bind_expression<decay_t<T>>{} > = 0> \
decltype(auto) operator op (T&& t) { \
  return bind(fcn(), fw<T>(t)); \
}

#define ACIER_DEFINE_FUNCTONAL_POSTFIX_UNARY_OPERATOR(op, fcn) \
template <class T, \
    when< std::is_bind_expression<decay_t<T>>{} > = 0> \
decltype(auto) operator op (T&& t, int) { \
  return bind(fcn(), fw<T>(t)); \
}


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

inline namespace fcn_ops {

ACIER_DEFINE_FUNCTONAL_UNARY_OPERATOR(*, dereference);
ACIER_DEFINE_FUNCTONAL_UNARY_OPERATOR(&, address_of);

ACIER_DEFINE_FUNCTONAL_UNARY_OPERATOR(++, pre_increment);
ACIER_DEFINE_FUNCTONAL_UNARY_OPERATOR(--, pre_decrement);
ACIER_DEFINE_FUNCTONAL_POSTFIX_UNARY_OPERATOR(++, post_increment);
ACIER_DEFINE_FUNCTONAL_POSTFIX_UNARY_OPERATOR(--, post_decrement);

ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(==, equal_to);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(!=, not_equal_to);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(<, less);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(>, greater);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(<=, less_equal);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(>=, greater_equal);

ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(+, plus);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(-, minus);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(*, multiplies);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(/, divides);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(%, modulus);
ACIER_DEFINE_FUNCTONAL_UNARY_OPERATOR(+, unary_plus);
ACIER_DEFINE_FUNCTONAL_UNARY_OPERATOR(-, negate);

ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(&, bit_and);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(|, bit_or);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(^, bit_xor);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(<<, left_shift);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(>>, right_shift);

ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(&&, logical_and);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(||, logical_or);
ACIER_DEFINE_FUNCTONAL_UNARY_OPERATOR(!, logical_not);

ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(+=, plus_assign);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(-=, minus_assign);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(*=, multiplies_assign);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(/=, divides_assign);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(%=, modulus_assign);

ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(&=, bit_and_assign);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(|=, bit_or_assign);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(^=, bit_xor_assign);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(<<=, left_shift_assign);
ACIER_DEFINE_FUNCTONAL_BINARY_OPERATOR(>>=, right_shift_assign);

//pipes operator
/*template <class T, class F>
result_of_t<F(T)> operator|(T&& value, F&& fn) {
  return invoke(fw<F>(fn), fw<T>(value));
}*/

struct adl {};
}

}
