#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Perlin Noise Generation");

	sf::Image image;
	image.create(WINDOW_WIDTH, WINDOW_HEIGHT, sf::Color());

	for (int i = 0; i < image.getSize().x; i++) {
		for (int j = 0; j < image.getSize().y; j++) {
			image.setPixel(i, j, sf::Color(i % 255, j % 255, 0, 255));
		}
	}

	sf::Texture texture;
	texture.loadFromImage(image);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}