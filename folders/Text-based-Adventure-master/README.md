# ENGG1340 Group Project

## Members:

- Anchit Mishra 
  - UID: 3035665665 
  - Username: anchit1729 
- Ajayveer Singh 
  - UID:3035664635 
  - Username: Quacktillius

## Proposal

In this project, we have used the 1981 arcade game **Galaga** as a source of inspiration and designed a * *space arcade shooter* *.

### Game Description
##### Name: Astrid Crisis
The game's shooter mechanics and its arcadey style are the game's main feature, but there is also a minimalistic story-line (see Premise).

##### Premise
You are a combat pilot sent as part of the UN Space Exploration Team (UNSET) to the newly discovered exoplanet Astrid. However, upon arrival you quickly find out that the planet was a trap set up by Alien Demons. With all of your crew members dead, you must fight in a heroic last-stand against an endless onslaught of Demons, killing as many as you can.

##### Objective: Destroy waves of enemies before they reach the bottom of the screen, and survive for as long as you can.

##### Player Mechanics
```
                                                    ^ 
                                                   /#\
                                                   H#H
```
The player will control a ship at the bottom of the screen.
* Can move horizontally
* Can fire projectiles towards enemies
* Can pick up "power-ups" that grant special abilities such as increased damage, faster movement etc.
* Has 3 lives, i.e can take damage thrice without having to restart

##### Enemies
```
                                                   O-O
```
Enemy ships will randomly appear at the top of the screen and move downwards.
Some enemies will fuse together into a chain or block (randomly), and will be harder to gun down.

##### Power Ups
* BFB (inspired by the BFG from the Doom games, it kills all enemy ships in one shot, but is one use only)
* Extra Life (lets the player respawn once more without losing progress)
* Hyperjets (makes player movements 100% faster)

### Game Features (Corresponding to Coding Requirements)

| Coding Requirements                      | Feature                                                                                                    |
| ---------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| Generation of Random Events              | Enemies and power-ups are spawned randomly into the game world. Moreover, the number of enemies that can spawn on screen, although limited by a cap, is random up to that cap value.                              |                               
| Data Structures for Storing Game Status  | We use text file-handling in order to store Leaderboard scores and handle related functions in a seamless manner via classes. Moreover, at any given instant, the game status is stored in an object of the "game" class to interface with the program smoothly and without security issues.                               |
| Dynamic Memory Management (DMM)          | We implement DMM to maintain dynamic queues of objects to be spawned into the game world, as well as dynamically initialise data structures for the game files upon starting the game. Also, memory is allocated dynamically within the intro sequence.             |
| File Input/Output                        | We use text file handling in order to maintain a record of top scores within Leaderboard.txt, and display top 10 scores from the file                   |
| Multiple Files of Program Code           | We use separate files for various features of the game (intro sequence handling, game status, menu etc.)       |

## DISCLAIMER
Regarding the intro sequence that plays at the beginning of the game:
* It is purely for comedic purposes, and thus, should be taken in a light hearted manner.
* The first line serves not to disregard the worth of the project, calling it "mediocre", but rather to set the tone for intro
* The second line furthers this
* We are NOT saying that this is the best project. The 3rd line was purely comedic. No one was bribed, or said that.

## Controls:
### Menu:
`1`- Make a new Game (No need to press Enter)  
`2`- Leaderboard (No need to press Enter, but press enter once the Leaderboard is displayed in order to return to the menu)   
`3`- Exit (No need to press Enter)  

### In-game:
`A`- Strafe left  
`D`- Strafe right  
`W`- Shoot  
`P`- Exit the game (without saving)

## Power-Up Symbols:
### BFB: `*`
### Extra Life: `#`
### Hyper-jet: `@`

## DEVELOPER NOTES (IMPORTANT)
* A glitch in the game may randomly occur that causes the enemies to stick to player projectiles. At this point, the player must pick up a BFB powerup in order to reset enemy spawns and rid himself of the curse. Alternatively, the game may be terminated by pressing `P` on the keyboard. Then, running `make clean`, `make Game` and finally, `make run` removes the glitch.
* If `P` is pressed to exit the game, the current score WILL NOT BE SAVED.

## EXTERNAL LIBRARIES USED - `ncurses`
* For the purposes of this project, we have used the library `ncurses` to draw console graphics. This library was used because it makes it easier for the program to navigate to a custom coordinate and set characters, instead of drawing the screen top-down every time an update is made to the game state.
* `ncurses` also enables dynamic screen sizing, which ensures that the program can scale with displays of different sizes.
* The library does not need to be manually set up by the user as a prerequisite. The Makefile deals with that process.

## INSTRUCTIONS FOR BUILDING AND RUNNING 
* Once the repository has been cloned, run the command `make Game` in order to install the necessary library (ncurses) and set up the executable file (`Game`), log file (`log.txt`), and score save file (`Leaderboard.txt`).
* After installation, run `make run` in order to run the executable and start the game.
* The recommended size for running the game is 24 rows by 80 cols. However, the game will render and run at any window size, albeit with a reduced difficulty (since enemies take longer to reach the bottom of the screen).
* To clear up the game's executable files and text files `log.txt` and `Leaderboard.txt`, use the command `make clean`
* To clear up ALL of the game's files and uninstall `ncurses`, run the command `make full_clean`.
