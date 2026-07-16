#include <gtest/gtest.h>
#include <Core/Image/NearestNeignbourImageScaler.hpp>

TEST(NeareastNeignbourImageScaler, Upscaling) {
  
  ASCII::NearestNeignbourImageScaler ImageScaler;
  //ImageScaler.apply()
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}