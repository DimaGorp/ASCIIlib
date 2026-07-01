#Link Source to library
target_sources(
          sfml-adapter
     PRIVATE
          ${SOURCE_DIR}/Adapters/SFMLAdapter.cpp
     )
#use C++20 Standart
target_compile_features(
          sfml-adapter
     PUBLIC
          cxx_std_20
     )
