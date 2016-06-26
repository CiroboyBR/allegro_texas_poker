class Timer {
  public:
    Timer(std::string timerName)::timerName(timerName) {
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &starttime);
    }
    ~Timer() {
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stoptime);
      std::printf("%s: %d\n", timerName.c_str(), stoptime.tv_nsec - starttime.tv_nsec);
    }
  private:
    std::string timerName;
    timespec starttime, stoptime;
};

int main() {
  Timer timer("Total time");
  PokerGames headsUpGames("poker.txt");
  int playerOneWins = 0;
  for(int i = 0; i < headsUpGames.nrOfGames; i++) {
    PokerGame game = headsUpGames.GetGame(i);
    playerOneWins += (calculate_handvalue(game.playerHand[0]) > calculate_handvalue(game.playerHand[1]));
  }

  std::printf("Player 1 wins: %d\n", playerOneWins);
  return 0;
}
