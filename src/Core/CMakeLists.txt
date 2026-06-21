#Link Source to library
target_sources(
          Image
     PRIVATE
          ${SOURCE_DIR}/Core/ASCIIGenerator.cpp
          ${SOURCE_DIR}/Core/Adapters/SFMLAdapter.cpp
     )
#use C++20 Standart
target_compile_features(
          Image
     PUBLIC
          cxx_std_20
     )
