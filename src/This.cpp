class EntityThis {
public:
  int x, y;
  EntityThis(int x, int y) {
    x = x; // 无效
    this->x = x;
    this->y = y;
  };
  int GetX() const {
    // annot initialize a variable of type 'EntityThis *'
    // with an rvalue of type 'const EntityThis *'
    // this 是一个常量指针，指向当前对象
    // const EntityThis *e = this;
    // return (*this).x;
    return this->x;
  };
};

void PrintEntityThis(EntityThis *e) {}

void testThis() { EntityThis e(1, 2); }