#include <SFML/Graphics.hpp>
#include <iostream>

class Point {
public:
	double N_Ox;
	double N_Oy;
	Point() {
		N_Ox = 0;
		N_Oy = 0;
	}
	Point(double Ox, double Oy) {
		N_Ox = Ox;
		N_Oy = Oy;
	}
};

class Triangle : public Point {
private: 
	sf::Event N_event;
	sf::RenderWindow N_window;
	double N_radius = 80;
	double N_corner = 0;
	double N_N = 800;
	double N_M = 800;
public:
	Triangle() : Point(400, 400) {}
	void draw() {
		N_window.create(sf::VideoMode(N_N, N_M), "TRIANGLE");
		sf::VertexArray N_Triangle(sf::TriangleFan, 5);
		N_Triangle[0].position = sf::Vector2f(N_Ox, N_Oy);
		N_Triangle[0].color = sf::Color(255, 192, 255);
		for (int i = 0; i < 4; i++) {
			N_Triangle[i + 1].position = sf::Vector2f(N_Ox + N_radius * cos(((30 + 120 * i) * 3.14) / 180), N_Oy + N_radius * sin(((30 + 120 * i) * 3.14) / 180));
			N_Triangle[i + 1].color = sf::Color(255, 192, 255);
		}
		while (N_window.isOpen()) {
			while (N_window.pollEvent(N_event)) {
				if (N_event.type == sf::Event::Closed)
					N_window.close();
			}
			N_Triangle[0].position = sf::Vector2f(N_Ox, N_Oy);
			N_Triangle[0].color = sf::Color(255, 192, 255);
			for (int i = 0; i < 4; i++) {
				N_Triangle[i + 1].position = sf::Vector2f(N_Ox + N_radius * cos(((30 + 120 * i) * 3.14) / 180), N_Oy + N_radius * sin(((30 + 120 * i) * 3.14 / 180)));
				N_Triangle[i + 1].color = sf::Color(255, 192, 255);
			}
			N_Ox = N_Ox - 10;
			N_Oy = N_Oy - 10;
			N_corner = N_corner + 0.1;
			N_window.clear(sf::Color(0, 255, 255));
			N_window.draw(N_Triangle);
			N_window.display();

		}
	}
};
int main() {
	Triangle Triangle;
	Triangle.draw();
}