/*
 * tash.h
 *
 *  Created on: Aug 25, 2015
 *      Author: rba90
 */

#ifndef TASK_H_
#define TASK_H_

// prototype of task
// void function(void *args)
typedef void (* task_func_t)(void *args);

typedef struct task_struct
{
	// state of each task
	// 0 for unused
	unsigned char state;

	unsigned int task_id;

    // function handler
    task_func_t func;

    // arguments
    void *args;

    // frequency of task, measured in period
    unsigned long period;

    // next available slot
    unsigned long reschedule;
} task_t;

void scheduler_init(unsigned int num_tasks);
void scheduler_create(unsigned int *task_id, task_func_t func, void *args, unsigned long period);
void scheduler_cancel(unsigned int task_id);
void scheduler_start();
void scheduler_clean();

task_t *scheduler_task_get(unsigned int task_id);



#endif /* TASK_H_ */
