// for xml usage by tinyxml2.

#include <string>
#include <iostream>
#include <tinyxml2.h>

std::string kxml = 
  "<?xml version=\"1.0\"?>"
  "<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
  "<hello>"
  "  <world/>"
  "</hello>"
  "<hi name=\"hey\" value=\"2\">"
  "  <new>bee</new>"
  "</hi>";

void test_string() {
  using namespace tinyxml2;

  XMLDocument doc;
  doc.Parse(kxml.c_str());
  doc.Print();

  XMLElement *hello = doc.FirstChildElement();
  std::cout << "doc's first child element name=" << hello->Name() << std::endl;
  XMLElement *world = hello->FirstChildElement();
  std::cout << "hello's first child element name=" << world->Name() << std::endl;

  XMLElement *hi = hello->NextSiblingElement();
  std::cout << "hello's next sibling element name=" << hi->Name() << std::endl;

  int value = 0;
  hi->QueryIntAttribute("value", &value);
  std::string name = hi->Attribute("name");

  std::cout << "hi's name=" << name << ", value=" << value << std::endl;

  XMLElement *nb = hi->FirstChildElement();
  std::cout << "hi's first child element name=" << nb->Name() << std::endl;
  std::cout << "nb's text=" << nb->GetText() << std::endl;
}

void test_file() {
  using namespace tinyxml2;
  XMLDocument doc;
  doc.LoadFile("error.xml");

  XMLElement *error = doc.FirstChildElement("Error");
  if (error != nullptr) {
    std::cout << "xml error element find" << std::endl;
  }

  XMLElement *code = error->FirstChildElement("Code");
  if (code != nullptr)
    std::cout << "xml code element find, content=" << code->GetText() << std::endl;
  
  XMLElement *msg = error->FirstChildElement("Message");
  if (msg != nullptr) 
    std::cout << "xml message element find, content=" << msg->GetText() << std::endl;
}

int main() {
  test_string();
  test_file();
  return 0;
}


