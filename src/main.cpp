#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(CustomPauseLayer, PauseLayer)
{
	void customSetup()
	{
		PauseLayer::customSetup();

		auto winSize = CCDirector::sharedDirector()->getWinSize();
		auto GM = GameManager::sharedState();

		if (GM->getGameVariable("0146"))
		{
			auto checkpointsLabel = CCSprite::create("DCE_Text.png"_spr);
			checkpointsLabel->setPosition({winSize.width / 2 + 224.f, winSize.height / 2 + 100.f});
			checkpointsLabel->setID("disabled-checkpoints-label");

			this->addChild(checkpointsLabel);
		}
	}
};

class $modify(CustomPlayLayer, PlayLayer)
{
	bool init(GJGameLevel *level, bool useReplay, bool dontCreateObjects)
	{
		if (!PlayLayer::init(level, useReplay, dontCreateObjects))
			return false;

		if (!level->isPlatformer() || !Mod::get()->getSettingValue<bool>("show-icon"))
			return true;

		auto winSize = CCDirector::sharedDirector()->getWinSize();
		auto GM = GameManager::sharedState();

		if (GM->getGameVariable("0146"))
		{
			auto checkpointsIcon = CCSprite::create("DCE_Icon.png"_spr);
			checkpointsIcon->setPosition({winSize.width / 2, 20.0f});
			checkpointsIcon->setOpacity(125);
			checkpointsIcon->setScale(0.75f);
			checkpointsIcon->setID("disabled-checkpoints-icon");
			this->addChild(checkpointsIcon);
		}

		return true;
	}

	void resetLevel(){
		PlayLayer::resetLevel();

		auto GM = GameManager::sharedState();
		auto icon = this->getChildByID("disabled-checkpoints-icon");

		if(icon){
			icon->setVisible(GM->getGameVariable("0146"));
		}
	}
};