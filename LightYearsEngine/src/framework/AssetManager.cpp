#include "framework/AssetManager.h"

namespace ly {
	unique<AssetManager> AssetManager::assetManager{ nullptr };

	AssetManager& AssetManager::Get() 
	{
		if (!assetManager) {
			assetManager = unique<AssetManager> {new AssetManager};
		}
		return *assetManager;
	}

	AssetManager::AssetManager()
	{

	}

	shared<sf::Texture> AssetManager::LoadTexture(const std::string& path) {				
		auto found = m_loadedTextureMap.find(path);
		if (found != m_loadedTextureMap.end()) {
			return found->second;
		}
		
		shared<sf::Texture> newTexure{ new sf::Texture };
		
		if (newTexure->loadFromFile(path)) {
			m_loadedTextureMap.insert({path, newTexure});
			return newTexure;
		}
		
		return shared<sf::Texture>{nullptr};
	}
}