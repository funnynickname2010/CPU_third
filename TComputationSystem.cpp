#include "TComputationSystem.h"

TComputationSystem::TComputationSystem(size_t size_queue, int flow_intensity, int cpu_power, size_t model_time_lim) : cpu(size_queue, flow_intensity, cpu_power)
{
	average_execution_time = 0;
	model_time = 0;
	model_time_limit = model_time_lim;
	tasks_generated_in_total = 0;
	tasks_executed = 0;
	ignored_tasks = 0;
	cpu_idle = 0;
	cpu_summed_calculation_time = 0;
	current_task_number = 0;
}

void TComputationSystem::NextTic()
{
	model_time++;

	if (model_time_limit < 20) { cout << "\nTic " << model_time << ":\n"; }

	bool task_is_performed = ((rand() % 100) < cpu.cpu_power_critical);

	/*if (task_flow.queue.Full())
	{
		ignored_tasks++;
	}*/

	if (cpu.task_flow.NewTaskGenerate())
	{
		tasks_generated_in_total++;
		if (model_time_limit < 20) { cout << "The task number " << cpu.task_flow.task_count << " has been delivered to the queue.\n"; }
	}

	if (cpu.task_flow.HasTask() && cpu.state == 0)
	{
		cpu_summed_calculation_time++;
		cpu.state = 1;
		cpu.previous_state = 0;
		current_task_number = cpu.task_flow.queue.Dq();

		if (model_time_limit < 20) { cout << "The CPU is free\n" << "Task number " << cpu.task_flow.task_count << " has been delivered to the CPU\n"; }
	}
	else if (cpu.task_flow.HasTask() && cpu.state == 1)
	{
		cpu_summed_calculation_time++;
		cpu.previous_state = 1;

		if (model_time_limit < 20) { cout << "The CPU is busy\n"; }

		if (task_is_performed)
		{
			tasks_executed++;
			cpu.state = 0;
			if (model_time_limit < 20) { cout << "The task number " << (tasks_executed + 1) << " has been executed by the CPU\n"; }
		}
	}
	else if (!cpu.task_flow.HasTask() && cpu.state == 0)
	{
		cpu_idle++;

		if (model_time_limit < 20) { cout << "The CPU is free\n" << "The queue is empty, the CPU idles.\n"; }
	}
	else if (!cpu.task_flow.HasTask() && cpu.state == 1)
	{
		cpu_summed_calculation_time++;

		if (model_time_limit < 20) {
			cout << "The CPU is busy\n";
		}

		cpu.previous_state = 1;
		if (task_is_performed)
		{
			tasks_executed++;
			cpu.state = 0;
			if (model_time_limit < 20) { cout << "The task number " << (tasks_executed + 1) << " has been executed by the CPU\n"; }
		}
	}
}

