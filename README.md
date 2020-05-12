# StateMachine
Automatic Queuing System for ATMega328P/Arduino.

Theory of Operation:
The queue is executed from low number states to high number states. ie. State 1 has the highest priority.
Each time a state function (ie. stateOne() {};) is executed, the queue counter starts over at one and scans toward eight.

Possible Scenario's:
1. If there is only one state function in the queue, it will be executed immediately.
2. If there are two or more state functions in the queue, the lowest numbers gets executed first.
3. If there are two or more state functions in the queue and a state function is added during the execution of an existing state function. The new state function will be executed in the pre-described manner. For example: if the queue has state five and eight, it will execute five first. If while state five is being executed state two gets added to the queue, then state two will be executed as soon as state five is finished. Then, state eight will be executed (assuming no other lower states are added to the queue before it's state eight's turn).

How to use:
To add a state function to the queue, simply call 'addToQueue(stateNumber)'. This can be done at anytime, include (and especially) during Interrupt Service Routines. If there is a situation where you no longer want the state function to be executed, call 'removeFromQueue(stateNumber)'.

The state functions (stateOne(), stateTwo(), etc.) are weakly linked to the library so if you don't need/want to use all eight states, just delete the unneeded state functions with no compliler consequences.
