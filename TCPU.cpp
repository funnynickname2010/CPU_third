#include "TCPU.h"

TCPU::TCPU(size_t size_queue, int flow_intensity, int cpu_power) : task_flow(size_queue, flow_intensity)
{
	cpu_power_critical = cpu_power;
	state = 0;
	previous_state = 0;
}