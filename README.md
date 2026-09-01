# Alvironment

Alvironment is a custom OpenGL environment done to allow to create rapidly simple testigs and simulations without relying on another engin and removing all the extra tools other softwares offer that are not needed to what is actually required.

It has no graphics environment like other engines such as [Unity](https://unity.com/) or [Unreal](https://www.unrealengine.com/), everything is made by code, sort of similar to [MonoGame](https://monogame.net/) but using C++.

---

### Getting started

As any C++ project, a method  `int main()` is absolutly required to initialize anything we are building.

```cpp
#include "./engine/WindowProperties.h"
#include "./engine/Environment.h"

int main()
{
	WindowProperties properties(500, 500, "Test");
	Environment environment(&properties);

	std::cin.get();
	return 0;
}
```

This will create a 500 x 500 dark window on screen under the title "Test".

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