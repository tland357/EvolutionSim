# EvolutionSim
A Simple Evolution Simulator for Windows
This Project is an experiment for exploring how evolution and natural selection work.

CREATURE TYPES:
Currently it features two types of abstract creatures.
In the application they are both refered to as Function Snakes.
These snakes are born with a random constant value and a list of mathematical functions. 
Every snake starts with a value of 1 and iterates this value through the list of functions
in order until they have run out of functions. This outputs a new value which represents
this creature's score. In the first type of creature, they perform based on raw score;
however, with the efficiency based function snakes, having many functions is punished. 
Creatures should strive to earn the highest score in the least amount of function calls.

HOW TO USE:

Step 1. Select a creature type. This is seen in radio button group at the top left of the window.

Step 2. Input settings
    Mutation Rate: The probability that a certain mutation will occur when a creature is reproduced
        bounded between 0 and 1.
    Forgiveness: The degree to which poor performances are punished. At a value of 1, good performing
        creatures are just as likely to reproduce as bad performing ones. At a value of 0, a creature
        in the bottom half of a population is extremely likely to die to natural selection in the next
        iteration.
    Capacity: How many members a population can hold. This is limited to values between 10 and 9,999.
    Seed: A Number which generates all random evolution events. Two simulations with the same seed will
      start with the same population.
      
Step 3. Generate a population. You can either generate a single one, or type a value for how many
    generations to skip through.
    
Step 4. Observe results. The Best, Worst, and Median performers are recorded and displayed. Clicking
    on any of these three will display it's details in depth. To display the results of any specific 
    creature during a certain generation, either type a value in the creature observer box between 0 
    and the Capacity you've entered minus 1, or drag the sliding vertical bar up and down. Note that 
    creatures have been sorted based on performance with the best performers at the top. If a creature 
    displays a "Perfect Score!!!" this indicates that they've reached the maximum possible value and 
    any increase in performance will result in a drastic decrease in their overall score due to the 
    way computers process integers.
    
Step 5. Continue the simulation or change the settings. Any alteration to a setting (other than the
    value for running multiple generations) will result in the simulation starting over. A given
    simulation with the same settings and seed value will always result in the same simulation so you
    can go back and observe a simulation again.
