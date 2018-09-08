#pragma once
#include "stdafx.h"

#define SAMPLER_SET_COUNT 83

class ISampler
{
public:
	ISampler();
	ISampler(const int numSamples);
	ISampler(const int numSamples, const int numSets);

	// Remove unwanted implicit members.
	ISampler(const ISampler&) = delete;
	ISampler& operator=(ISampler&) = delete;

	void InitializeSampler();

	Point2D SampleUnitSquare();
	Point2D SampleUnitDisk();
	Vector3 SampleUnitHemisphere();


	int GetSampleCount() const { return nSamples; }
	int GetSetCount() const { return nSets; }


protected:

	virtual void GenerateSamples() = 0;
	void SetupShuffledIndices();
	void ShuffleSamples();

	/// <summary>
	/// Map the samples from the unit square onto a unit disk.
	/// </summary>
	/// <remarks>
	/// This is based on the algorithm in Ch6 of Suffern, that maps the points into
	/// four sectors of the unit disk.
	/// </remarks>
	void MapSamplesToUnitDisk();
	/// <summary>
	/// Map the samples from the unit square onto a unit hemisphere.
	/// </summary>
	/// <remarks>
	/// Basd ont he algorithm in Ch7 of Suffern, using cosine power curves.
	/// </remarks>
	void MapSamplesToUnitHemisphere();

	int nSamples;
	int nSets;

	int _totalSamples;

	/// <summary>
	/// The sample points on a unit square.
	/// </summary>
	std::vector<Point2D> samples;
	/// <summary>
	/// The sample points on a unit disk.
	/// </summary>
	std::vector<Point2D> diskSamples;

	/// <summary>
	/// The sample points on a unit hemisphere.
	/// </summary>
	std::vector<Vector3> hemisphereSamples;

	/// <summary>
	/// Shuffled samples array indices.
	/// </summary>
	std::vector<int> shuffledIndices;
	/// <summary>
	/// The next index to use for sampling
	/// </summary>
	unsigned long nextIndex;
	/// <summary>
	/// Random jump index.
	/// </summary>
	int jump; 

};
