#include "PhysicsEngine.h"


int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Kriss", sf::Style::Close);
	window->setFramerateLimit(240);
	//PhysicsEngine::Rectangle rect
	sf::Clock clock, spawnClock;
	float deltaTime;
	float spawnTime = 1;
	std::vector <PhysicsEngine::Rectangle*>rectCollection;
	
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window->close();
		}
		deltaTime = clock.restart().asSeconds();
		sf::Vector2f mousepos = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		if (spawnTime == 1)
			spawnTime = spawnClock.restart().asSeconds();
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			
			PhysicsEngine::Rectangle* rect = new PhysicsEngine::Rectangle(mousepos, 50, 50, true);
			rectCollection.push_back(rect);
		}
		std::cout << mousepos.x <<", " << mousepos.y << std::endl;
		window->clear(sf::Color::Black);
		for (auto* rect : rectCollection) {
			rect->draw(window);
			rect->update(deltaTime);
		}
		window->display();
	}
}