#include "stdafx.h"

std::mt19937 World::rand;

void World::InitializeRandomGenerator()
{
	std::random_device rd;
	rand = std::mt19937(rd());
}

int World::RandomInt()
{
	return RandomInt(0, 100);
}

int World::RandomInt(const int min, const int max)
{
	std::uniform_int_distribution<int> dist(min, max);
	return dist(rand);
}

Float World::RandomFloat()
{
	return RandomFloat(0.0, 1.0);
}

Float World::RandomFloat(Float min, Float max)
{
	std::uniform_real_distribution<Float> dist(min, max);
	return dist(rand);
}

World::World()
	: View(),
	BackgroundColour(Colours::Black),
	Tracer(),
	camera(nullptr),
	ambientLight(new AmbientLight)

{
	renderWindow = nullptr;
}

void World::SetCamera(ICamera* newCamera)
{
	if (camera)
	{
		delete camera;
		camera = nullptr;
	}

	camera = newCamera;
}

void World::SetAmbientLight(ILight* ambient)
{
	if (ambientLight)
	{
		delete ambientLight;
		ambientLight = nullptr;
	}

	ambientLight = ambient;
}

void World::Build()
{
	InitializeRandomGenerator();

	//BuildFunctions::RedSphere(*this);
	BuildFunctions::TwoSpheres(*this);
	//BuildFunctions::Perspective(*this);
	//BuildFunctions::TestTriangle(*this);


	if (!camera)
	{
		throw new std::exception("Camera was not defined by the build function.");
	}
}

void World::RenderScene()
{
	std::cout << "Generating samples...\t";
	View.GetSampler()->InitializeSampler();
	std::cout << "Done!" << std::endl;

	renderWindow = new RenderWindow(View.GetHorizontalResolution(), View.GetVerticalResolution());
	tracingThread = std::thread(&World::RayTraceScene, this);

	// The main thread will stay in this function until the window is closed.
	OpenWindow();

	// Make sure the tracing thread gets joined before we quit.
	if (tracingThread.joinable())
	{
		tracingThread.join();
	}



}

void World::RayTraceScene() const
{
	bool windowReady = false;
	while (!windowReady)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		windowReady = RenderWindow::Current->IsWindowRunning();
	}

	auto start = std::chrono::high_resolution_clock::now();


	std::cout << "Beginning render..." << std::endl;
	std::cout << "Rendring " << this->GetWorldObjectCount() << " objects and " << this->GetLightCount() << " lights." << std::endl;
	std::cout << "Render resolution: " << View.GetHorizontalResolution() << "x" << View.GetVerticalResolution() << "." << std::endl;
	

	camera->RenderScene(*this);

	auto end = std::chrono::high_resolution_clock::now();
	auto runTime = end - start;

	auto runTimeMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(runTime);

	Float averageRunTime = (Float)(runTimeMilliseconds.count()) / (View.GetHorizontalResolution() * View.GetVerticalResolution());


	std::cout << std::endl << "-------------------------------------------" << std::endl;
	std::cout << "Render Complete!" << std::endl;
	std::cout << "Total runtime: " << (Float)runTimeMilliseconds.count() / 1000.0 << " seconds." << std::endl;
	std::cout << "Average time per pixel: " << averageRunTime << " milliseconds.";
	std::cout << std::endl << "-------------------------------------------" << std::endl;

}

void World::OpenWindow() const
{
	int result = renderWindow->OpenWindow();

	if (result < 0)
	{
		std::cout << "Unable to open render window.\r\n";
		throw "Unable to open render window.";
	}
}

void World::DisplayPixel(const int x, const int y, const RGBColour& colour) const
{
	renderWindow->SetPixel(x, y, View.GetScreenColour(colour));
	Redraw();
}

TraceResult World::HitObjects(const Ray& ray)
{
	Float tMin;

	return HitObjects(ray, tMin);
}

TraceResult World::HitObjects(const Ray & ray, Float& tMin)
{
	TraceResult tr = TraceResult(*this);

	Float t;
	tMin = std::numeric_limits<Float>::max();
	Vector3 normal;
	Vector3 localHitPoint;

	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->Hit(ray, t, tr) && t < tMin)
		{
			tr.HitDetected = true;
			tMin = t;
			tr.Material = objects[i]->GetMaterial();
			tr.HitPoint = ray.Origin + (t * ray.Direction);
			normal = tr.Normal;
			localHitPoint = tr.LocalHitPoint;
		}
	}

	if (tr.HitDetected)
	{
		tr.Normal = normal;
		tr.LocalHitPoint = localHitPoint;
	}

	return tr;
}

World::~World()
{
	if (Tracer)
	{
		delete Tracer;
		Tracer = nullptr;
	}

	if (renderWindow)
	{
		delete renderWindow;
		renderWindow = nullptr;
	}

	if (camera)
	{
		delete camera;
		camera = nullptr;
	}

	if (ambientLight)
	{
		delete ambientLight;
		ambientLight = nullptr;
	}

	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (objects[i])
		{
			delete objects[i];
			objects[i] = nullptr;
		}
	}
	objects.clear();

	for (unsigned int i = 0; i < lights.size(); i++)
	{
		if (lights[i])
		{
			delete lights[i];
			lights[i] = nullptr;
		}
	}
	lights.clear();

}

