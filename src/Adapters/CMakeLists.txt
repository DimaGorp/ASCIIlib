if(ADAPTERS_LIBRARY)
    #Link Source to library
    target_sources(
            img-adapters
        PRIVATE
            $<$<BOOL:${SFML_ADAPTER}>:${SOURCE_DIR}/Adapters/SFMLAdapter.cpp>
        )
    #use C++20 Standart
    target_compile_features(
            img-adapters
        PUBLIC
            cxx_std_20
    )
endif()
if(SFML_ADAPTER)
    #link SFML
    find_package(SFML 3.0 COMPONENTS Graphics CONFIG REQUIRED)
    target_link_libraries(img-adapters PRIVATE SFML::Graphics)
endif()
