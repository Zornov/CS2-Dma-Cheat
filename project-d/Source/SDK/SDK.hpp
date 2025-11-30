#pragma once
#include <Overlay/Overlay.hpp>
#include <thread>
#include <cs2/offsets.hpp>
#include <cs2/client_dll.hpp>
#include <Objects/C_PlantedC4.hpp>
#include <Objects/C_C4.hpp>

class SDK {
public:

	std::unique_ptr<C_PlantedC4> planted_C4;
	std::unique_ptr<C_C4> c4;

	bool Init();

	static SDK& Get() {
		static SDK instance;
		return instance;
	}

	void Update() {
		std::thread([&]() {
			while (Globals::Running) {
				if (c4)
					c4->Update();

				if (planted_C4)
					planted_C4->Update();

				std::this_thread::sleep_for(std::chrono::milliseconds(5));
			}
			}
		).detach();
	}

	bool WorldToScreen(const Vector3& WorldPos, Vector2& ScreenPos, const Matrix& Matrix = Globals::ViewMatrix);
};

inline SDK& sdk = SDK::Get();