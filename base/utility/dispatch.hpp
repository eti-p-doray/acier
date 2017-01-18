#pragma once

namespace base {

// dispatching tags with priority
template <size_t> struct dispatch_tag : tag<i-1> { using base = tag<i-1>; };
template <> struct dispatch_tag<0> {};

// overload_tag has precedence over default_tag
using default_tag = dispatch_tag<0>;
using overload_tag = dispatch_tag<1>;

namespace tags {

using _1 = dispatch_tag<8>;
using _2 = dispatch_tag<7>;
using _3 = dispatch_tag<6>;
using _4 = dispatch_tag<5>;
using _5 = dispatch_tag<4>;
using _6 = dispatch_tag<3>;
using _7 = dispatch_tag<2>;
using _8 = dispatch_tag<1>;
using _9 = dispatch_tag<0>;

constexpr _1 first = {};

}

}