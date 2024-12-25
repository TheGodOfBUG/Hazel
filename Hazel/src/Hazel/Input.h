#pragma once

#include "Hazel/Core.h"
namespace Hazel {

	class HAZEL_API Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instnce->IsKeyPressedImpl(keycode); };
		inline static bool IsKeyMouseButtonPressed(int button) {
			return s_Instnce->IsKeyMouseButtonPressedImpl(button);
		};
		inline static float GetMouseX() {
			return s_Instnce->GetMouseXImpl();
		};
		inline static float GetMouseY() {
			return s_Instnce->GetMouseYImpl();
		};
		inline static std::pair<float, float> GetMousePosition() {
			return s_Instnce->GetMousePositionImpl();
		};
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsKeyMouseButtonPressedImpl(int button) = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
	private:
		static Input* s_Instnce;
	};
}