#include "stdafx.h"

ISampler::ISampler()
{
	nSamples = 16;
	nSets = SAMPLER_SET_COUNT;

	_totalSamples = nSamples * nSets;
	nextIndex = 0;
}

ISampler::ISampler(const int numSamples)
{
	nSamples = numSamples;
	nSets = SAMPLER_SET_COUNT;

	_totalSamples = nSamples * nSets;
	nextIndex = 0;
}

ISampler::ISampler(const int numSamples, const int numSets)
{
	nSamples = numSamples;
	nSets = numSets;

	_totalSamples = nSamples * nSets;
	nextIndex = 0;
}

void ISampler::InitializeSampler()
{
	GenerateSamples();
	MapSamplesToUnitDisk();
	MapSamplesToUnitHemisphere();
	SetupShuffledIndices();
}

Point2D ISampler::SampleUnitSquare()
{
	if (nextIndex % nSamples == 0)
	{
		jump = (World::RandomInt() % nSets) * nSamples;
	}

	return samples[jump + shuffledIndices[jump + nextIndex++ % nSamples]];
}

Point2D ISampler::SampleUnitDisk()
{
	throw "Not Implemented. See textbook chapter 6.";
}

Vector3 ISampler::SampleUnitHemisphere()
{
	throw "Not Implmeneted. See textbook chapter 7.";
}

void ISampler::SetupShuffledIndices()
{
	shuffledIndices.reserve(nSamples * nSets);

	std::vector<int> indices;

	for (int i = 0; i < nSamples; i++)
	{
		indices.push_back(i);
	}

	for (int set = 0; set < nSets; set++)
	{
		std::random_shuffle(indices.begin(), indices.end());

		for (int sample = 0; sample < nSamples; sample++)
		{
			shuffledIndices.push_back(indices[sample]);
		}
	}
}

void ISampler::MapSamplesToUnitDisk()
{
	// Polar coordinates on the disk
	Float r, phi; 
	Point2D samplePoint;

	diskSamples.reserve(_totalSamples);

	for (int i = 0; i < _totalSamples; i++)
	{
		// Map sample points to the range ([-1,1], [-1,1])

		samplePoint.X = 2.0 * samples[i].X - 1.0;
		samplePoint.Y = 2.0 * samples[i].Y - 1.0;

		// Sectors 1 and 2
		if (samplePoint.X > -samplePoint.Y)
		{
			if (samplePoint.X > samplePoint.Y)
			{
				// Sector 1
				r = samplePoint.X;
				phi = samplePoint.Y / samplePoint.X;
			}
			else
			{
				// Sector 2
				r = samplePoint.Y;
				phi = 2.0 - samplePoint.X / samplePoint.Y;
			}
		}
		else // Sectors 3 and 4
		{
			if (samplePoint.X < samplePoint.Y)
			{
				// Sector 3
				r = -samplePoint.X;
				phi = 4.0 + samplePoint.Y / samplePoint.X;
			}
			else
			{
				// Sector 4
				r = -samplePoint.Y;
				// Make sure we don't divide by zero.
				samplePoint.Y != 0.0 ? phi = 6.0 - samplePoint.X / samplePoint.Y : 0.0;
			}
		}

		phi *= PI_BY_FOUR;

		diskSamples.push_back(Point2D(r * cos(phi), r * sin(phi)));

	}
}

void ISampler::MapSamplesToUnitHemisphere()
{
	hemisphereSamples.reserve(_totalSamples);

	for (int i = 0; i < _totalSamples; i++)
	{
		Float cosPhi = cos(TWO_PI * samples[i].X);
		Float sinPhi = sin(TWO_PI * samples[i].X);
		Float cosTheta = pow((1.0 - samples[i].Y), 1.0 / (NAT_LOG_E + 1.0));
		Float sinTheta = sqrt(1.0 - cosTheta * cosTheta);
		Float pu = sinTheta * cosPhi;
		Float pv = sinTheta * sinPhi;
		Float pw = cosTheta;

		hemisphereSamples.push_back(Vector3(pu, pv, pw));
	}
}

void ISampler::ShuffleSamples()
{

}