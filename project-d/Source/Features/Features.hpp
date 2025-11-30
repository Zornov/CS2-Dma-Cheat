#include <SDK.hpp>

#include <ESP/ESP.hpp>
#include <Aimbot/Aimbot.hpp>
#include <Aimbot/TrigerBot.hpp>

class Features {

public:
	void Update() {
		aimbot->Update();
		triger->Update();

		esp->Update();
	}

	void Render(ImDrawList* drawList) {
		aimbot->Render(drawList);
		triger->Render(drawList);
		esp->Render(drawList);

	}

	bool Init() {

		return true;
	}

	static Features& Get() {
		static Features instance;
		return instance;
	}
};

inline std::unique_ptr<Features> features = std::make_unique<Features>();