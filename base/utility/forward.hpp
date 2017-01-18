#pragma once

#include "base/type_traits.hpp"

namespace base {

template <class T>
constexpr T&& fw( remove_reference_t<T>& t ) noexcept {
	return static_cast<T&&>(t);
}

template <class T>
constexpr T&& fw( remove_reference_t<T>&& t ) noexcept {
	return static_cast<T&&>(t);
}

}