#Link Source to library
target_sources(
          Core
     PRIVATE
          ${SOURCE_DIR}/Core/ASKII.cpp
     )
#use C++20 Standart
target_compile_features(
          Core
     PRIVATE
          cxx_std_20
     )