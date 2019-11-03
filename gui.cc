#include "gui.h"

#include <iostream>

GUI::GUI()
: m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_Button_Add("Add File"),
  m_Button_Search("Search for Term"),
  m_CheckButton_Stem("Stem")
{
  set_size_request(400, 150);
  set_title("File Text Search");

  add(m_VBox);

  m_Entry.set_max_length(50);
  m_Entry.set_text("Enter file name or query term");
  m_Entry.select_region(0, m_Entry.get_text_length());
  m_VBox.pack_start(m_Entry);

  // Note that add() can also be used instead of pack_xxx()
  m_VBox.add(m_CheckButton_Stem);
  m_CheckButton_Stem.set_active(true);


  m_HBox.pack_start(m_Button_Add);
  m_Button_Add.signal_clicked().connect( sigc::mem_fun(*this,
              &GUI::on_button_add) );

  m_HBox.pack_start(m_Button_Search);
  m_Button_Search.signal_clicked().connect( sigc::mem_fun(*this,
              &GUI::on_button_search) );
              
  m_VBox.pack_start(m_HBox, Gtk::PACK_SHRINK);

  m_VBox.pack_start(m_Output);
  m_Text_Buffer = Gtk::TextBuffer::create();
  m_Output.set_buffer(m_Text_Buffer);
  m_Output.set_editable(false);

  show_all_children();
}

GUI::~GUI()
{
}

void GUI::on_button_add()
{
  try {
    _ii = mergeIndices(
      _ii,
      addFile(m_Entry.get_text(), m_CheckButton_Stem.get_active())
    );
    m_Text_Buffer->set_text("Added file");
  } catch (...) {
    m_Text_Buffer->set_text("Error adding file");
  }
}

void GUI::on_button_search()
{
  vector<string> searchResults = searchTerm(m_Entry.get_text(), _ii);
  m_Text_Buffer->set_text(getSearchResultString(searchResults));
}