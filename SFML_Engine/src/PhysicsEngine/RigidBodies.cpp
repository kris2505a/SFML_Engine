#include "Headers/RigidBodies.h"

namespace PhysicsEngine {

    //Rectangle Start

    Rectangle::Rectangle(sf::Vector2f pos, float w, float h)
        : Object{ pos }, width{ w }, height{ h } {
        
        this->rectangle.setPosition(this->position);
        this->rectangle.setSize(sf::Vector2f(this->width, this->height));
        this->rectangle.setFillColor(sf::Color::White);

    }


    bool Rectangle::isCollided(const Object& otherObject) {
        // logic
        return false; 
    }


    float Rectangle::getArea() {
        return this->width * this->height;
    }

    void Rectangle::draw(sf::RenderWindow* window) {
        window->draw(this->rectangle);
    }

    void Rectangle::update(float deltaTime) {

    }
    //Rectangle end
}



namespace PhysicsEngine {

    //Circle start

    Circle::Circle(sf::Vector2f pos, float rad)
        : Object{ pos }, radius{ rad } {

        this->circle.setPosition(this->position);
        this->circle.setRadius(this->radius);
    }


    bool Circle::isCollided(const Object& otherObject) {
        // logic
        return false;
    }

    //Circle end
}
