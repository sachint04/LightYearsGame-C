#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
namespace ly
{
	Actor::Actor(World* owningWorld, const std::string& texturePath)
		: m_owningWorld{ owningWorld, },
		m_HasBeganPlay{ false },
		m_texture{},
		m_sprite{}
	{
		SetTexture(texturePath);
	}

	void Actor::BeginPlayInternal() {
		if (!m_HasBeganPlay) {
			m_HasBeganPlay = true;
			BeginPlay();
		}
	}

	void Actor::BeginPlay() {
		LOG("Actor begin play");
	}

	void Actor::TickInternal(float deltaTime) {
		if (!IsPendingDestroy()) {
			Tick(deltaTime);
		}
	}

	void Actor::Tick(float deltaTime) {
		LOG("Actor Ticking");
	}

	void Actor::SetTexture(const std::string& texturePath)
	{

		m_texture = AssetManager::Get().LoadTexture(texturePath);
		if (!m_texture)return;

		m_sprite.setTexture(*m_texture);
		int textureWidth = m_texture->getSize().x;
		int textureHeight = m_texture->getSize().y;
		m_sprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{textureWidth,textureHeight } });
		m_sprite.setPosition(sf::Vector2f{ 50.f, 50.f });
		
	}

	void Actor::Render(sf::RenderWindow& window)
	{
		if (IsPendingDestroy())return;

		window.draw(m_sprite);
	}

	Actor::~Actor() {
		LOG("Actor Destroyed");
	}
	
}