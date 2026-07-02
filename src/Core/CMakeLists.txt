#Link Source to library
target_sources(
          img-generator
     PRIVATE
          ${SOURCE_DIR}/Core/ASCIIGenerator.cpp
     )
#use C++20 Standart
target_compile_features(
          img-generator
     PUBLIC
          cxx_std_20
     )
