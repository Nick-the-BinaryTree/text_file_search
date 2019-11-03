#include "gui.cc"

#include <gtkmm/application.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  GUI window;

  //Shows the window and returns when it is closed.
  return app->run(window);
}