# philosophers
The "Philosophers" project is a simulation of the dining philosophers problem, which involves a set of philosophers sitting around a table and contemplating. Each philosopher alternates between thinking, eating, and sleeping, but they must share a limited number of resources (forks) with their adjacent philosophers.   
The goal is to prevent deadlock and starvation while ensuring that each philosopher can eat.

## Features
- Simulates the dining philosophers problem
- Utilizes threads and synchronization mechanisms (mutexes) to prevent deadlock and starvation
- Dynamic control of simulation parameters through command-line arguments
- Updates of the simulation in real-time

## Prerequisites
- [GCC](https://gcc.gnu.org/) compiler

## Installation
1. Clone the repository
   `git clone https://github.com/yourusername/philosophers.git`
2. Compile the program
   `cd philosophers/philo; make`

## Usage
Use the following command to run:
`./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [(optional) number_of_times_each_philosopher_must_eat]`  
- number_of_philosophers: The number of philosophers sitting around the table.
- time_to_die: The time (in milliseconds) after which a philosopher dies if they haven't started eating.
- time_to_eat: The time (in milliseconds) required for a philosopher to finish eating.
- time_to_sleep: The time (in milliseconds) a philosopher spends sleeping before thinking or eating.
- number_of_times_each_philosopher_must_eat: Optional argument specifying the number of times each philosopher must eat before the simulation ends.

## Resources
- [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) - Wikipedia article
- [Philosophers Subject](https://github.com/rgilles42/Philosophers/blob/main/subject.pdf) - Project subject and requirements
