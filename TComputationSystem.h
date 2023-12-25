#pragma once
#include "TQueue.h"
#include "TTaskFlow.h"
#include "TCPU.h"
using namespace std;

class TComputationSystem
{
public:

	TComputationSystem(size_t size_queue, int flow_intensity, int cpu_power, size_t model_time_lim);

	TCPU cpu;

	unsigned int average_execution_time = 0;
	unsigned int model_time = 0;
	unsigned int model_time_limit;

	unsigned int tasks_generated_in_total = 0;
	unsigned int tasks_executed = 0;
	unsigned int ignored_tasks = 0;
	unsigned int cpu_idle = 0;
	unsigned int cpu_summed_calculation_time = 0;

	unsigned int current_task_number;

	void NextTic();
	void AllTheTics();
};