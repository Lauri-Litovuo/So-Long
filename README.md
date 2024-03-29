# So-Long

<p align="center">
  <img src="https://github.com/Lauri-Litovuo/So-Long/blob/main/showcase/squirrel_away.gif" />
</p>

## Introduction
The So_long is a 2D game project that was done as a part of the curriculum for the Hive Helsinki Coding Sccool. The goal of the project was to create a simple 2D game using C and a graphics library called MLX. The game mechanics and rules were given by the school.

This project provided an opportunity for me to learn about game development, use of math libraries and building a graphical interface using C. During the project I also utlized bash scripting to build an automated testing program to test the program.

## Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Game](#game)
- [Tests](#tests)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Installation
To play the game follow these steps:
1. Clone the repository to your local machine using `git clone https://github.com/Lauri-Litovuo/so-long so_long`.
2. Navigate to the project directory: `cd so_long`.
3. Run the `make` command to compile the source files.

And you're good to go!

To play check available maps in `cd maps/valid/` or create your own map. Run a map use ./so_long NameOfaMap.ber for example `./so_long subj_ex2.ber` 

An macOS is required to run this game. You can find MLX dependencies on their git: [MLX42](https://github.com/codam-coding-college/MLX42)

## Game
The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
You can move using arrow keys or `W A S D`-keys. Your move count is shown in the terminal. You can quit the game by using ESC.

## Tests
The program was play tested and by using run_maps.sh tester, which runs invalid maps and invalid user inputs.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

The sprites to this game were downloaded from itch.io by the artists [A_Foxli](https://a-foxli.itch.io/lost-forest-pixel-tile-forest), [Vivite](https://vivite.itch.io/the-squirrel-rise), and [MXT Games](https://mxtgames.itch.io/forest-vegetation-lite). Thank you for sharing your work.