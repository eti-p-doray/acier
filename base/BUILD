cc_library(
    name = "base",
    hdrs = [
      "functional/invoke.hpp",
      "functional/wrapper.hpp",
      "utility/compressed.hpp",
      "utility/dispatch.hpp",
      "utility/forward.hpp",
      "utility/integral_constant.hpp",
      "utility/type_traits.hpp",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
  name = "base_unittest",
  srcs = [
    "functional/invoke_unittest.cpp",
    "utility/compressed_unittest.cpp",
  ],
  copts = ["-Iexternal/gtest/include", "-std=c++14"],
  deps = [
    "@gtest//:main",
    ":base",
  ],
)