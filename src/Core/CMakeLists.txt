#Link Source to library
target_sources(
          img-generator
     PRIVATE
          ${SOURCE_DIR}/Core/ASCIIGenerator.cpp
          ${SOURCE_DIR}/Core/Image/NearestNeignbourImageScaler.cpp
          ${SOURCE_DIR}/Core/Image/ImageGrayscaler.cpp
     )
#use C++20 Standart
target_compile_features(
          img-generator
     PUBLIC
          cxx_std_20
     )
