#include "Headers/physicsEngine.h"

namespace PhysicsEngine {

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


    void Rectangle::draw(sf::RenderWindow* window) {
        window->draw(this->rectangle);
    }

   
    Circle::Circle(sf::Vector2f pos, float rad) 
        : Object{ pos }, radius{ rad } {
    
        this->circle.setPosition(this->position);
        this->circle.setRadius(this->radius);
    }


    bool Circle::isCollided(const Object& otherObject) {
        // logic
        return false;
    }
}
