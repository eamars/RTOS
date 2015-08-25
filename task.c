/*
 * tash.c
 *
 *  Created on: Aug 25, 2015
 *      Author: rba90
 */

#include "stdlib.h"
#include "string.h"
#include "task.h"

typedef struct scheduler_struct
{
	task_t *tasks;
	unsigned int max_num_tasks;

} scheduler_t;

// task scheduler
scheduler_t scheduler;

// systick
extern volatile unsigned long sysTick;

void scheduler_init(unsigned int num_tasks)
{
	// allocate memory for tasks
	scheduler.tasks = (task_t *) malloc (num_tasks * sizeof(task_t));

	// if failed to allocate, then trap here
	if (scheduler.tasks == NULL)
	{
		while (1)
		{
			// unable to allocate heap memory for tasks
			// please consider to change the size of heap and stack
		}
	}

	// init memory block
	memset(scheduler.tasks, 0, num_tasks * sizeof(task_t));

	scheduler.max_num_tasks = num_tasks;
}

void scheduler_clean()
{
	free(scheduler.tasks);
}

// find the next available slot, return null if not found
task_t *next_available_slot()
{
	unsigned int i = 0;
	for (i = 0; i < scheduler.max_num_tasks; i++)
	{
		if (scheduler.tasks[i].state == 0)
		{
			scheduler.tasks[i].task_id = i;
			return &scheduler.tasks[i];
		}
	}

	return NULL;
}

void scheduler_create(unsigned int *task_id, task_func_t func, void *args, unsigned long period)
{
	task_t *task;

	// allocate slot for new task
	task = next_available_slot();
	if (task == NULL)
	{
		return;
	}

	// return task id
	*task_id = task->task_id;

	// copy information to task
	task->func = func;
	task->args = args;
	task->period = period;

	// set active
	task->state = 1;

}

void scheduler_cancel(unsigned int task_id)
{
	scheduler.tasks[task_id].state = 0;
}


void scheduler_start()
{
	unsigned long tick;
	int i;


	while (1)
	{
		// get the real time clock
		tick = sysTick;

		for (i = 0; i < scheduler.max_num_tasks; i++)
		{
			// for activated task only
			if (scheduler.tasks[i].state == 0)
			{
				continue;
			}

			if (tick > scheduler.tasks[i].reschedule)
			{
				// execute task
				scheduler.tasks[i].func(scheduler.tasks[i].args);

				// reschedule for next execution
				scheduler.tasks[i].reschedule += scheduler.tasks[i].period;

				continue;
			}
		}
	}
}





