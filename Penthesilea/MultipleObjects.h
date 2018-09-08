#pragma once
class MultipleObjects : public ITracer
{
public:
	MultipleObjects(World* world);
	virtual RGBColour TraceRay(const Ray& ray, const int depth = 1) const;
};