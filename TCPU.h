#pragma once
#include "TTaskFlow.h"

class TCPU
{
public:

	TTaskFlow task_flow;

	unsigned int cpu_power_critical;
	bool state = 0;
	bool previous_state = 0;

	TCPU(size_t size_queue, int flow_intensity, int cpu_power);
};