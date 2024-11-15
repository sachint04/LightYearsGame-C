#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"
namespace ly
{
	class Actor;
	class Application;
	class World
	{
	public:
		World(Application* owningApp);

		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		
		virtual ~World();

		template<typename ActorType>
		weak<ActorType> SpawnActor();
		void Render(sf::RenderWindow& window);

	private:
		void BeginPlay();
		void Tick(float deltaTime);
		Application* m_owningApp;
		bool m_BeginPlay;

		List<shared<Actor>> m_Actors;

		List<shared<Actor>> m_pendingActors;
	};


	template<typename ActorType>
	weak<ActorType> World::SpawnActor()
	{
		shared<ActorType> newActor{ new ActorType{this} };
		m_pendingActors.push_back(newActor);
		return newActor;
	}
}
