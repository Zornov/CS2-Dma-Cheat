#include <SDK.hpp>

#include <ESP/ESP.hpp>
#include <Aimbot/Aimbot.hpp>
#include <Aimbot/TriggerBot.hpp>

class Features {

public:
	void Update() {
		aimbot->Update();
		triggerBot->Update();

		esp->Update();
	}

	void Render(ImDrawList* drawList) {
		aimbot->Render(drawList);
		triggerBot->Render(drawList);
		
		esp->Render(drawList);
	}

	bool Init() {
		return true;
	}
};

inline std::unique_ptr<Features> features = std::make_unique<Features>();
