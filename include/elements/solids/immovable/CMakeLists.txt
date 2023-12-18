target_sources(WaterSim
    PRIVATE
        Glass.hpp
        ImmovableSolid.hpp
        Stone.hpp
        Wood.hpp
        Iron.hpp
)

target_include_directories(WaterSim PUBLIC ${CMAKE_CURRENT_LIST_DIR})
