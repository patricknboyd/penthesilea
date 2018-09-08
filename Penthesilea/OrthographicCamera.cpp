#include "stdafx.h"

OrthographicCamera::OrthographicCamera()
	: ICamera()
{

}

OrthographicCamera::OrthographicCamera(Vector3 eyePosition, Vector3 lookAtPosition, Vector3 upVector)
	: ICamera(eyePosition, lookAtPosition, upVector)
{

}

void OrthographicCamera::RenderScene(const World& world)
{
	RGBColour pixelColour;
	Point2D samplePoint;
	Point2D pixelPoint;
	Ray ray(Vector3(), Vector3(-w.X, -w.Y, -w.Z));

	ISampler* sampler = world.View.GetSampler();
	Float pixelSize = world.View.GetPixelSize();
	int hRes = world.View.GetHorizontalResolution();
	int vRes = world.View.GetVerticalResolution();

	for (int y = 0; y < world.View.GetVerticalResolution(); y++)
	{
		for (int x = 0; x < world.View.GetHorizontalResolution(); x++)
		{
			pixelColour = Colours::Black;

			for (int n = 0; n < world.View.GetSampleCount(); n++)
			{
				samplePoint = sampler->SampleUnitSquare();
				pixelPoint.X = pixelSize * (x - 0.5 * hRes + samplePoint.X);
				pixelPoint.Y = pixelSize * (y - 0.5 * vRes + samplePoint.Y);

				ray.Origin = Vector3(pixelPoint.X, pixelPoint.Y, position.Z);

				pixelColour += world.Tracer->TraceRay(ray);
			}

			world.DisplayPixel(x, y, pixelColour / world.View.GetSampleCount());
		}
	}
}