#include <gtest/gtest.h>
#include <Core/Image/NearestNeignbourImageScaler.hpp>
TEST(NeareastNeignbourImageScaler, Upscaling) {

  //Inputs
  std::vector<Pixel> input_img{
    Pixel(1,1,1),Pixel(2,2,2),
    Pixel(3,3,3),Pixel(4,4,4)
  };
  std::pair<short,short> input_img_size = std::make_pair<short,short>(2,2);
  //Operation
  ASCII::NearestNeignbourImageScaler ImageScaler({2,1});
  ImageScaler.apply(input_img,input_img_size);
  //Assertion
  EXPECT_EQ(input_img_size, std::make_pair(2,1));
  EXPECT_EQ(input_img,std::vector<Pixel>({Pixel(1,1,1),Pixel(2,2,2)}));
}