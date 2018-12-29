#include <SFML/Graphics.hpp>

#include "PerlinNoise.hpp"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Perlin Noise Generation");

	sf::Image image;
	image.create(WINDOW_WIDTH, WINDOW_HEIGHT, sf::Color());

	siv::PerlinNoise noise(12345);

	double freq = 8;
	int octaves = 1;

	double fx = image.getSize().x / freq;
	double fy = image.getSize().y / freq;


	for (double i = 0; i < image.getSize().x; i++) {
		for (double j = 0; j < image.getSize().y; j++) {
			//double val = noise.noise(i, j) * 255;
			double val = noise.octaveNoise0_1(i / fx, j / fy, octaves) * 255;
			image.setPixel(i, j, sf::Color(val, val, val, 255));
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