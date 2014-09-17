# Tank Garage

An OpenGL game hosting several chassis parts and weapons that can be chosen from to build different futuristic tanks. The game's graphics are completely rendered from code without using any modelling tools (e.g. Blender).

### Screenshots

![screen1](/screenshots/screen1.jpg)

![screen2](/screenshots/screen2.jpg)

![screen3](/screenshots/screen3.jpg)

![screen4](/screenshots/screen4.jpg)

### Features

* 3 different options for each of the tank's front, head, rear & weapon. 
* The ability to orient/rotate the head, weapon & wheels, along with setting different camera viewing angles.
* A first-person view, through which the environment can be navigated. 

### Download

[Version 1.0](https://github.com/bishoybassem/tank-garage/releases/download/v1.0/Tank.Garage.zip)

### OpenGL Setup

To run the release do the following:

1- Download & extract the latest version of OpenGL from [here](http://user.xmission.com/~nate/glut.html).
2- Place "glut32.dll" in the "C:\Windows\System32" directory.

To edit the solution in Visual Studio:

3- Place "glut.h" in the "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\include" directory.
4- Place "glut32.lib" in the "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\lib" directory.
(directories can differ depending on the used version of VS and it's installation directory)