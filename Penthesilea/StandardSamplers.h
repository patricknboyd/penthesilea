#pragma once
#include "stdafx.h"


class RegularSampler : public ISampler
{
public:
	RegularSampler();

private:
	virtual void GenerateSamples();
};

class JitteredSampler : public ISampler
{
public:

	JitteredSampler();
	JitteredSampler(const int numSamples);
	JitteredSampler(const int numSamples, const int numSets);

private:
	virtual void GenerateSamples();
};

class MultiJitteredSampler : public ISampler
{
public:

	MultiJitteredSampler();
	MultiJitteredSampler(const int numSamples);
	MultiJitteredSampler(const int numSamples, const int numSets);

private:
	virtual void GenerateSamples();
};