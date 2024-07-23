#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(CustomPauseLayer, PauseLayer) {
	void customSetup() {
		PauseLayer::customSetup();

		auto winSize = CCDirector::sharedDirector()->getWinSize();
		auto GM = GameManager::sharedState();

		//	log::debug("Disable Checkpoints: {}", GM->getGameVariable("0146"));

		if(GM->getGameVariable("0146")){
			auto checkpointsLabel = CCSprite::create("checkpointsText.png"_spr);
			checkpointsLabel->setPosition({winSize.width / 2 + 224.f, winSize.height / 2 + 100.f});
			checkpointsLabel->setID("disabled-checkpoints-label");

			this->addChild(checkpointsLabel);
		}
	}
};
