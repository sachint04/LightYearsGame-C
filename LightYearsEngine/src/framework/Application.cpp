#include "framework/Application.h"
#include "framework/Core.h"
#include "framework/World.h"
namespace ly
{

	Application::Application(unsigned int _winWidth, unsigned int _winHeight, const std::string& title, sf::Uint32 style)
		:m_Window{ sf::VideoMode(_winWidth, _winHeight), title, style} ,
		m_targetFrameRate{60.f},
		m_ticktok{},
		currentWorld{nullptr}		
	{
	}

	void Application::Run()
	{
		float acumulatedTime = 0.f;
		float targetDeltaTime = 1.f / m_targetFrameRate;
		int counter = 0;
		while (m_Window.isOpen())
		{
			sf::Event windowEvent;
			while (m_Window.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					m_Window.close();
				}
			}
			float deltaFrameTime = m_ticktok.restart().asSeconds();
			acumulatedTime += deltaFrameTime;
			while (acumulatedTime > targetDeltaTime)
			{
				acumulatedTime -= targetDeltaTime;
				++counter;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}

			//LOG("ticking at framerate %f", 1.f / deltaFrameTime);
		}
	}

	void Application::TickInternal(float deltaTime) {
		if (currentWorld) {
			currentWorld->BeginPlayInternal();
			currentWorld->TickInternal(deltaTime);
		}
		Tick(deltaTime);
	}

	void Application::RenderInternal() {
		m_Window.clear( sf::Color::White );
		
		Render();

		m_Window.display();

	}

	void Application::Tick(float deltaTime) {

	}



	void Application::Render() {
	/*	sf::CircleShape circle{ 50 };
		circle.setFillColor({ sf::Color::Blue });
		circle.setOrigin(50, 50);
		circle.setPosition(m_Window.getSize().x / 2, m_Window.getSize().y / 2);
		m_Window.draw(circle);*/

		if (currentWorld) {
			currentWorld->Render(m_Window);
		}
	}
}