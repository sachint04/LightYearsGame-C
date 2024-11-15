#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
namespace ly
{
	class World;
	class Application
	{
	public:
		Application(unsigned int _winWidth, unsigned int _winHeight, const std::string& title, sf::Uint32 style);
		void Run();


		template<typename WorldType>
		weak<WorldType> LoadWorld();


	

	private:
		void TickInternal(float deltaTime);
		void RenderInternal();
		virtual void Render();
		virtual void Tick(float deltaTime);

		sf::RenderWindow m_Window;
		float m_targetFrameRate;
		sf::Clock m_ticktok;

		shared<World> currentWorld;
	};
	

	template<typename WorldType>
	weak<WorldType> Application::LoadWorld()
	{
		shared <WorldType> newWorld{ new WorldType{this} };
		currentWorld = newWorld;
		currentWorld->BeginPlayInternal();
		return newWorld;
	}
}