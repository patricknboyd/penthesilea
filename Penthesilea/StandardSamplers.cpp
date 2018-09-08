#include "stdafx.h"

RegularSampler::RegularSampler()
	: ISampler(1, 1)
{}

void RegularSampler::GenerateSamples()
{
	Float n = sqrt(nSamples);

	for (int p = 0; p < nSets; p++)
	{
		for (Float j = 0; j < n; j++)
		{
			for (Float k = 0; k < n; k++)
			{
				Point2D samplePoint(k / n, j / n);
				samples.push_back(samplePoint);
			}
		}
	}
}

// Jittered Sampler
JitteredSampler::JitteredSampler()
	: ISampler(16, SAMPLER_SET_COUNT) {}

JitteredSampler::JitteredSampler(const int numSamples)
	: ISampler(numSamples, SAMPLER_SET_COUNT) {}

JitteredSampler::JitteredSampler(const int numSamples, const int numSets)
	: ISampler(numSamples, numSets) {}

void JitteredSampler::GenerateSamples()
{
	Float n = sqrt(nSamples);

	for (int p = 0; p < nSets; p++)
	{
		for (Float j = 0; j < n; j++)
		{
			for (Float k = 0; k < n; k++)
			{
				Point2D samplePoint((k + World::RandomFloat()) / n, (j + World::RandomFloat()) / n);
				samples.push_back(samplePoint);
			}
		}
	}
}

// Multi-Jittered Sampler
MultiJitteredSampler::MultiJitteredSampler()
	: ISampler(16, SAMPLER_SET_COUNT) {}

MultiJitteredSampler::MultiJitteredSampler(const int numSamples)
	: ISampler(numSamples, SAMPLER_SET_COUNT) {}

MultiJitteredSampler::MultiJitteredSampler(const int numSamples, const int numSets)
	: ISampler(numSamples, numSets) {}

void MultiJitteredSampler::GenerateSamples()
{
	// This code copied from textbook source.
	// nSamples needs to be a perfect square

	int n = (int)sqrt((Float)nSamples);
	Float subcell_width = 1.0 / ((Float)nSamples);

	// fill the samples array with dummy points to allow us to use the [ ] notation when we set the 
	// initial patterns

	Point2D fill_point;
	for (int j = 0; j < nSamples * nSets; j++)
		samples.push_back(fill_point);

	// distribute points in the initial patterns

	for (int p = 0; p < nSets; p++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				samples[i * n + j + p * nSamples].X = (i * n + j) * subcell_width + World::RandomFloat(0, subcell_width);
				samples[i * n + j + p * nSamples].Y = (j * n + i) * subcell_width + World::RandomFloat(0, subcell_width);
			}
		}
	}

	// shuffle x coordinates

	for (int p = 0; p < nSets; p++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int k = World::RandomInt(j, n - 1);
				Float t = samples[i * n + j + p * nSamples].X;
				samples[i * n + j + p * nSamples].X = samples[i * n + k + p * nSamples].X;
				samples[i * n + k + p * nSamples].X = t;
			}
		}
	}

	// shuffle y coordinates

	for (int p = 0; p < nSets; p++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) 
			{
				int k = World::RandomInt(j, n - 1);
				Float t = samples[j * n + i + p * nSamples].Y;
				samples[j * n + i + p * nSamples].Y = samples[k * n + i + p * nSamples].Y;
				samples[k * n + i + p * nSamples].Y = t;
			}
		}
	}
}
