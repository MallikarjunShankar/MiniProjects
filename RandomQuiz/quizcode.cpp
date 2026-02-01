#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

// creating a class to represent a question
class Question {
public:
	string questionText;
	string options[4];
	int correct;

	// the parameter based constructor
	Question(string qText, string opt1, string opt2, string opt3, string opt4, int corr) { 
		questionText = qText;
		options[0] = opt1;
		options[1] = opt2;
		options[2] = opt3;
		options[3] = opt4;
		correct = corr;
	}

	// display function to first print the question then loop to print the options
	void display() { 
		cout << questionText << endl;
		for (int i = 0; i < 4; i++) {
			cout << i + 1 << ". " << options[i] << endl;
		}
	}

	// ask function to get user input and check for correctness
	bool ask() {
		int answer;
		cout << "Your answer (1-4): ";
		cin >> answer;
		return answer == correct;
	}
};

int main() {

	// defining the questions
	// as long at the parameter order is maintained, any set of questions can be inputted
	Question q1("What is the capital of France?", "Berlin", "London", "Paris", "Madrid", 3);
	Question q2("What is the largest planet in our solar system?", "Earth", "Jupiter", "Mars", "Saturn", 2);
	Question q3("Who wrote 'Romeo and Juliet'?", "Mark Twain", "Charles Dickens", "William Shakespeare", "Jane Austen", 3);
	Question q4("Who painted the Mona Lisa?", "Vincent Van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Claude Monet", 3);
	Question q5("What is the meaning of somniferous?", "Bringing sleep", "Causing excitement", "Full of energy", "Very bright", 1);
	Question q6("What is the chemical symbol for gold?", "Au", "Ag", "Fe", "Pb", 1);
	Question q7("Which of these organs is a vestigial organ in humans?", "Appendix", "Liver", "Heart", "Kidney", 1);
	Question q8("What is the hardest natural substance on Earth?", "Gold", "Iron", "Diamond", "Silver", 3);

	Question questions[] = { q1, q2, q3, q4, q5, q6, q7, q8 };
	int score = 0;
	int total = sizeof(questions) / sizeof(questions[0]);

	//shuffling the questions to ensure they appear in random order each time
	shuffle(begin(questions), end(questions), default_random_engine(time(0)));

	cout << "Begin Quiz!" << endl;

	// looping through the first 5 questions after shuffling
	for (int i = 0; i < 5; i++) {
		questions[i].display();
		if (questions[i].ask()) {
			cout << "Correct!" << endl;
			score++;
		} else {
			cout << "Wrong! The correct answer was option " << questions[i].correct << "." << endl;
		}
	}

	// displaying the final score
	cout << "Your total score: " << score << " out of " << total << "." << endl;
	cout << "Quiz Over!" << endl;
	return 0;
}
