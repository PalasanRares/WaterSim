target_sources(WaterSim
    PRIVATE
        MovableSolid.hpp
        Sand.hpp
        Dirt.hpp
)

target_include_directories(WaterSim PUBLIC ${CMAKE_CURRENT_LIST_DIR})
