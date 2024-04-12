# magxTasksCoordinator Library

## Overview

The `magxTasksCoordinator` library provides a simple and flexible way to manage tasks and timers in Arduino projects. It allows you to create tasks with customizable timeout intervals, callback functions, and timer types. This library is particularly useful for implementing asynchronous behavior and managing time-sensitive tasks in your Arduino sketches.

## Features

- Create tasks with customizable timeout intervals.
- Support for one-shot and periodic timers.
- Ability to set callback functions for task execution.
- Support for repeat timeout callbacks.
- Lightweight and easy to use.

## Installation

1. Download the `magxTasksCoordinator` library ZIP file from the [GitHub repository](https://github.com/magxTz/magxTasksCoordinator).
2. In the Arduino IDE, go to `Sketch > Include Library > Add .ZIP Library...` and select the downloaded ZIP file.
3. The library will be installed and ready to use in your Arduino sketches.

## Usage

### Creating Tasks

To create a task, instantiate an object of the `magxTaskCoordinator` class with the desired timeout interval:

```cpp
magxTaskCoordinator task(timeoutMs);
```

You can optionally specify the number of repetitions and stoppage interval for periodic tasks.

### Setting Callbacks

Set callback functions to be executed when the task timeout occurs:

```cpp
task.setCallback(callbackFunction);
```

### Starting and Stopping Tasks

Start and stop tasks as needed:

```cpp
task.start();  // Start the task
task.stop();   // Stop the task
```

### Updating Tasks

Call the `update()` method periodically in your main loop to check for task timeouts:

```cpp
void loop() {
    // Update tasks
    task.update();
}
```

### Adding Tasks to Manager

Tasks can be managed by a `magxTasksManager` object. Add tasks to the manager for centralized control:

```cpp
magxTasksManager manager;
manager.addTimer(&task);
```

## Examples

Check out the `examples` folder for usage examples and demonstrations of the library features.

## License

This library is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! If you have any suggestions, bug reports, or feature requests, please open an issue or submit a pull request on GitHub.
```