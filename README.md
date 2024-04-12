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
