#Link Source to library
target_sources(
          Core
     PRIVATE
          ${SOURCE_DIR}/Core/ASCIIGenerator.cpp
     )
#use C++20 Standart
target_compile_features(
          Core
     PUBLIC
          cxx_std_20
     )
