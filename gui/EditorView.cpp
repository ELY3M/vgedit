#include "EditorView.hpp"

EditorView::EditorView(Editor* editor)
{
  // initialize the text view for the first time, using whatever's in the editor
  mainTextField = new TextInputElement(editor->contents());
  mainTextField->x = 20;
  mainTextField->y = 20;
  this->elements.push_back(mainTextField);

  this->editor = editor;
}

void EditorView::render(Element* parent)
{
  SDL_Rect background = { 15, 15, 1240, 690 };

  SDL_SetRenderDrawColor(parent->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderFillRect(parent->renderer, &background);

  super::render(parent);
}

bool EditorView::process(InputEvents* e)
{
  int selected_x = mainTextField->selected_x;
  int selected_y = mainTextField->selected_y;

  if (e->pressed(LEFT_BUTTON | RIGHT_BUTTON | UP_BUTTON | DOWN_BUTTON))
  {
    if (e->pressed(LEFT_BUTTON))
      selected_x -= 1;
    if (e->pressed(RIGHT_BUTTON))
      selected_x += 1;
    if (e->pressed(UP_BUTTON))
      selected_y -= 1;
    if (e->pressed(DOWN_BUTTON))
      selected_y += 1;
    
    selected_y = selected_y < 0 ? 0 : selected_y;
    selected_y = selected_y > editor->lines.size()-1 ? editor->lines.size()-1 : selected_y;
    selected_x = selected_x < 0 ? 0 : selected_x;
    selected_x = selected_x > editor->lines[selected_y].size()-1 ? editor->lines[selected_y].size()-1  : selected_x;

    mainTextField->selected_x = selected_x;
    mainTextField->selected_y = selected_y;
    return true;
  }
  return false;
}