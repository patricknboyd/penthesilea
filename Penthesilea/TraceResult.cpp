#include "stdafx.h"


TraceResult::TraceResult(World& world)
	: HitDetected(false),
	LocalHitPoint(), HitPoint(),
	Normal(),
	Colour(Colours::Black),
	Ray(), Depth(), Direction(),
	WorldRef(world),
	Material(nullptr)
{

}

TraceResult::~TraceResult()
{
	// Nothing for now, will need more here once we get materials going.
}