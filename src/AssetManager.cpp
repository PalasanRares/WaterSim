#include "AssetManager.hpp"

#include "types.hpp"

AssetManager::AssetManager() {
  loadElementIcons();
  loadElementLabels();
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
}

AssetManager* AssetManager::instance = nullptr;

AssetManager* AssetManager::getInstance() {
  if (instance == nullptr) {
    instance = new AssetManager();
  }
  return instance;
}

string AssetManager::getElementIcon(const int& element) {
  return elementIcons[element];
}

string AssetManager::getElementLabel(const int& element) {
  return elementLabels[element];
}
