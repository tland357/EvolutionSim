# EvolutionSim
A Simple Evolution Simulator for Windows
This Project is an experiment for exploring how evolution and natural selection work on abstract creatures.


CREATURE TYPES:
Currently it features three types of abstract creatures.
The first two creatures are called function snakes.
These snakes are born with a random constant value and a list of mathematical functions. 
Every snake starts with a value of 1 and iterates this value through the list of functions
in order until they have run out of functions. This outputs a new value which represents
this creature's score. In the first type of creature, they perform based on raw score;
however, with the efficiency based function snakes, having many functions is punished. 
Creatures should strive to earn the highest score in the least amount of function calls.
The third type of creature is called a Sudoku Creature. This creature is a randomly
generated sudoku board; however, this board may not follow the restrictions of sudoku
from the start. Sudoku creatures are made up of rows, columns, and 3x3 subregions on a
grid, and each of these areas of the board must contain all numbers from 1 to 9. If a
row, column, or sub-region contains all 9 numerals, then the creatures score goes up by 1. 
Be sure to play around with the evolution settings to find which scenarios work best 
for each creature!

HOW TO USE:
1. Open the releases tab and download the most recent verified release.

2. Open the executable file ES.exe

3. Select a creature type. This is seen in radio button group at the top left of the window.

4. Change the input settings:

    Mutation Rate: The probability that a certain mutation will occur when a creature is reproduced
        bounded between 0 and 1.
    Forgiveness: The degree to which poor performances are punished. At a value of 1, good performing
        creatures are just as likely to reproduce as bad performing ones. At a value of 0, a creature
        in the bottom half of a population is extremely likely to die to natural selection in the next
        iteration.
    Capacity: How many members a population can hold. This is limited to values between 10 and 9,999.
    Seed: A Number which generates all random evolution events. Two simulations with the same seed will
      start with the same population.
      
5. Generate a population. You can either generate a single one, or type a value for how many
    generations to skip through.
    
6. Observe results. The Best, Worst, and Median performers are recorded and displayed. Clicking
    on any of these three will display it's details in depth. To display the results of any specific 
    creature during a certain generation, either type a value in the creature observer box between 0 
    and the Capacity you've entered minus 1, or drag the sliding vertical bar up and down. Note that 
    creatures have been sorted based on performance with the best performers at the top. If a creature 
    displays a "Perfect Score!!!" this indicates that they've reached the maximum possible value and 
    any increase in performance will result in a drastic decrease in their overall score due to the 
    way computers process integers.
    
7. Continue the simulation or change the settings. Any alteration to a setting (other than the
    value for running multiple generations) will result in the simulation starting over. A given
    simulation with the same settings and seed value will always result in the same simulation so you
    can go back and observe a simulation again.
