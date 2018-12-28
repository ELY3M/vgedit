#include "../libs/hb-appstore/gui/Element.hpp"
#include "../libs/hb-appstore/gui/TextElement.hpp"
#include <SDL2/SDL_image.h>
#pragma once

class EditorView;

class Keyboard : public Element
{
public:
	Keyboard(EditorView* editorView);
	~Keyboard();
	void render(Element* parent);
	bool process(InputEvents* event);

	// setup field variables
	void updateSize();

  EditorView * editorView = NULL;

	// draw a qwerty keyboard
	std::string row1 = "Q W E R T Y U I O P";
	std::string row2 = "A S D F G H J K L";
	std::string row3 = "Z X C V B N M";

	std::vector<std::string> rows;

	// the currently selected row and index
	int curRow = -1;
	int index = -1;

	// the below variables are stored to be used in processing touch events
	// and rendering the drawings to screen

	// attributes of each key
	int keyWidth = 0;
	int padding = 0;
	int textSize = 0;

	// attributes of delete and backspace keys
	int dPos = 0;
	int dHeight = 0;
	int sPos = 0;
	int dWidth = 0;
	int sWidth = 0;

	// positions of key location offset information
	int kXPad = 0;
	int kXOff = 0;
	int yYOff = 0;
	int kYPad = 0;
	int ySpacing = 0;

	bool touchMode = false;

	void space();
	void backspace();
	void type(int y, int x);
	void updateView();
};
