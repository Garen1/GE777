#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GE777::Application* GE777::CreateApplication();

int main(int argc, char** argv)
{
	//printf("Entry point...");
	auto app = GE777::CreateApplication();
	app->Run();
	delete app;

}

#endif
