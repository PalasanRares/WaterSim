#include "AssetManager.hpp"

#include "types.hpp"

AssetManager::AssetManager() {
  loadElementIcons();
  loadElementLabels();
  loadCursors();
}

void AssetManager::loadElementIcons() {
  elementIcons[ERASER] = "./res/Eraser.png";
	elementIcons[WATER] = "./res/Water.png";
  elementIcons[ACID] = "./res/Acid.png";
  elementIcons[FIRE] = "./res/Fire.png";
  elementIcons[GLASS] = "./res/Glass.png";
  elementIcons[LAVA] = "./res/Lava.png";
  elementIcons[SAND] = "./res/Sand.png";
  elementIcons[STONE] = "./res/Stone.png";
  elementIcons[VAPOR] = "./res/Vapor.png";
  elementIcons[WOOD] = "./res/Wood.png";
  elementIcons[IRON] = "./res/Iron.png";
}

void AssetManager::loadElementLabels() {
  elementLabels[ERASER] = "Eraser";
  elementLabels[WATER] = "Water";
  elementLabels[ACID] = "Acid";
  elementLabels[FIRE] = "Fire";
  elementLabels[GLASS] = "Glass";
  elementLabels[LAVA] = "Lava";
  elementLabels[SAND] = "Sand";
  elementLabels[STONE] = "Stone";
  elementLabels[VAPOR] = "Vapor";
  elementLabels[WOOD] = "Wood";
  elementLabels[IRON] = "Iron";
}

void AssetManager::loadCursors() {
  cursors[1] = "./res/Cursor1.png";
  cursors[2] = "./res/Cursor2.png";
  cursors[3] = "./res/Cursor3.png";
}

AssetManager* AssetManager::instance = nullptr;

AssetManager* AssetManager::getInstance() {
  if (instance == nullptr) {
    instance = new AssetManager();
  }
  return instance;
}

const string& AssetManager::getElementIcon(const int& element) {
  return elementIcons[element];
}

const string& AssetManager::getElementLabel(const int& element) {
  return elementLabels[element];
}

const string& AssetManager::getCursor(const int& brushSize) {
  return cursors[brushSize];
}
