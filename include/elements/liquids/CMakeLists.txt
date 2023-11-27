target_sources(WaterSim
    PRIVATE
        Acid.hpp
        Lava.hpp
        Liquid.hpp
        Water.hpp
)

target_include_directories(WaterSim PUBLIC ${CMAKE_CURRENT_LIST_DIR})
