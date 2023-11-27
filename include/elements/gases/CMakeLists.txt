target_sources(WaterSim
    PRIVATE
        Fire.hpp
        Gas.hpp
        Vapor.hpp
)

target_include_directories(WaterSim PUBLIC ${CMAKE_CURRENT_LIST_DIR})
