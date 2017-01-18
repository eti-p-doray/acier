#pragma once

#include "base/utility/forward.hpp"
#include "base/utility/type_traits.hpp"
#include "base/functional/operators.hpp"

namespace base {

template <class T, class U>
struct is_equality_comparable : is_callable<equal_to(T, U), bool> {};

namespace equality_comparison { struct adl {};

template <class T, class U,
		when< is_equality_comparable<T, U>{} > = 0>
constexpr bool operator!=(T&& a, U&& b)
{ return !(fw<T>(a) == fw<U>(b)); }

} using equality_comparable = equality_comparison::adl;

}