#include "Hazel.h"


class MyLayer : public Hazel::Layer
{
public:
	MyLayer(std::string name)
		:Layer(name)
	{

	}

	void OnUpdate() override
	{
		HZ_INFO("ExampleLayer{0}::Update", m_DebugName);
	}

	void OnEvent(Hazel::Event& e) {
		HZ_INFO("{0}", e.ToString());
	}
};

class Sandbox : public Hazel::Application
{
public:
	Sandbox() {
		MyLayer* layer = new MyLayer("1");
		PushLayer(layer);
		PushOverlay(new MyLayer("5"));
		PushOverlay(new MyLayer("6"));
		//PushOverlay(new Hazel::ImGuiLayer());
		PushLayer(new MyLayer("2"));
		PushLayer(new MyLayer("3"));

		PopLayer(layer);
		PushLayer(new MyLayer("4"));

	}
	~Sandbox() {

	}
private:

};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}