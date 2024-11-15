#include "EntryPoint.h"
#include "framework/Application.h"


int main()
{
	// allowcating on the heap
	ly::Application* app = GetApplication();
	app->Run();
	delete app;
}