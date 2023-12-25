#include "TComputationSystem.h"

int main()
{
	unsigned int cpu_power, flow_power, model_time, queue_size;

	cout << "Enter the cpu_power [0-99]: ";
	cin >> cpu_power;
	cout << endl;

	cout << "Enter the flow_power [0-99]: ";
	cin >> flow_power;
	cout << endl;

	cout << "Enter the size of the queue: ";
	cin >> queue_size;
	cout << endl;

	cout << "Enter the number of tics to model: ";
	cin >> model_time;
	cout << endl;


	TComputationSystem computation_system(queue_size, flow_power, cpu_power, model_time);

	for (int i = 0; i < model_time; i++)
	{
		computation_system.NextTic();
	}
};