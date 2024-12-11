#pragma once
#include "core.h"
#include "SFML/Graphics.hpp"


namespace PhysicsEngine {
	
	class PH_ENG_API Object {
	
	protected:

		//Attributes:
		sf::Vector2f position;
		bool physics { false };
		sf::Color color;

		//Physics
		float mass { 0.0f };
		float inertia{ 0.0f };
		float coeffOfFriction { 0.0f };
		float coeffOfRestitution { 0.0f };
		float gravityConst { 981.0f };
		sf::Vector2f velocity{ 0, 0 };
		bool gravity { false };
		
		//private Functions
		virtual void updatePosition() = 0;

	public:
		
		//Constructors and Destructors		
		virtual ~Object() = default;
		inline Object(sf::Vector2f pos) : position{ pos } {}

		//Get Attributes		
		virtual float getArea() = 0;
		inline sf::Vector2f getPosition() { return this->position; }
		inline sf::Color getColor() { return this->color; }
		inline bool physicsStatus() { return this->physics; }
		inline bool gravityStatus() { return this->gravity; }
		
		//Set Atrributes
		inline void setPhysics(bool toStatus) { this->physics = toStatus; }
		inline void setGravity(bool toStatus) { this->gravity = toStatus; }
		inline void setMass(float targetMass) { this->mass = targetMass; }


		//Collision
		virtual bool isCollided(const Object&) = 0;

		//render and update functions
		virtual void draw(sf::RenderWindow*) = 0;
		virtual void update(float) = 0;
	};


/*----------------------------------------------------------------------------------------------------------------------------*/


	class PH_ENG_API Rectangle : public Object {
	
	private:
		float width, height;
		sf::RectangleShape rectangle;

		virtual void updatePosition() override;
	
	public:
		Rectangle(sf::Vector2f, float, float, bool);
		virtual bool isCollided(const Object&) override;
		virtual float getArea() override;
		virtual void draw(sf::RenderWindow*) override;
		virtual void update(float) override;
	};


/*----------------------------------------------------------------------------------------------------------------------------*/

	
	class PH_ENG_API Circle : public Object {
		
	private:
		float radius;
		sf::CircleShape circle;
	public:
		Circle(sf::Vector2f pos, float rad);
		virtual bool isCollided(const Object& otherObject) override;
	};
}

