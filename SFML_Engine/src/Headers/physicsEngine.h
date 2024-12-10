#include "core.h"
#include "SFML/Graphics.hpp"


namespace PhysicsEngine {
	
	class PH_ENG_API Object {
	
	protected:
		sf::Vector2f position;
	
	public:
		virtual ~Object() = default;
		virtual bool isCollided(const Object& otherObject) = 0;
		inline Object(sf::Vector2f pos) : position{ pos } {}
	};

	
	class PH_ENG_API Rectangle : public Object {
	
	private:
		float width, height;
		sf::RectangleShape rectangle;
	
	public:
		Rectangle(sf::Vector2f pos, float w, float h);
		virtual bool isCollided(const Object& otherObject) override;
		void draw(sf::RenderWindow* window);
	};


	class PH_ENG_API Circle : public Object {
		
	private:
		float radius;
		sf::CircleShape circle;
	public:
		Circle(sf::Vector2f pos, float rad);
		virtual bool isCollided(const Object& otherObject) override;
	};
}

