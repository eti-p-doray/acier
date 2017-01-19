#pragma once

#include <utility>

#include "base/utility/type_traits.hpp"

namespace acier {

using std::swap;

struct swap_fn {
	constexpr void operator()(T&& rhs, U&& lhs) 
	noexcept(swap(fw<T>(rhs), fw<U>(lhs))) ->
	decltype(swap(fw<T>(rhs), fw<U>(lhs)), void()) {
		swap(fw<T>(rhs), fw<U>(lhs));
	}
};

struct member_swap_fn {
	constexpr void operator()(T&& rhs, U&& lhs) {
		fw<T>(rhs).swap(fw<U>(lhs));
	}
};

template <class T, class U>
struct is_swappable_with : is_callable<swap_fn(T, U)> {};
template <class T>
struct is_swappable : is_callable<swap_fn(T, T)> {};

template <class T, class U>
struct is_member_swappable_with : is_callable<member_swap_fn(T, U)> {};

constexpr swap_fn swap() 
{ return {}; }

template <class T, class U,
		when< is_member_swappable_with<T, U>{} > = 0>
void do_swap(tags::_1, T&& lhs, U&& rhs)
noexcept(fw<T>(lhs).swap(fw<U>(rhs))) {
	return fw<T>(lhs).swap(fw<U>(rhs));
}

template <class T, class U,
		when< is_member_swappable_with<T, U>{} > = 0>
void do_swap(tags::_2, T&& lhs, U&& rhs) 
noexcept(fw<U>(rhs).swap(fw<T>(lhs))) {
	return fw<U>(rhs).swap(fw<T>(lhs));
}

template <class T, class U,
		when< is_member_swappable_with<T, U>{} || 
				  is_member_swappable_with<U, T>{} > = 0>
void swap(tags::_2, T&& lhs, U&& rhs) 
noexcept(do_swap(tags::first, fw<T>(lhs), fw<U>(rhs))) {
	return do_swap(tags::first, fw<T>(lhs), fw<U>(rhs));
}

}
