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
	sf::ConvexShape m_shape;
	//днаюбхрэ люяяхб рнвей рпесцнкэмхйю - рпюейрнпхх


	double N_radius = 80;
	double N_corner = 0;
	double N_N = 800;
	double N_M = 800;
public:
	Triangle(sf::Vector2f StartingPoint) : Point(StartingPoint.x, StartingPoint.y)
	{
		m_shape.SetPointCount(3);
		m_shape[0] = sf::Vector2f(/*рбнх йннпдхмюрш нрмняхрекэмн StartingPoint*/);
		m_shape[1] = sf::Vector2f(/*рбнх йннпдхмюрш нрмняхрекэмн StartingPoint*/);
		m_shape[2] = sf::Vector2f(/*рбнх йннпдхмюрш нрмняхрекэмн StartingPoint*/);

		//янярюбхрэ бяе рнвйх рпесцнкэмхйю_рпюейрнпхх мю нямнбе хгбеярмшу рнвей рпесцнкэмхйю!
	}


	Triangle(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C)
	{
		m_shape.SetPointCount(3);
		m_shape[0] = A;
		m_shape[1] = B;
		m_shape[2] = C;
		//янярюбхрэ бяе рнвйх рпесцнкэмхйю_рпюейрнпхх мю нямнбе хгбеярмшу рнвей рпесцнкэмхйю!
	}
	void draw(sf::RenderWindow N_window)
	{
		N_window.draw(m_shape);
	}

	void move(sf::Vector2f Step)
	{
		N_Ox += Step.x;
		N_Oy += Step.y;
		m_shape.SetPosition(m_shape.GetPosition() + sf::Vector2f(N_Ox, N_Oy));
	}

private:
	void refresh()
	{

	}
};
int main() {
	sf::RenderWindow N_window(900, 900);
	sf::Vector2f POINTS[] = {
		sf::Vector2f(),
		sf::Vector2f(),
		sf::vector2f()
	};
	Triangle NewTriangle(POINTS[0], POINTS[1], POINTS[2]);
	Triangle NewTriangle2(POINTS[0]);

	while (N_window.is_open())
	{
		NewTriangle2.move(sf::Vector2f(1, 1));//ядбхцюрэ ме мю 1,1!!! Ю МЮ ПЮГМНЯРЭ ПЮДХСЯ БЕЙРНПЮ ДН ЯКЕДСЧЫЕИ РНВЙХ (РПЕСЦНКЭМХЙЮ-РПЮЕЙРНПХХ) Х РЕЙСЫЕЦН ОНКНФЕМХЪ РПЕСЦНКЭМХЙЮ
		N_window.clear();
		NewTriangle2.draw(N_window);
		N_window.display();
	}

}