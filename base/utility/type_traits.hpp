#pragma once

#include <type_traits>

namespace acier {

constexpr struct ignore_t {} ignore {};
constexpr struct blank_t {} blank {};

template <class T>
struct type_ { using type = T; };
template <template <class...> class T>
struct typefcn_ {
  template <class... U>
  using type = T<U...>; 
};

template <class T> using _t = typename T::type;

template <class T> using remove_const_t = _t<std::remove_const<T>>;
template <class T> using remove_volatile_t = _t<std::remove_volatile<T>>;
template <class T> using remove_cv_t = _t<std::remove_cv<T>>;
template <class T> using add_const_t = _t<std::add_const<T>>;
template <class T> using add_volatile_t = _t<std::add_volatile<T>>;
template <class T> using add_cv_t = _t<std::add_cv<T>>;

template <class T> using remove_reference_t = _t<std::remove_reference<T>>;
template <class T> 
using add_lvalue_reference_t = _t<std::add_lvalue_reference<T>>;
template <class T> 
using add_rvalue_reference_t = _t<std::add_rvalue_reference<T>>;

template <class T> using make_signed_t = _t<std::make_signed<T>>;
template <class T> using make_unsigned_t = _t<std::make_unsigned<T>>;

template <class T> using remove_extent_t = _t<std::remove_extent<T>>;
template <class T> using remove_all_extents_t = _t<std::remove_all_extents<T>>;

template <class T> using remove_pointer_t = _t<std::remove_pointer<T>>;
template <class T> using add_pointer_t = _t<std::add_pointer<T>>;


template <size_t Len, size_t Align = 0 > 
using aligned_storage_t = _t<std::aligned_storage<Len, Align>>;
template <size_t Len, class... Types>
using aligned_union_t = _t<std::aligned_union<Len, Types...>>;
template <class T> using decay_t = _t<std::decay<T>>;
template <bool b, class T = void> 
using enable_if_t = _t<std::enable_if<b, T>>;
template <bool b, class T, class F>
using conditional_t = _t<std::conditional<b, T, F>>;
template <class... T> using common_type_t = _t<std::common_type<T...>>;
template <class T> using underlying_type_t = _t<std::underlying_type<T>>;
template <class T> using result_of_t = _t<std::result_of<T>>;


template <class... T>
struct always_true : std::true_type {};

template <bool C>
using when = std::enable_if_t<C, int>;
template <class... E>
using when_valid = std::enable_if_t<always_true<E...>{}, int>; 


template <class T, class R = ignore_t, class = when<true>>
struct is_callable : std::false_type {};
template <class T>
struct is_callable<T, ignore_t, when_valid<result_of_t<T>>> 
    : std::true_type {};
template <class T, class R>
struct is_callable<T, R, when_valid<result_of_t<T>>>
    : std::is_convertible<result_of_t<T>, R> {};


template <class T>
constexpr std::true_type returns(T) { return {}; }

constexpr std::true_type expect_true(std::true_type) { return {}; }
constexpr std::true_type expect_false(std::false_type) { return {}; }

template <class T>
constexpr type_<T> type_of(T&&) { return {}; }

}
