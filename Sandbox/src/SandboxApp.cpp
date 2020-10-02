
#include <GE777.h>

class Sandbox : public GE777::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

GE777::Application* GE777::CreateApplication()
{
	return new Sandbox();
}



