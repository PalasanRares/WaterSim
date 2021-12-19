#ifndef _ASSET_MANAGER_HPP_
#define _ASSET_MANAGER_HPP_

#include <map>
#include <string>

#include "SDL.h"

using namespace std;

class AssetManager {
private:
  AssetManager();

  void loadElementIcons();
  void loadElementLabels();

  static AssetManager* instance;

  map<int, string> elementIcons;
  map<int, string> elementLabels;

public:
  static AssetManager* getInstance();

  string getElementIcon(const int& element);
  string getElementLabel(const int& element);

};

#endif
