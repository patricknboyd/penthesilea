#pragma once
#include "stdafx.h"

class World
{
public:

	static Float RandomFloat();
	static Float RandomFloat(const Float min, const Float max);

	static int RandomInt();
	static int RandomInt(const int min, const int max);

	ViewPlane View;
	RGBColour BackgroundColour;
	ITracer* Tracer;

	World();
	World(const World&) = delete;
	~World();

	World& operator= (const World&) = delete;

	void Build();
	void RenderScene();
	void OpenWindow() const;
	// I've switched the order of x and y in this from the book!
	void DisplayPixel(const int x, const int y, const RGBColour& colour) const;
	inline void AddWorldObject(GeometricObject* object) { objects.push_back(object); }
	inline int GetWorldObjectCount() const { return objects.size(); }
	inline GeometricObject* GetWorldObject(int index) const { return objects[index]; }
	inline void AddLight(ILight* light) { lights.push_back(light); }

	TraceResult HitObjects(const Ray& ray);
	TraceResult HitObjects(const Ray& ray, Float& tMin);

	inline void Redraw() const { renderWindow->Redraw(); }

	void SetCamera(ICamera* newCamera);
	void SetAmbientLight(ILight* ambient);
	ILight* GetAmbientLight() const { return ambientLight; }

	unsigned int GetLightCount() const { return lights.size(); }
	ILight* GetLight(int index) const { return lights[index]; }


private:

	static std::mt19937 rand;
	static void InitializeRandomGenerator();


	RenderWindow* renderWindow;
	ICamera* camera;
	ILight* ambientLight;

	std::vector<GeometricObject*> objects;
	std::vector<ILight*> lights;

	void RayTraceScene() const;

	std::thread tracingThread;
};
