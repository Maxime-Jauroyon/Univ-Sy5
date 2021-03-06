#ifndef WORKER_H
#define WORKER_H

#include <sy5/types.h>

// Defines a worker (a data structure holding all information about a task's thread).
typedef struct worker {
    task task;
    run *runs;
    string last_stdout;
    string last_stderr;
    char *dir_path;
    int task_file_fd;
    int runs_file_fd;
    int last_stdout_file_fd;
    int last_stderr_file_fd;
} worker;

// Array of workers.
extern worker **g_workers;

// Array of running taskids (running workers).
extern uint64_t *g_running_taskids;

// Creates a worker.
// Returns `-1` in case of failure, else 0.
int create_worker(worker **dest, task *task, const char *tasks_path, uint64_t taskid);

// Frees a worker.
// Returns `-1` in case of failure, else 0.
int free_worker(worker *worker);

// Checks if a worker is running.
int is_worker_running(uint64_t taskid);

// Removes a running worker.
// Returns `-1` in case of failure, else 0.
int remove_worker(uint64_t taskid);

// Gets a running worker.
worker *get_worker(uint64_t taskid);

// Code for the worker's thread.
void *worker_main(void *worker_arg);

#endif /* WORKER_H. */