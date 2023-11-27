target_sources(WaterSim
    PRIVATE
        Element.hpp
        Eraser.hpp
)

target_include_directories(WaterSim PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(gases)
add_subdirectory(liquids)
add_subdirectory(solids/immovable)
add_subdirectory(solids/movable)
