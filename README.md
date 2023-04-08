# Factory system and analysis
Module 2 open-ended project, by John Driscoll

### Program Summary <hr />

My program attempt to model the costs of running a factory. The project
contains a basic generic Factory, alongside two specialized subclasses:
CarFactory and ChipFactory, each with their own unique expenses. The
TESTING configuration verifies the functionality of the various Factory
classes, along with another Employee class of which many are contained in a 
Factory object. The main method gathers this information via file or user input, along with revenues,
and sees whether the operation is profitable. 

**Module 2 Features:**
* Inheritance class relationship: CarFactory and ChipFactory are Factory
subclasses.
* Component class relationship: the Employee class is contained in a vector
within the Factory class or one of its subclasses.
* File input: the MAIN configuration uses text file data or user input to determine if a
Factory subclass object is profitable or not.

**In the future,** I'd like to add additional types of Factories and Employees
to better model the real-world operation of a particular factory. This
would allow my analysis to be more dynamic and accurate.

**I think I've earned** at least 100 points from this project. The main program involves the Factory
classes and their associated component and inheritance relationships, and the analysis scheme
makes contextual sense; the testing program is robust with many test cases for all four classes;
the component and inheritance relationships are integrated well and make sense; file input functions
and makes sense. Further, documentation is complete, and the lifespan of the project spans seven days.

**I'm citing** StackOverflow for providing me with a method to convert the choice of chip or car
factory to lowercase. This avoids me needing to check for countless different cases.

There are **no known bugs** at time of submission, apart from the car/chip validation not accounting
for whitespaces.
