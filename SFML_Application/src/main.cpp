#include "PhysicsEngine.h"


int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Kriss", sf::Style::Close);
	PhysicsEngine::Rectangle rect(sf::Vector2f(400, 300), 150, 100);
	
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window->close();
		}
		window->clear(sf::Color::Black);
		rect.draw(window);
		window->display();
	}
}