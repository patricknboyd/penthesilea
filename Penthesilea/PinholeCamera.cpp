#include "stdafx.h"

PinholeCamera::PinholeCamera()
	: ICamera()
{
	viewPlaneDistance = 10.0;
	zoomFactor = 1.0;
}

PinholeCamera::PinholeCamera(Vector3 eyePosition, Vector3 lookAtPosition, Vector3 upVector, Float distanceToViewPlane)
	: ICamera(eyePosition, lookAtPosition, upVector)
{
	viewPlaneDistance = distanceToViewPlane;
	zoomFactor = 1.0;
}

void PinholeCamera::RenderScene(const World& world)
{
	RGBColour colour;
	int depth = 0;
	Point2D samplePoint;
	Point2D pixelPoint;

	Float hRes = world.View.GetHorizontalResolution();
	Float vRes = world.View.GetVerticalResolution();
	Float size = world.View.GetPixelSize() / zoomFactor;

	Ray ray;
	ray.Origin = position;

	ISampler* sampler = world.View.GetSampler();

	for (int y = 0; y < vRes; y++)
	{
		for (int x = 0; x < hRes; x++)
		{
			colour = Colours::Black;

			for (int s = 0; s < world.View.GetSampleCount(); s++)
			{
				samplePoint = sampler->SampleUnitSquare();
				pixelPoint.X = size * (x - 0.5 * hRes + samplePoint.X);
				pixelPoint.Y = size * (y - 0.5 * vRes + samplePoint.Y);

				ray.Direction = GetRayDirection(pixelPoint);

				colour += world.Tracer->TraceRay(ray, depth);
			}

			colour = colour / world.View.GetSampleCount();
			colour = exposureTime * colour;

			world.DisplayPixel(x, y, colour);
		}
	}

}

Vector3 PinholeCamera::GetRayDirection(const Point2D& p) const
{
	Vector3 direction = (p.X * u) + (p.Y * v) - (viewPlaneDistance * w);
	return direction.Normalize();
}