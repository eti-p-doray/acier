#pragma once

#include <type_traits>

#include "base/utility/forward.hpp"
#include "base/utility/type_traits.hpp"

namespace acier {

template <class T, class = when<true>>
class compressed {
 public:
 	constexpr compressed(T&& value)
 			: member(fw<T>(value)) {}

 				T& get()
 	{ return member; }
 	const T& get() const
 	{ return member; }

 	operator 			 T&()
 	{ return member; }
 	operator const T&() const
 	{ return member; }

 private:
 	T member;
};

template <class T>
class compressed<T, when< std::is_empty<T>{} && !std::is_final<T>{} >> 
		: private T {
 public:
	constexpr compressed(T&& value)
 			: T(fw<T>(value)) {}

				T& get()
 	{ return *this; }
 	const T& get() const
 	{ return *this; }

 	operator 			 T&()
 	{ return *this; }
 	operator const T&() const
 	{ return *this; }
 	
};

}