#pragma once

#include <type_traits>

namespace base {

template <class T>
using remove_const_t = typename remove_const<T>::type;
template <class T>
using remove_volatile_t = typename remove_volatile<T>::type;
template <class T>
using remove_cv_t = typename remove_cv<T>::type;
template <class T>
using add_const_t = typename add_const<T>::type;
template <class T>
using add_volatile_t = typename add_volatile<T>::type;
template <class T>
using add_cv_t = typename add_cv<T>::type;

template <class T>
using remove_reference_t = typename remove_reference<T>::type;
template <class T>
using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;
template <class T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

template <class T>
using make_signed_t = typename make_signed<T>::type;
template <class T>
using make_unsigned_t = typename make_unsigned<T>::type;

template <class T>
using remove_extent_t = typename remove_extent<T>::type;
template <class T>
using remove_all_extents_t = typename remove_all_extents<T>::type;

template <class T>
using remove_pointer_t = typename remove_pointer<T>::type;
template <class T>
using add_pointer_t = typename add_pointer<T>::type;

//template <size_t Len,
//size_t Align = /*default-alignment*/ > 
//using aligned_storage_t = typename aligned_storage<Len, Align>::type;
template <size_t Len, class... Types>
using aligned_union_t = typename aligned_union<Len, Types...>::type;
template <class T>
using decay_t = typename decay<T>::type;
template <bool b, class T = void>
using enable_if_t = typename enable_if<b, T>::type;
template <bool b, class T, class F>
using conditional_t = typename conditional<b, T, F>::type;
template <class... T>
using common_type_t = typename common_type<T...>::type;
template <class T>
using underlying_type_t = typename underlying_type<T>::type;
template <class T>
using result_of_t = typename result_of<T>::type;


//template <class... T>
//struct models : is_callable<T> {};

template <class T>
constexpr std::true_type returns(T) { return {}; }
constexpr std::true_type expect_true(std::true_type) { return {}; }
constexpr std::true_type expect_false(std::false_type) { return {}; }

template <class... T>
struct always_true : std::true_type {};

template <bool C>
using when = std::enable_if_t<C, int>;
template <class... Expr>
using when_valid = std::enable_if_t<always_true<T...>, int>; 

}