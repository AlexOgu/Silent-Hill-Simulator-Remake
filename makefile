CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

OBJS = Game.o Area.o Hero.o Enemy.o Creeper.o Mandarin.o Mannequin.o Weapon.o Plank.o Shotgun.o Chainsaw.o run.o
EXEC = run

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

Game.o: Game.cpp Game.h Area.h Hero.h Enemy.h Creeper.h Mandarin.h Mannequin.h Weapon.h Plank.h Chainsaw.h Shotgun.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

Area.o: Area.cpp Area.h
	$(CXX) $(CXXFLAGS) -c Area.cpp

Hero.o: Hero.cpp Hero.h Weapon.h Plank.h Shotgun.h Chainsaw.h
	$(CXX) $(CXXFLAGS) -c Hero.cpp

Enemy.o: Enemy.cpp Enemy.h
	$(CXX) $(CXXFLAGS) -c Enemy.cpp

Creeper.o: Creeper.cpp Creeper.h Enemy.h
	$(CXX) $(CXXFLAGS) -c Creeper.cpp

Mandarin.o: Mandarin.cpp Mandarin.h Enemy.h
	$(CXX) $(CXXFLAGS) -c Mandarin.cpp

Mannequin.o: Mannequin.cpp Mannequin.h Enemy.h
	$(CXX) $(CXXFLAGS) -c Mannequin.cpp

Weapon.o: Weapon.cpp Weapon.h
	$(CXX) $(CXXFLAGS) -c Weapon.cpp

Plank.o: Plank.cpp Plank.h Weapon.h
	$(CXX) $(CXXFLAGS) -c Plank.cpp

Shotgun.o: Shotgun.cpp Shotgun.h Weapon.h
	$(CXX) $(CXXFLAGS) -c Shotgun.cpp

Chainsaw.o: Chainsaw.cpp Chainsaw.h Weapon.h
	$(CXX) $(CXXFLAGS) -c Chainsaw.cpp

run.o: run.cpp Game.h
	$(CXX) $(CXXFLAGS) -c run.cpp

clean:
	rm -f $(OBJS) $(EXEC)

cleanobj:
	rm -f $(OBJS)
