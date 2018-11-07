Alright so your problem here is that you are having to instantiate a new db object for each command.
That isn't acceptable.
So solution 1 you throw out GUI and just do everything in .cpp
Option 2 is you find out how to pass the AdvisingDBAbstraction object and create it once in main then just pass it to everything that needs it.