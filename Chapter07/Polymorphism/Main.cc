#include <iostream>
#include <string>
#include <vector>

#include "Agent.h"

void printAllAgents(const std::vector<Agent *> &agents)
{
    for (const auto agent : agents)
    {
        agent->print_agent_data();
    }
}

int main()
{
    Agent agent1("A1", 0, 100, 25);
    Player player1("P1", 1, 250, 55);
    NPC npc1("N1", 2, 235, 41);

    Agent a2 = npc1;
    a2.print_agent_data();
    const auto agents = std::vector<Agent *>{&agent1, &player1, &npc1, &a2};
    // std::cout << "--------" << std::endl;
    // printAllAgents(agents);

    return 0;
}
