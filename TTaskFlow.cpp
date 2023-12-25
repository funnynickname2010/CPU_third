#include "TTaskFlow.h"

TTaskFlow::TTaskFlow(size_t size, unsigned int flow_intensiry) : queue(size)
{
	flow_intensity_critical = flow_intensiry;
	task_count = 0;
}

bool TTaskFlow::HasTask()
{
	return (!queue.Empty());
}

bool TTaskFlow::NewTaskGenerate()
{
	if (((rand() % 100) < flow_intensity_critical) && !queue.Full())
	{
		queue.Enq(task_count++);
		return 1;
	}
	return 0;
}