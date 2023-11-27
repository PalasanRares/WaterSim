target_sources(WaterSim
    PRIVATE
        AssetManager.hpp
        colorPicker.hpp
        Drawer.hpp
        Matrix.hpp
        RenderWindow.hpp
        types.hpp
)

target_include_directories(WaterSim PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory(elements)
add_subdirectory(factories)
