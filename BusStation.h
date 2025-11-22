#include "Vector2.h"

#include <iostream>
#include <string>

class BusStation {
private:
  std::string name;
  Vector2 location;

public:
  BusStation(const std::string &name, const int x, const int y) {
    this->name = name;
    this->location = Vector2(x, y);
  }

  const std::string &getName() const { return name; }
  const Vector2 &getLocation() const { return location; }
};