# Randomized Quiz

This documentation was created for the file [quizcode.cpp](https://github.com/MallikarjunShankar/MiniProjects/RandomQuiz/quizcode.cpp)

---

## Flow of the Program

The program begins by defining a `Question` class. This class is used to represent a single multiple-choice question and contains:

- A string for the question text  
- An array of four strings for the options  
- An integer indicating the correct option (1–4)

The class includes:
- A parameterized constructor to initialize all question data  
- A `display()` function to print the question and its options  
- An `ask()` function to take user input and check whether the answer is correct  

---

## Flow of Code

1. **Question Definition**  
   Inside `main()`, individual questions are created as objects of the `Question` class.  
   Each question must follow the constructor format:

Question(questionText, option1, option2, option3, option4, correctOption)

As long as this order is maintained, any number of questions can be defined.

2. **Storing Questions**  
All question objects are stored in an array of type `Question`.  
The array length determines how many total questions exist in the quiz.

3. **Randomization**  
The `shuffle()` function from the `<algorithm>` library is used to randomize the order of questions.  
A time-based seed ensures a different order each time the program runs.

4. **Quiz Execution**  
A `for` loop iterates through the first `m` questions in the shuffled array.  
For each question:
- The question and options are displayed  
- The user enters an answer  
- The program checks correctness and updates the score  

5. **Result Display**  
After the loop completes, the final score is printed along with a completion message.

---

## Changing the Questions

To modify or add questions:

- Create new `Question` objects using the same constructor format
- Add or remove them from the `questions[]` array
- Ensure the correct option number matches the intended answer (1–4)

Example:

Question q9("Sample question?", "A", "B", "C", "D", 2);

---

## Changing the Number of Questions in the Quiz

There are two places that control quiz length:

1. **Total Available Questions**  
   Controlled by how many `Question` objects are placed in the `questions[]` array.

2. **Number of Questions Asked**  
   Controlled by the loop condition:

---

Mallikarjun Shankar
