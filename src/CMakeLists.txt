target_sources(WaterSim
    PRIVATE
        AssetManager.cpp
        colorPicker.cpp
        Drawer.cpp
        Matrix.cpp
        RenderWindow.cpp
)

add_subdirectory(elements)
add_subdirectory(managers)
