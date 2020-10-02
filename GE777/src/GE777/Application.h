#pragma once
#include "Core.h"


namespace GE777 
{
	class GE_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined
	Application* CreateApplication();


}


