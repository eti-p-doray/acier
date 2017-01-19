#pragma once

#include "base/utility/type_traits.hpp"

namespace acier {

template <class T>
constexpr T&& fw( remove_reference_t<T>& t ) noexcept {
	return static_cast<T&&>(t);
}

template <class T>
constexpr T&& fw( remove_reference_t<T>&& t ) noexcept {
	return static_cast<T&&>(t);
}

}
