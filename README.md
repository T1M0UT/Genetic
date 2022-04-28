# Genetic Cell Simulator
**Natural selection genetic algorithms**

This project is a simulator for natural selection of cells in specific enviroments. Each cell is represented by a genome of 64 commands, where a command is a number between 0 and 64 and it defines behaviour of the cell. In such way, a cell is an emulation of a processing unit. Cells can behave as individual organisms or evolve into multicell structures. For every move the cell uses some of its energy, so there are couple of ways to earn the energy to survive: by eating other cells, eating organic (dead cells) or process poison into minerals and then eating it. Multicell organisms can develop a mechanism of sharing the enegry with one another.
For the greater performance, the project is implemented in C++. It uses multithreading to speed up things as well. And SFML for the UI.

A prototype implemented in JS:
https://editor.p5js.org/krasnianskiy/full/ueF5nNSmh
![Example](https://i.imgur.com/pd6qdSk.jpeg)

### Multicell organisms
![Families](https://i.imgur.com/sWtmF1H.jpeg)

## Tech
- C++
- CMake
- CLion

## Simplified UML scheme:
![UML](https://i.imgur.com/FIP0qWO.jpeg)

## Installation
- Install SFML first
https://www.sfml-dev.org/download/sfml/2.5.1/



## Team 
_Tymur Krasnianskyi_
_Volodymyr Kuchynskiy_

## License

Ukrainian Catholic University

