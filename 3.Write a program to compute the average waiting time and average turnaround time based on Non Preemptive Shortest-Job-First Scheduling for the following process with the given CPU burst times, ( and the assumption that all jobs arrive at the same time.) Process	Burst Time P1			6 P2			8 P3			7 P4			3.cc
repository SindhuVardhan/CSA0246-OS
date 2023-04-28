def calculate_average_times(processes, burst_times):
    n = len(processes)
    waiting_time = [0] * n
    turnaround_time = [0] * n
    total_waiting_time = 0
    total_turnaround_time = 0

    # Sort the processes by burst time
    sorted_processes = sorted(range(n), key=lambda k: burst_times[k])

    # Calculate waiting time and turnaround time for each process
    for i in range(n):
        process_index = sorted_processes[i]
        if i == 0:
            waiting_time[process_index] = 0
        else:
            waiting_time[process_index] = burst_times[sorted_processes[i-1]] + waiting_time[sorted_processes[i-1]]
        turnaround_time[process_index] = burst_times[process_index] + waiting_time[process_index]

        total_waiting_time += waiting_time[process_index]
        total_turnaround_time += turnaround_time[process_index]

    # Calculate the averages
    avg_waiting_time = total_waiting_time / n
    avg_turnaround_time = total_turnaround_time / n

    return avg_waiting_time, avg_turnaround_time


# Define the process names and burst times
processes = ["P1", "P2", "P3", "P4"]
burst_times = [6, 8, 7, 3]

# Calculate the average times and print the results
avg_waiting_time, avg_turnaround_time = calculate_average_times(processes, burst_times)
print("Average Waiting Time:", avg_waiting_time)
print("Average Turnaround Time:", avg_turnaround_time)
