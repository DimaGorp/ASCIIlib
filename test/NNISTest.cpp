#include <gtest/gtest.h>
#include <Core/Image/NearestNeignbourImageScaler.hpp>


TEST(NNIS, upscalingImage)
{
  // Arrange
  std::pair<short,short> input_img_size ={2,2};
  std::vector<Pixel> input_image = {
    {1,1,1,},{2,2,2},
    {3,3,3},{4,4,4}
  };
  std::pair<short,short> expect_img_size ={4,4};
  std::vector<Pixel> expect_image = {
    {1,1,1,},{1,1,1},{2,2,2},{2,2,2},
    {1,1,1,},{1,1,1},{2,2,2},{2,2,2},
    {3,3,3},{3,3,3},{4,4,4},{4,4,4},
    {3,3,3},{3,3,3},{4,4,4},{4,4,4}
  };
  //Act
  ASCII::NearestNeignbourImageScaler ImageScaler(expect_img_size);
  ImageScaler.apply(input_image,input_img_size);
  //Assertion
  EXPECT_EQ(input_image,expect_image) << "Expected image is not the same as filtered one";
  EXPECT_EQ(input_img_size,expect_img_size) << "Input image size does not match expected image size.";
}

TEST(NNIS, downcalingImage)
{
  // Arrange
  std::pair<short,short> input_img_size ={4,4};
  std::vector<Pixel> input_image = {
    {1,1,1,},{1,1,1},{2,2,2},{2,2,2},
    {1,1,1,},{1,1,1},{2,2,2},{2,2,2},
    {3,3,3},{3,3,3},{4,4,4},{4,4,4},
    {3,3,3},{3,3,3},{4,4,4},{4,4,4}
  };
  std::pair<short,short> expect_img_size ={2,2};
  std::vector<Pixel> expect_image = {
    {1,1,1,},{2,2,2},
    {3,3,3},{4,4,4}
  };
  //Act
  ASCII::NearestNeignbourImageScaler ImageScaler(expect_img_size);
  ImageScaler.apply(input_image,input_img_size);
  //Assertion
  EXPECT_EQ(input_image,expect_image) << "Expected image is not the same as filtered one";
  EXPECT_EQ(input_img_size,expect_img_size) << "Input image size does not match expected image size.";
  
}