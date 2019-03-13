# BlondeGen

BlondGen is an automated maze generator using random motions with 5 possible actions it can perform per iteration. It works by having an active point within the maze (defined as an array) and moving this active point around the maze randomly, until it no longer can. A record of all the active points gone to is kept, and treated as the maze itself. 

  - Move up
  - Move left
  - Move down
  - Move right
  - Change active point in maze (to a random previous active point)

# included:
- All source files (.cc, .hh, .cpp, .h)
- This README
- DLLs for SFML
- Resources
- Batch file to compile (assuming SFML is installed in your C drive)

# Required
- SFML-2.4.2 or above https://www.sfml-dev.org