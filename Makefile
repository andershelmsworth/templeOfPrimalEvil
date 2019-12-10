
output: main.o Menu.o Game.o Die.o Character.o Barbarian.o HarryPotter.o Amulet.o FocusingLens.o InventoryObject.o JungleFloor.o LairOfTheSphinx.o MightySeal.o Queue.o Rest.o Rumble.o ShadowKey.o Space.o SubterraneanAtrium.o TempleFoyer.o TombOfTheGravediggers.o
	g++ -std=c++11 main.o Menu.o Game.o Die.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++11 -c Menu.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

Die.o: Die.cpp Die.hpp
	g++ -std=c++11 -c Die.cpp

Character.o: Character.cpp Character.hpp
	g++ -std=c++11 -c Character.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -std=c++11 -c Barbarian.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -std=c++11 -c HarryPotter.cpp

Amulet.o: Amulet.cpp Amulet.hpp
	g++ -std=c++11 -c Amulet.cpp

FocusingLens.o: FocusingLens.cpp FocusingLens.hpp
	g++ -std=c++11 -c FocusingLens.cpp

InventoryObject.o: InventoryObject.cpp InventoryObject.hpp
	g++ -std=c++11 -c InventoryObject.cpp

JungleFloor.o: JungleFloor.cpp JungleFloor.hpp
	g++ -std=c++11 -c JungleFloor.cpp

LairOfTheSphinx.o: LairOfTheSphinx.cpp LairOfTheSphinx.hpp
	g++ -std=c++11 -c LairOfTheSphinx.cpp

MightySeal.o: MightySeal.cpp MightySeal.hpp
	g++ -std=c++11 -c MightySeal.cpp

Queue.o: Queue.cpp Queue.hpp
	g++ -std=c++11 -c Queue.cpp

Rest.o: Rest.cpp Rest.hpp
	g++ -std=c++11 -c Rest.cpp

Rumble.o: Rumble.cpp Rumble.hpp
	g++ -std=c++11 -c Rumble.cpp

ShadowKey.o: ShadowKey.cpp ShadowKey.hpp
	g++ -std=c++11 -c ShadowKey.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++11 -c Space.cpp

SubterraneanAtrium.o: SubterraneanAtrium.cpp SubterraneanAtrium.hpp
	g++ -std=c++11 -c SubterraneanAtrium.cpp

TempleFoyer.o: TempleFoyer.cpp TempleFoyer.hpp
	g++ -std=c++11 -c TempleFoyer.cpp

TombOfTheGravediggers.o: TombOfTheGravediggers.cpp TombOfTheGravediggers.hpp
	g++ -std=c++11 -c TombOfTheGravediggers.cpp

clean:
	rm *.o output