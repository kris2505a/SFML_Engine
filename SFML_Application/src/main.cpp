#include "PhysicsEngine.h"


int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Kriss", sf::Style::Close | sf::Style::Fullscreen);
	window->setFramerateLimit(240);
	//PhysicsEngine::Rectangle rect
	sf::Clock clock, spawnClock;
	float deltaTime;
	std::vector <PhysicsEngine::Object*>objCollection;
	sf::RectangleShape base(sf::Vector2f(1900, 50));
	base.setPosition(10, 1030);
	base.setFillColor(sf::Color::Cyan);
	
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window->close();
		}

		
		deltaTime = clock.restart().asSeconds();
		sf::Vector2f mousepos = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && (spawnClock.getElapsedTime().asSeconds() >= 0.25)) {
			
			objCollection.push_back(new PhysicsEngine::Rectangle(mousepos, 50, 50, true));
			spawnClock.restart();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && (spawnClock.getElapsedTime().asSeconds() >= 0.25)) {

			objCollection.push_back(new PhysicsEngine::Circle(mousepos, 25, true));
			spawnClock.restart();
		}
		window->clear(sf::Color::Black);
		window->draw(base);
		for (auto* obj : objCollection) {
			obj->draw(window);
			obj->update(deltaTime);
		}
		window->display();
	}
}