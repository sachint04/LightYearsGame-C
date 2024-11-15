#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "framework/Core.h"



namespace ly
{
	GameApplication::GameApplication()
		:Application{300, 600, "C++ Light Years", sf::Style::Titlebar | sf::Style::Close}
	{

		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		m_actorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		m_actorToDestroy.lock()->SetTexture(GetResourceDir() +"SpaceShooterRedux/PNG/playerShip1_blue.png");
		counter = 0;

	}
	void GameApplication::Tick(float deltaTime)
	{
		counter += deltaTime;
		if (counter > 2.f)
		{
			if (!m_actorToDestroy.expired()) {
				m_actorToDestroy.lock()->Destroy();
			}
		}
	}
}

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

