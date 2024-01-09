# include <iostream>
# include <string>
# include <cstdlib> 
using namespace std;


enum hardLevelEnum { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum operationTypeEnum { Add = 1, Sub = 2, Mul = 3, Div = 4, MixO = 5 };

enum finalResultEnum { pass = 1, fail = 2 };
enum answerOfUserEnum { correct = 1, incorrect = 2 };

int randomNumber(int From, int To) {
 int num = From + rand() % (To - From + 1);
	return num;
}

string operatorString(operationTypeEnum op) {
	if (op == operationTypeEnum::Add)
		return"+";
	else if (op == operationTypeEnum::Sub)
		return "-";
	else if (op == operationTypeEnum::Mul)
		return "*";
	else if (op == operationTypeEnum::Div)
		return "/";
	else
		return "Mix";

}

string levelString(hardLevelEnum level) {
	if (level == hardLevelEnum::Easy)
		return "Easy";

	else if (level == hardLevelEnum::Med)
		return "Med";

	else if (level == hardLevelEnum::Hard)
		return "Hard";
	else

		return "Mix";

}

string finalResultString(finalResultEnum result) {
	if (result == finalResultEnum::pass)
		return "pass";
	else
		return "fail";

}

string face(finalResultEnum result) {
	if (result == finalResultEnum::pass)
		return ":-)";
	else
		return ":-(";
}

struct aGameInfo {
	hardLevelEnum hardLevel;
	operationTypeEnum operatorType;
	finalResultEnum result;
	int numberOfQuestions = 0;
	int numCorrect = 0;
	int numWrong = 0;
};

struct aQuestionInfo {
	int QuestionNumber = 0;
	int num1 = 0;
	int num2 = 0;
	int answer = 0;
	operationTypeEnum questionOperator;
	hardLevelEnum questionLevel;
	answerOfUserEnum Mark;
};


void resetScreen() {
	system("cls");
	system("color 0F");
}

void colorScreen(answerOfUserEnum answer) {

	if (answer == answerOfUserEnum::correct)
		system("color 2F");
	else
	{
		system("color 4F");
		cout << "\a";
	}



}

void showFinalResult(aGameInfo& Game) {

	if (Game.numCorrect >=( Game.numberOfQuestions / 2))
		Game.result = finalResultEnum::pass;
	else
		Game.result = finalResultEnum::fail;


	cout << "\n\n";
	cout << "----------------------------------------------------------------------------\n";
	cout << "Final Result is "<< finalResultString( Game.result )<< face(Game.result);
    cout << "\n----------------------------------------------------------------------------\n";

	cout << "Number of Questions:  "<<Game.numberOfQuestions<<endl;
	cout << "Questions Level    :  "<<levelString(Game.hardLevel)<<endl;
	cout << "OpType             :  "<< operatorString(Game.operatorType)<<endl;
	cout << "Number of right Answer:  "<<Game.numCorrect<<endl;
	cout << "Number of Wrong Answer:  "<<Game.numWrong<<endl;

	cout << "\n----------------------------------------------------------------------------\n";
}

void aQuestionResult(aGameInfo& Game, aQuestionInfo& question) {
	switch (question.questionOperator) {

	case Add:   if (question.num1 + question.num2 == question.answer) {
		question.Mark = answerOfUserEnum::correct;
		colorScreen(question.Mark);
		Game.numCorrect++;
		cout << "Right Answer :-)\n";
		cout << "\n\n";

	}          

			else {
			         question.Mark = answerOfUserEnum::incorrect;
					 colorScreen(question.Mark);
					 Game.numWrong++;
					 cout << "Wrong Answer :-( \n";
					 cout << "The correct Answer is: " <<( question.num1 + question.num2 )<< endl;

	}
		
	
			break;

//----------------------------------------------------------------------------------
	case Sub :        if (question.num1 - question.num2 == question.answer) {
		question.Mark = answerOfUserEnum::correct;
		colorScreen(question.Mark);
		Game.numCorrect++;
		cout << "Right Answer :-)\n";
		cout << "\n\n";
	}

			else {
		question.Mark = answerOfUserEnum::incorrect;
		colorScreen(question.Mark);
		Game.numWrong++;
		cout << "Wrong Answer :-( \n";
		cout << "The correct Answer is: " <<( question.num1 - question.num2) << endl;
	}
			break;

//--------------------------------------------------------------------------------------

	case Mul :        if (question.num1 * question.num2 == question.answer) {
		question.Mark =answerOfUserEnum::correct;
		colorScreen(question.Mark);
		Game.numCorrect++;
		cout << "Right Answer :-)\n";
		cout << "\n\n";
	}

			else {
		question.Mark = answerOfUserEnum::incorrect;
		colorScreen(question.Mark);
		Game.numWrong++;
		cout << "Wrong Answer :-( \n";
		cout << "The correct Answer is: " << (question.num1 * question.num2) << endl;
	}
			break;
//--------------------------------------------------------------------------------

	case Div :       if (question.num1 / question.num2 == question.answer) {
		question.Mark = answerOfUserEnum::correct;
		colorScreen(question.Mark);
		Game.numCorrect++;
		cout << "Right Answer :-)\n";
		cout << "\n\n";
	}

			else {
		question.Mark = answerOfUserEnum::incorrect;
		colorScreen(question.Mark);
		Game.numWrong++;
		cout << "Wrong Answer :-( \n";
		cout << "The correct Answer is: " << (question.num1 / question.num2) << endl;
	}
			break;
	
	}



}

void showAQuestion(aGameInfo& Game, aQuestionInfo& question) {
	cout << "Question [" << question.QuestionNumber << "/" << Game.numberOfQuestions << "]\n";

	cout << question.num1 << endl;
	cout << question.num2 <<operatorString(question.questionOperator)<< "\n";
	cout << "___________" << endl;
    cin >> question.answer;

}

void fillQuestionInfo(aGameInfo& Game, aQuestionInfo& question) {

	if (Game.hardLevel == hardLevelEnum::Mix) {
		question.questionLevel = hardLevelEnum(randomNumber(1, 3));
	}
	else
		question.questionLevel = Game.hardLevel;

	if (Game.operatorType == operationTypeEnum::MixO) {
		question.questionOperator = operationTypeEnum(randomNumber(1, 4));
	}
	else
		question.questionOperator = Game.operatorType;

	//========================

	if (question.questionLevel == 1) {
		question.num1 = randomNumber(1, 10);
		question.num2 = randomNumber(1, 10);

	}

	else if (question.questionLevel ==2) {
		question.num1 = randomNumber(10, 50);
		question.num2 = randomNumber(10, 50);
	}

	else if (question.questionLevel == 3) {

		question.num1 = randomNumber(51, 100);
		question.num2 = randomNumber(51, 100);

	}


}

void questions(aGameInfo& Game) {
	   

	for (int i = 1; i <= Game.numberOfQuestions; i++) {
		aQuestionInfo question;
		question.QuestionNumber = i;
		fillQuestionInfo(Game, question);
	    showAQuestion(Game, question);
		aQuestionResult(Game, question);
	}

	    showFinalResult(Game);
}

operationTypeEnum operationType() {
	cout << "Enter Operation Type [1] Add , [2] sub , [3] Mul , [4] Div ,[5] Mix ? ";
	int num;
	cin >> num;
	return operationTypeEnum( num);

}


hardLevelEnum hardLevel() {
	int num;
	cout << "Enter Questions Level [1] Easy, [2] Med , [3] Hard ,[4] Mix ?";
	cin >> num;
	return hardLevelEnum(num);

}

int numberOfQuestions() {
	int num;
	cout << "How Many Questions do you want to answer ? ";
	cin >> num;
	return num;
}

void start() {

	char c;
	do {
		resetScreen();
		aGameInfo Game;
	    Game.numberOfQuestions=numberOfQuestions();
		Game.hardLevel = hardLevel();
		Game.operatorType = operationType();
		questions(Game);
		

		cout << "Do you want to play again? Y/N? \n";
		cin >> c;

	} while (c == 'Y' || c == 'y');

}


int main() {

	srand((unsigned)time(NULL));
	
 	start();


}











