#include "../libs/chesto/src/Element.hpp"
#include "../libs/chesto/src/ImageElement.hpp"
#include "../libs/chesto/src/TextElement.hpp"
#include "../libs/chesto/src/RootDisplay.hpp"
#include <unordered_map>

// TODO: don't forward declare
class FileBrowser;
class EditorView;

class MainDisplay : public RootDisplay
{
public:
	MainDisplay();
	bool process(InputEvents* event);
	void background(int r, int g, int b);
	void update();
	void closeEditor();
	void openFile(bool folder, std::string* path);

	TextElement* notice = NULL;
	FileBrowser* browser = NULL;
	EditorView* editorView = NULL;

	char path_string[2048];

	bool error = false;

	int lastFrameTime = 99;

	bool showingSplash = true;
	int count = 0;
};
