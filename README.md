# Arduino Game Console

This Arduino project implements a simple game console featuring two classic games: Pong and Car Race. It utilizes an Adafruit TFT display along with a Funduino joystick  and pushbuttons arduino UNO.

## Features

- Two classic games: Pong and Car Race.
- Intuitive menu interface for game selection.
- Real-time gameplay with collision detection and scoring.
- Supports joystick and buttons for user interaction.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno)
- Adafruit 1.44 inch TFT display (compatible with ST7735 driver)
- Funduino Joystick module
- Wires and breadboard for connections
## Configuration for Funduino Joystick module

![Joystick Configuration](circuitdiagram/joystickconfiguration.jpeg)
## Installation

1. Connect the Adafruit TFT display and other hardware components to the Arduino board following the provided wiring diagram.
2. Install the necessary libraries:
   - Adafruit GFX Library
   - Adafruit ST7735 Library
3. Upload the provided Arduino sketch (`.ino` file) to the Arduino board using the Arduino IDE or compatible software.
4. Ensure all connections are secure and power on the system.

## Usage

1. Upon powering on the device, a welcome screen will be displayed on the TFT screen.
2. Navigate through the menu using the joystick and select a game by pressing the appropriate button.
3. Follow the on-screen instructions to play the selected game.
4. Enjoy the gameplay experience!

## Examples

<center>

First Display (Wait 6sec it will redirect to next interface)
<br>
<br>
<img src="examples/welcome.jpeg" alt="Welcome Screen" width="400" style="margin: auto; display: block;">

Select game Display(use up and down button to move the selector button and enter select button to go with selected game)
<br>
<br>
<img src="examples/selectgame.jpeg" alt="Game Selection" width="400" style="margin: auto; display: block;">
<br>

Pong game entry (use up and down button to move the selector button and enter select button to go with selected option)
<br>
<br>
<img src="examples/pongentry.jpeg" alt="Pong Entry" width="400" style="margin: auto; display: block;">
<br>

Pong game Rules (Wait 6sec it will redirect to next interface)
<br>
<br>
<img src="examples/pongrule.jpeg" alt="Pong Rules" width="400" style="margin: auto; display: block;">
<br>

Pong game display (use joystick to move blue paddle)
<br>
<br>
<img src="examples/pongdisplay.jpeg" alt="Pong Gameplay" width="400" style="margin: auto; display: block;">
<br>

Pong game win (walt 5 sec to move into selcted game interface )
<br>
<br>
<img src="examples/pongmewin.jpeg" alt="Pong Win" width="400" style="margin: auto; display: block;">
<br>

Pong game lost (walt 5 sec to move into selcted game interface )
<br>
<br>
<img src="examples/ponggamelast.jpeg" alt="Pong Game Over" width="400" style="margin: auto; display: block;">
<br>

Car Race game entry (use up and down button to move the selector button and enter select button to go with selected option)
<br>
<br>
<img src="examples/carraceentry.jpeg" alt="Car Race Entry" width="400" style="margin: auto; display: block;">
<br>

Car Race rules (Wait 6sec it will redirect to next interface)
<br>
<br>
<img src="examples/cargamerule.jpeg" alt="Car Race Rules" width="400" style="margin: auto; display: block;">
<br>

Car game display (use joystick to move white car)
<br>
<br>
<img src="examples/cargamedisplay.jpeg" alt="Car Race Gameplay" width="400" style="margin: auto; display: block;">


Car game score (walt 5 sec to move into selcted game interface )
<br>
<br>
<img src="examples/cargameover.jpeg" alt="Car Race Game Over" width="400" style="margin: auto; display: block;">

</center>
