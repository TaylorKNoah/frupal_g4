# README
## CS300 Group Project: Frupal  
## Group 4  

| Members | | | |  |  
--- | --- | --- | --- | --- |  
|  `Taylor Noah`  |  `Jordan Malubay` | `Lawrence Scroggs` | `Wai Chan`  |  `Carl Knori` |  


### To Compile and Run  
| Compile | Run |  Clean |
--- | ---  | ---
| `make` | `./frupal map.txt` |  `make clean` |


### Controls  
- Movement  
  - `W` = North  
  - `A` = West  
  - `S` = South  
  - `D` = East  
  
 - Toggle Inventory Display
   - `I`  
 - Menu Interaction
   - `Y` \ `N`


### Implementation Completion / Incomplete Lists  
 - Player Can
   - Start new game with fully functioning map  
   - Move the hero
   - Move the cursor
   - See whiffle and energy count in the menu  
     - Cursor content will be displayed in the menu  
   - Toggle the inventory menu
   - Pick up tools found on the map, if they can afford the cost  
   - Eat food on the map, if they can afford it  
   - Pick up treasure at no cost  
   - Choose to not pick an item up and leave it on the map  
   - Find clues that may or may not lead to the royal diamonds  
   - See up to two grovnicks away  
   - Win when they step onto the royal  diamond grovnik 
   - Lose if energy should ever reach zero  
   - Movement (unless using the ship on water) and clearing obstacles costs energy  
   - Use tools found to reduce energy needed to clear an obstacle 
     - If player chooses not to clear obstacle they will lose one energy and be placed on thier previous grovnik  
   - Using tool will lose that tool (or one of it)  
   - Carry as many tools as they want (ship and binoculars are limited to 1)  

- Player cannot
  - Save / Load game state
  - Create a custom map



### Additional Info
- See our [Project page](https://github.com/TaylorKNoah/frupal_g4/projects/1) of this repo to see goal/task cards used for this project
- See our [Presentation Video]() of the game!
