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
	int waterLevel = 100;

	double fx = image.getSize().x / freq;
	double fy = image.getSize().y / freq;


	for (double i = 0; i < image.getSize().x; i++) {
		for (double j = 0; j < image.getSize().y; j++) {

			double val = noise.octaveNoise0_1(i / fx, j / fy, octaves);
			image.setPixel(i, j, sf::Color(val * 60, val * 255, val * 0, 255));

			if (val * 255 < waterLevel) {
				image.setPixel(i, j, sf::Color(val * 0, val * 255, val * 240, 255));
			}
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