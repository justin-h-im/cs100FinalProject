
// class responsible for keeping track of the game's status
// this includes keeping track of which player's turn it is along with if a player has won based on king HP
class Game {
	private:
		bool check;
		color turn;
		Piece* whiteKing;
		Piece* blackKing;
	public:
		Game();
		Color getTurn();
		bool isInCheck();
		bool whiteWin();
		bool blackWin();
};