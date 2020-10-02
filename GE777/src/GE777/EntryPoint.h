#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GE777::Application* GE777::CreateApplication();

int main(int argc, char** argv)
{
	GE777::Log::Init();
	GE_CORE_WARN("Initialized Logger");
	int a = 420;
	GE_INFO("Welcome, var = {0}", a);


	//printf("Entry point...");
	auto app = GE777::CreateApplication();
	app->Run();
	delete app;

}

#endif


