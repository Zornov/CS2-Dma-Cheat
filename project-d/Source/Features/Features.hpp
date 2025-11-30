#include <SDK.hpp>

#include <ESP/ESP.hpp>
#include <Aimbot/Aimbot.hpp>

class Features {

public:
	void Update(ImDrawList* drawList) {
		esp.Update(drawList);
		aimbot.Update(drawList);
	}

	bool Init() {

		return true;
	}

	static Features& Get() {
		static Features instance;
		return instance;
	}
};

inline Features& features = Features::Get();