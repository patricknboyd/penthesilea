#include "stdafx.h"

void BuildFunctions::RedSphere(World& world)
{
	int width = 300;
	int height = 300;

	world.View.SetHorizontalResolution(width);
	world.View.SetVerticalResolution(height);
	world.View.SetPixelSize(1.0);
	world.View.SetGamma(1.0);
	world.View.SetSampleCount(16);

	world.BackgroundColour = Colours::Black;
	world.Tracer = new MultipleObjects(&world);

	Sphere* s = new Sphere(Vector3(0.0, 0.0, 0.0), 85.0);
	s->SetColour(Colours::Red);

	world.AddWorldObject(s);
}

void BuildFunctions::TwoSpheres(World & world)
{
	world.View.SetHorizontalResolution(400);
	world.View.SetVerticalResolution(400);
	world.View.SetPixelSize(1.0);
	world.View.SetGamma(1.0);
	world.View.SetSampleCount(16);

	world.BackgroundColour = Colours::Black;
	world.Tracer = new RayCastTracer(&world);

	ICamera* camera = new PinholeCamera(
		Vector3(0, 0, 500),
		Vector3(-5, 0, 0),
		Vector3::Up,
		850);
	world.SetCamera(camera);	

	AmbientLight* ambient = new AmbientLight();
	ambient->SetIntensity(1.0);
	world.SetAmbientLight(ambient);

	PointLight* pointLight = new PointLight();
	pointLight->SetPosition(100, 50, 150);
	pointLight->SetIntensity(3.0);
	world.AddLight(pointLight);

	PhongMaterial* phongOne = new PhongMaterial();
	phongOne->SetAmbientIntensity(0.25);
	phongOne->SetDiffuseIntensity(0.65);
	phongOne->SetSpecularIntensity(0.25);
	phongOne->SetColour(1, 1, 0);
	Sphere* sphereOne = new Sphere(Vector3(10,-5,0), 27);
	sphereOne->SetMaterial(phongOne);
	world.AddWorldObject(sphereOne);

	PhongMaterial* phongTwo = new PhongMaterial();
	phongTwo->SetAmbientIntensity(0.15);
	phongTwo->SetDiffuseIntensity(0.85);
	phongOne->SetSpecularIntensity(0.25);
	phongTwo->SetColour(0.71, 0.40, 0.16);   		// brown
	Sphere*	sphere_ptr2 = new Sphere(Vector3(-25, 10, -35), 27);
	sphere_ptr2->SetMaterial(phongTwo);
	world.AddWorldObject(sphere_ptr2);

	PhongMaterial* phongThree = new PhongMaterial();
	phongThree->SetAmbientIntensity(0.15);
	phongThree->SetDiffuseIntensity(0.5);
	phongOne->SetSpecularIntensity(0.25);
	//phongThree->SetColour(0, 0.4, 0.2);				// dark green
	phongThree->SetColour(Colours::HotPink);
	Plane* plane_ptr = new Plane(Vector3(0, 0, -50), Vector3(0, 0, 1));
	plane_ptr->SetMaterial(phongThree);
	world.AddWorldObject(plane_ptr);
}

void BuildFunctions::Perspective(World& world)
{
	world.View.SetHorizontalResolution(400);
	world.View.SetVerticalResolution(400);
	world.View.SetPixelSize(1.0);
	world.View.SetGamma(1.0);
	world.View.SetSampleCount(16);

	world.BackgroundColour = Colours::Black;
	world.Tracer = new MultipleObjects(&world);

	Sphere* sphere = new Sphere(Vector3(-45, 45, 40), 50);
	sphere->SetColour(RGBColour(0.5, 0.6, 0.0));
	world.AddWorldObject(sphere);

	Triangle* triangle = new Triangle(Vector3(-110.0, -85.0, 80), Vector3(120, 10, 20), Vector3(-40, 50, -30));
	triangle->SetColour(RGBColour(0.0, 0.5, 0.5));
	world.AddWorldObject(triangle);

	Box* box = new Box(Vector3(20, -101, -100), Vector3(90, 100, 20));
	box->SetColour(RGBColour(0.8, 0.5, 0));
	world.AddWorldObject(box);

	
}

void BuildFunctions::TestTriangle(World& world)
{
	world.View.SetHorizontalResolution(400);
	world.View.SetVerticalResolution(400);
	world.View.SetPixelSize(1.0);
	world.View.SetGamma(1.0);
	world.View.SetSampleCount(16);

	world.BackgroundColour = Colours::Black;
	world.Tracer = new MultipleObjects(&world);

	Triangle* triangle = new Triangle(Vector3(0,0,0), Vector3(100,0,0), Vector3(0,100,0));
	triangle->SetColour(Colours::Cyan);
	world.AddWorldObject(triangle);


}
