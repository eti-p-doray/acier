cc_library(
    name = "base",
    hdrs = [
      "functional/operators.hpp",
      "utility/compressed.hpp",
      "utility/dispatch.hpp",
      "utility/operators.hpp",
      "utility/type_traits.hpp",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
  name = "base_unittest",
  srcs = [],
  copts = ["-Iexternal/gtest/include", "-std=c++14"],
  deps = [
    "@gtest//:main",
    ":base",
  ],
)