# snake-and-fruit
"Snakefruit: Classic Snake Game in C++! Control the snake, eat fruits, avoid collisions. Features dynamic gameplay, score tracking, and levels. Contribute on GitHub: Snake and fruit Repo #CPlusPlus #GameDev 🐍🍇"
Snakefruit
Snakefruit is a classic Snake game implemented in C++. It features a simple yet engaging gameplay experience where players control a snake to eat fruits and grow longer, all while avoiding collisions with walls and their own tail.

How to Play
Clone the Repository: Clone the repository to your local machine using git clone.
Compile the Code: Compile the code using a C++ compiler. For example, g++ -o snakefruit snakefruit.cpp.
Run the Executable: Run the executable to start playing Snakefruit. For example, ./snakefruit.
Gameplay
Controls:
Use w for up, s for down, a for left, and d for right.
Objective:
Control the snake to eat fruits (*) and avoid collisions with walls (#) and its own tail (=).
Scoring:
Each fruit eaten increases the score, and reaching certain scores unlocks higher levels.
Levels:
Snakefruit has multiple levels, each with increased speed and difficulty.
Game Over:
The game ends if the snake collides with a wall or itself.
Functions Used
Constructor (snakefruit(int,int)): Initializes the game with specified height and width.
Draw (void draw()): Draws the game board, snake, fruit, and UI elements.
Food (void food()): Generates a new fruit and handles scoring.
Input (void input()): Handles keyboard input for controlling the snake.
Run (void run()): Executes the game logic, including snake movement and collision detection.
Contributing
Feel free to contribute to Snakefruit by forking the repository, making changes, and submitting pull requests. Your contributions are welcome and appreciated!
