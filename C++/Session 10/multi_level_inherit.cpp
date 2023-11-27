#include <algorithm>
#include <iostream> 
#include <memory>

class Drawable{
    public:
    virtual void draw() const = 0;
    virtual ~Drawable() {}
};

class Shape{
    public:
    virtual ~Shape() {}
};

class Circle : public Shape, public Drawable {
    public:
    void draw() const override{
        std::cout << "Drawing a Circle" << std::endl;
    }
};

class Rectangle : public Shape, public Drawable {
    public:
    void draw() const override {
        std::cout << "Drawing a rectangle" << std::endl;

    }
};

class Triangle : public Shape, public Drawable {
    public:
    void draw() const override {
        std::cout << "Drawing a Triangle" << std::endl;

    }
};

int main (){

    auto circle =  std::make_unique<Circle>();
    auto rect = std::make_unique<Rectangle>();
    auto triangle = std::make_unique<Triangle>();

    std::unique_ptr<Drawable> drawableObjects[] = {std::move(circle), std::move(rect), std::move(triangle)};

    for (const auto& obj : drawableObjects){
        obj->draw();
    }

    return 0;
}