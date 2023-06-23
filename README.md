
<div align = center>

# Sabr : A modern build system

![Discord](https://img.shields.io/badge/%3CGNU/Cord%3E-%237289DA.svg?style=for-the-badge&logo=discord&logoColor=white)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/made-with-crayons.svg)](https://forthebadge.com)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
[![forthebadge](https://forthebadge.com/images/badges/designed-in-etch-a-sketch.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/works-on-my-machine.svg)](https://forthebadge.com)
</div>

## Info
sabr is a build manager built from the unsatisfactory
experience from cmake, ridiculous size, useless tools,
massive "cmake-build-debug" directory", and more! ironically
we need to keep the CMakeLists.txt file for project wide autocomplete
in JetBrains CLion. I simply wanted a build tool with one singular file
for the entire project, therefore, sabr was born. one of my previous 
projects, gigachad, was an earlier attempt at this, however it became 
too complex and I decided to start from scratch to make it perfect.

Join us at discord: https://discord.gg/4U2Cs7sFW3

## Features (All will be implemented at some point)
- [X] Basic build, install, etc management system

## Active bugs (Check means fixed)
- [X] None!

## Configuration

```json
// the following is an example configuration (the config used by sabr)
// (comments are not allowed in json so remove them if you plan on using this config)

{
  "name": "sabr", // (default is "blank")
  "binary": "sabr", // (default is "blank")
  "sources": [ // put each of your CPP files in this array (default is ["main.cpp"])
    "main.cpp",
    "Builder.cpp",
    "Project.cpp",
    "Spinner.cpp"
  ],
  "compiler": "g++", // default is "g++"
  "compilerFlags": "-O3", // default is "-O3"
  "compilerFormat": "%c %s -o %o %f" // default is this as well
}
```

## THANK YOU
**crazywillbear: https://github.com/crazywillbear** - *emotional support and is currently developing a package manager using this as a build system*  