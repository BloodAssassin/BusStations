#include <cmath>

class Vector2 {
private:
  float x;
  float y;

public:
  Vector2(float x = 0, float y = 0) {
    this->x = x;
    this->y = y;
  }

  static int Distance(const Vector2 &a, const Vector2 &b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
  }
};