#pragma once
#include<map>
#include "framework/Core.h"
#include <SFML/Graphics.hpp>


namespace ly
{
	class AssetManager
	{
	public:
		static AssetManager& Get();
		shared<sf::Texture> LoadTexture(const std::string& path);

	protected:
		AssetManager();

	private:
		static unique<AssetManager> assetManager;
		std::map<std::string, shared<sf::Texture>> m_loadedTextureMap;
	};
}