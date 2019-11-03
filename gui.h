#ifndef GTKMM_GUI_H
#define GTKMM_GUI_H

#include "lib.cc"

#include <gtkmm.h>

class GUI : public Gtk::Window
{
  public:
    GUI();
    virtual ~GUI();

  protected:
    //Signal handlers:
    void on_button_add();
    void on_button_search();

    //Child widgets:
    Gtk::Box m_HBox;
    Gtk::Box m_VBox;
    Gtk::Entry m_Entry;
    Gtk::Button m_Button_Add;
    Gtk::Button m_Button_Search;
    Gtk::CheckButton m_CheckButton_Stem;
    Glib::RefPtr<Gtk::TextBuffer> m_Text_Buffer;
    Gtk::TextView m_Output;

  private:
    inverted_index _ii;

};

#endif