#include <stdexcept>
#include <string>

using namespace std;

struct Result {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {
	}

	bool isDuplicatedNumber(string guessNumber) {
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

	bool isIncludeChar(const string& guessNumber) {
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			return true;
		}
		return false;
	}

	void assertIllegalArgument(string guessNumber) {
		if (guessNumber == "") {
			throw std::invalid_argument("값을 넣어야함");
		}
		if (guessNumber.length() != 3) {
			throw std::invalid_argument("자리수 오류");
		}
		if (isIncludeChar(guessNumber)) {
			throw std::invalid_argument("숫자로만 구성되어 있지 않음");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw std::invalid_argument("중복수 금지");
		}
	}

	bool checkSolved(int strikes)
	{
		if (strikes == 3)
			return true;
		return false;
	}

	void checkStrikesandballs(string guessNumber, int& strikes, int& balls)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				if (guessNumber[i] == question[j])
				{
					if (j == i)
						strikes++;
					else
						balls++;
				}
			}
		}
	}

	Result guess(string guessNumber) {
		assertIllegalArgument(guessNumber);

		if (guessNumber == question) {
			return { true, 3, 0 };
		}
		bool solved = false;
		int strikes = 0;
		int balls = 0;
		checkStrikesandballs(guessNumber, strikes, balls);

		solved = checkSolved(strikes);

		return { solved, strikes, balls };

	}

private:
	string question;
};
