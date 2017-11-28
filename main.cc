#include <iostream>
#include <memory>
#include "game_state.h"
#include "game_controller.h"
#include "text_view.h"

using namespace std;

int main()
{
    //this is just code to test my stuff, ignore this for now
    shared_ptr<GameState> gs(new GameState());
    shared_ptr<GameController> gc(new GameController(gs));
    shared_ptr<TextView> tv(new TextView(cin, cout, gs));
    tv->attach(gc);
    tv->test();
    return 0;
}
