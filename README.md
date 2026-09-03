# Alvironment

Alvironment is a custom OpenGL environment done to allow to create rapidly simple testings and simulations without relying on another engin and removing all the extra tools other softwares offer that are not needed to what is actually required.

It has no graphics environment like other engines such as [Unity](https://unity.com/) or [Unreal](https://www.unrealengine.com/), everything is made by code, sort of similar to [MonoGame](https://monogame.net/) but using C++.

---

### Getting started

To start a project in this environment, the first thing we need to create is a class which inherits from the class  `AbstractWorld`, which will offer a protected variable Environment you will need to set and forces the new class to contain the methods `initialize` and  `update`.

```cpp
#pragma once

#include "alvironment/AbstractWorld.h"

class World : public AbstractWorld
{
public:
	void initialize() override;
	void update(double) override;
};
 ```

 The method  `initialize` will be automatically fired once the world is created, which means we have to set up its configutations as the windows properties (width, height, title and whether the window is resizeable) with the WindowProperties and set it to the environment like the example below.

 ```cpp
#include "World.h"

#include "alvironment/window/WindowProperties.h"

void World::initialize()
{
	WindowProperties properties(500, 500, "Test", false);
	this->environment.emplace(&properties);
}

void World::update(double deltaTime) {}
```

The  `update` method we will fired once for frame, offering a variable $\Delta t$ that corresponds to the time passed between the last frame and the current one.

Once finished our world, we will go to  `main.cpp`, create an instance of it and issue it to the method `setUp` included in `alvironment/WorldSetUp.h`. Once this is finished, we are free to test our worlds and make our simulations.

```cpp
#include <iostream>

#include "alvironment/WorldSetUp.h"
#include "./world/World.h"

int main()
{
	World myWorld;
	setUp(myWorld);

	std::cin.get();
	return 0;
}
```

Additionally, this project also offers a few examples of simulations and a template for a new world in the directory [Project](./Alvironment/src/Project).

---

### Inside the engine

In the [include](./Alvironment/include) directory, the majority of the environment logic will be found with a few features that might be useful for the projects that use this environment or even for the environment itselt internally, such as mathematical constants or terminal colors.

The directory [include/alvironment](./Alvironment/include/alvironment) contains the whole environment logic, such as the geometry or the whole graphic logic.

In [include/debug_helper](./Alvironment/include/debug_helper), there are codes that help you making a better testing, mainly with the terminal offering new terminal functions for printing and colors codes. Furthermore, in the file [print.h](./Alvironment/include/debug_helper/print.h) resides a variable `DEBUG_ENGINE`, which is by default false, but if it is changed to true, all the internal prints of the enviroment will be shown once thea project is ran.

Moreover, there are some mathematical features in [include/math](./Alvironment/include/math). Here there are useful math constants and classes to simplify calculations.

---

### Motivation to create the environment

Even thought it might sound pedantic to most of the people, I did not want to have certain tools most of the engines have as I wanted to create my own things from scratch and be able to sink in them.

I have been using simple applications as [Processing](https://processing.org/) but it was not exactly what I have been looking for.

Furthermore, I also wanted to attempt to do something more than just making projects that are just enjoyable as a user or player, I wanted to create somethig other developers as me would enjoy.