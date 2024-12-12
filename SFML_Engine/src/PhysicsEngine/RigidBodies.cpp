#include "Headers/RigidBodies.h"

namespace PhysicsEngine {

    //Rectangle Start

    Rectangle::Rectangle(sf::Vector2f pos, float w, float h, bool hasGravity)
        : Object{ pos }, width{ w }, height{ h } {
        
        this->rectangle.setPosition(this->position);
        this->rectangle.setSize(sf::Vector2f(this->width, this->height));
        this->rectangle.setFillColor(sf::Color::White);
        this->gravity = hasGravity;

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
        if (this->gravity)
            this->position.y = this->position.y + this->gravityConst * deltaTime;
        this->position.y += this->velocity.y * deltaTime;        
        this->updatePosition();

        if (this->position.y >= 1080)
            this->gravity = false;
    }

    void Rectangle::updatePosition() {
        this->rectangle.setPosition(this->position);
    }
    //Rectangle end
}



namespace PhysicsEngine {

    //Circle start

    Circle::Circle(sf::Vector2f pos, float rad, bool hasGravity)
        : Object{ pos }, radius{ rad } {

        this->circle.setPosition(this->position);
        this->circle.setRadius(this->radius);
        this->gravity = hasGravity;
    }


    bool Circle::isCollided(const Object& otherObject) {
        // logic
        return false;
    }

    void Circle::draw(sf::RenderWindow* window) {
        window->draw(this->circle);
    }

    void Circle::update(float deltaTime) {
        if (this->gravity)
            this->position.y = this->position.y + this->gravityConst * deltaTime;
        this->position.y += this->velocity.y * deltaTime;
        this->updatePosition();

        if (this->position.y >= 1080)
            this->gravity = false;
    }

    void Circle::updatePosition() {
        this->circle.setPosition(this->position);
    }

    float Circle::getArea() {
        return PI * this->radius * this->radius;
    }

    //Circle end
}
