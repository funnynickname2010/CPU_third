#pragma once
#include "TQueue.h"
#include <random>

class TTaskFlow
{
public:

	TQueue<int> queue;
	unsigned int flow_intensity_critical;

	size_t task_count = 0;

	TTaskFlow(size_t size, unsigned int flow_intensity);

	bool HasTask();
	bool NewTaskGenerate();
};