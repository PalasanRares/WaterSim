#ifndef _ASSET_MANAGER_HPP_
#define _ASSET_MANAGER_HPP_

#include <map>
#include <string>

#include <SDL3/SDL.h>

using namespace std;

class AssetManager {
private:
  AssetManager();

  void loadElementIcons();
  void loadElementLabels();
  void loadCursors();

  static AssetManager* instance;

  map<int, string> elementIcons;
  map<int, string> elementLabels;
  map<int, string> cursors;

public:
  static AssetManager* getInstance();

  const string& getElementIcon(const int& element);
  const string& getElementLabel(const int& element);
  const string& getCursor(const int& brushSize);

};

#endif
