// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define _AFXDLL

#include "targetver.h"

#define NOMINMAX
//#include <Windows.h>
#include <cassert>

#pragma comment (lib,"Gdiplus.lib")

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <mutex>
#include <limits>
#include <random>
#include <string>
#include <sstream>
#include <locale>
#include <codecvt>

#include <afxdlgs.h>


namespace Gdiplus
{
	using std::max;
	using std::min;
}

#include <ObjIdl.h>
#include <gdiplus.h>

#include "lib/lodepng.h"

// TODO: reference additional headers your program requires here

#include "Penthesilea.h"
#include "WinMainParameters.h"
#include "RenderWindow.h"

#include "Vector3.h"
#include "Point2D.h"
#include "RGBColour.h"

#include "ISampler.h"
#include "StandardSamplers.h"

#include "IReflectanceFunction.h"
#include "LambertianReflectance.h"
#include "PerfectSpecularReflectance.h"
#include "GlossySpecularReflectance.h"

#include "ILight.h"
#include "AmbientLight.h"
#include "DirectionalLight.h"
#include "PointLight.h"

#include "IMaterial.h"
#include "MatteMaterial.h"
#include "PhongMaterial.h"

#include "ICamera.h"
#include "OrthographicCamera.h"
#include "PinholeCamera.h"

#include "ViewPlane.h"
#include "Ray.h"

#include "ITracer.h"
#include "MultipleObjects.h"
#include "RayCastTracer.h"
#include "WhittedTracer.h"
#include "AreaLightingTracer.h"
#include "PathTracer.h"

#include "GeometricObject.h"
#include "Plane.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Quad.h"
#include "Box.h"

#include "TraceResult.h"

#include "World.h"
#include "BuildFunctions.h"
