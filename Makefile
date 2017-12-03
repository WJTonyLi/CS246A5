CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = sorcery
OBJECTS = main.o game_state.o text_view.o cli_view.o game_controller.o ascii_graphics.o player.o abstract_card.o abstract_minion_card.o base_minion_card.o spell_card.o activated_effect.o Effects/blizzard_effect.o Effects/apprentice_summoner_effect.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
