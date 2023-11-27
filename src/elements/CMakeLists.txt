target_sources(WaterSim
    PRIVATE
        Element.cpp
        Eraser.cpp
)

add_subdirectory(gases)
add_subdirectory(liquids)
add_subdirectory(solids/immovable)
add_subdirectory(solids/moveable)
