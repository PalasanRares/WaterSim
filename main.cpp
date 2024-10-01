#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <iostream>

#include "RenderWindow.hpp"
#include "Water.hpp"
#include "Eraser.hpp"
#include "Element.hpp"
#include "Liquid.hpp"
#include "Acid.hpp"
#include "Matrix.hpp"
#include "types.hpp"
#include "AssetManager.hpp"
#include "Drawer.hpp"

#define MAX_TICK_SPEED 120
#define MIN_TICK_SPEED 30

using namespace std;

int main(int argc, char** argv) {
	const char* title = "WaterSim 0.10";
	const int width = 250;
	const int height = 125;
	int tickSpeed = 60;
	watersim::byte element = 1;
	watersim::byte elementNr = 11;
	RenderWindow* window = new RenderWindow(title, width * 4, height * 4);
	bool running = true;

	SDL_HideCursor();

	Matrix* matrix = new Matrix(width, height);
	Drawer* drawer = new Drawer(3);

	SDL_Event event;

	float xMouse, yMouse;

	int brushSize = drawer->getBrushSize();

	AssetManager* assetManager = AssetManager::getInstance();

	uint32_t lastTime = SDL_GetTicks();
	uint32_t lastTick = SDL_GetTicks();
	int noFrames = 0;

	while (running) {

		uint32_t currentTime = SDL_GetTicks();
		noFrames += 1;
		if (currentTime - lastTime >= 1000) {
			std::cout << 1000.0f / noFrames << " ms/frame" << std::endl;
			noFrames = 0;
			lastTime += 1000;
		}

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_EVENT_QUIT:
					running = false;
					break;
				case SDL_EVENT_KEY_DOWN:
					switch (event.key.keysym.sym) {
						case SDLK_RIGHT:
							drawer->modifyBrushSize(1);
							brushSize = drawer->getBrushSize();
							break;
						case SDLK_LEFT:
							drawer->modifyBrushSize(-1);
							brushSize = drawer->getBrushSize();
							break;
						case SDLK_UP:
							element = (element + 1) % elementNr;
							break;
						case SDLK_DOWN:
							if (element == 0) {
								element = elementNr - 1;
							}
							else {
								element = (element - 1) % elementNr;
							}
							break;
						case SDLK_u:
							tickSpeed += tickSpeed + 30 <= MAX_TICK_SPEED ? 30 : 0;
							break;
						case SDLK_j:
							tickSpeed -= tickSpeed - 30 >= MIN_TICK_SPEED ? 30 : 0;
							break;
					}
					break;
			}
		}

		Uint32 buttons = SDL_GetMouseState(&xMouse, &yMouse);
		if (buttons & SDL_BUTTON(1)) {
			drawer->drawElement(matrix, xMouse / 4, yMouse / 4, element);
		}

		int cursorOffsetX = xMouse - (brushSize + 3) * 3;
		int cursorOffsetY = yMouse - (brushSize + 3) * 3;

		uint32_t currentTick = SDL_GetTicks();
		
		if (currentTick - lastTick >= 1000.0f / tickSpeed) {
			matrix->updateMatrix();
			matrix->refreshMatrix();
			lastTick = currentTick;
		}

		window->clear();
		window->renderMatrix(matrix, width, height);

		SDL_Texture* elementIcon = window->loadImage(assetManager->getElementIcon(element));
		SDL_Texture* elementLabel = window->loadText(assetManager->getElementLabel(element));
		SDL_Texture* cursor = window->loadImage(assetManager->getCursor(brushSize));
		SDL_Texture* tickSpeedLabel = window->loadText("Ticks: " + std::to_string(tickSpeed));
		window->renderTexture(elementIcon, 10, 10, 2);
		window->renderTexture(elementLabel, 10, 75, 1);
		window->renderTexture(cursor, cursorOffsetX, cursorOffsetY, 4);
		window->renderTexture(tickSpeedLabel, 845, 10, 1);
		SDL_DestroyTexture(elementIcon);
		SDL_DestroyTexture(elementLabel);
		SDL_DestroyTexture(cursor);

		window->display();
	}

	delete window;
	delete matrix;
	return 0;
}
