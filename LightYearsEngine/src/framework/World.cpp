#include "framework//World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace ly {

	World::World(Application* owningApp)
		:m_owningApp{ owningApp },
		m_BeginPlay{false},
		m_Actors{},
		m_pendingActors{}

	{
		
	}

	void World::BeginPlayInternal() {
		if (!m_BeginPlay) {
			m_BeginPlay = true;
			BeginPlay();
		}
	}

	void World::TickInternal(float deltaTime)
	{
		for (shared<Actor> actor : m_pendingActors)
		{
			m_Actors.push_back(actor);
			actor->BeginPlayInternal();
		}

		m_pendingActors.clear();

		for (auto iter = m_Actors.begin(); iter != m_Actors.end();)
		{
			if (iter->get()->IsPendingDestroy())
			{
				iter = m_Actors.erase(iter);
			}
			else 
			{
				iter->get()->TickInternal(deltaTime);
				++iter;
			}

		}


		Tick(deltaTime);
	}


	void World::BeginPlay()
	{
		LOG("began Play");

	}

	void World::Tick(float deltaTime)
	{
		LOG("Tick at frame rate %f\n", 1.f / deltaTime);

	}

	void World::Render(sf::RenderWindow& window) {
		for (auto& actor : m_Actors) {
			actor->Render(window);
		}
	}

	World::~World() {
	}
}